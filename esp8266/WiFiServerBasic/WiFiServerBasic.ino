#include <ESP8266WiFi.h>

#define WDR while(true) // Watch Dog Reset
#define BAUD 115200
#ifndef STASSID
#define STASSID "UPC1625583"
#define STAPSK "DQJRFCNJ"
#endif

char ssid[] = STASSID;          //  your network SSID (name)
char pass[] = STAPSK;           // your network password
int status = WL_IDLE_STATUS;

WiFiServer server(80);

String prepareHtmlPage() {
  String htmlPage = String("HTTP/1.1 200 OK\r\n") +
                           "Content-Type: text/html\r\n" +
                           "Connection: close\r\n" +  // the connection will be closed after completion of the response
                           "Refresh: 5\r\n" +  // refresh the page automatically every 5 sec
                           "\r\n" +
                           "<!DOCTYPE html><html><head><style>.button {background-color: rgb(170, 22, 150);border: none;color: white;padding: 15px 25px;text-align: center;font-size: 16px;cursor: pointer;}.button:hover {background-color: rgb(0, 128, 122);}</style></head><body><h2>CSS Button</h2><button>Default Button</button><br><button class=\"button\">Styled Button</button></body></html>" +
                           "\r\n";
  return htmlPage;
}

void setup() {
    // initialize serial:
    Serial.begin(BAUD);
    Serial.println("Attempting to connect to WPA network...");
    Serial.print("SSID: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);
    status = WiFi.waitForConnectResult();
    if ( status != WL_CONNECTED )
    {
        Serial.println("Couldn't get a wifi connection");
        WDR;
    }

    server.begin();
    
    Serial.print("Connected to wifi. My address:");
    IPAddress myAddress = WiFi.localIP();
    Serial.println(myAddress);
}

void loop() {

    WiFiClient client = server.available();  // We got request.
    if (client)
    {
        while (client.connected())
        {
            if (client.available())
            {
                String line = client.readStringUntil('\r');  // We try to find the request.
                Serial.print(line);
                if (line.length() == 1 && line[0] == '\n')
                {
                    Serial.println("Sending the page...");
                    // Here we create the page and serve.
                    String page = prepareHtmlPage();
                    // Serving the client here.
                    client.println(page);
                    break;
                }
            }
        }
    }
    // delay(1);
    // client.stop();
    // Serial.println((server.hasClient()) ? "Some is connected!": "No clients so far.");

}
