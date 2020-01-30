/*
    What we need to do:
Use client secure to connect to https://api.github.com,
to GET /repos/esp8266/Arduino/commits/master/status,
search for the line "state": "success" and display “Build Successful” if we find it,
or “Build Failed” if otherwise.
*/

/*
    To establish a secure connection with a server we need to verify server’s identity.
Clients that run on “regular” computers do it by comparing server’s certificate with locally stored list of trusted root
 certificates. Such certificates take several hundreds of KB, so it is not a good option for an ESP module.
 As an alternative we can use much smaller SHA1 fingerprint of specific certificate.
*/

#include "ESP8266WiFi.h"

// const char* host = "api.github.com";
// const char* host = "www.example.com";
const char* host = "www.youtube.com";
const uint8_t httpsPort = 80;
const char* fingerprint = "59 74 61 88 13 CA 12 34 15 4D 11 0A C1 7F E6 67 07 69 42 F5";


const char* ssid = "UPC1625583";
const char* password = "DQJRFCNJ";


void connectToLocalNetwork()
{

    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println(" connected.");
}

WiFiClient connectToClient(const char* host, const uint8_t httpsPort){
    
    WiFiClient client;
    Serial.print("Connecting to ");
    Serial.println(host);

    if (!client.connect(host, httpsPort)) {
        Serial.println("ERROR! Connection failed!");
    }
    Serial.println("Connection successful!");
    return client;
}

void setup() {
    
    Serial.begin(115200);
    Serial.println();

    connectToLocalNetwork();
    WiFiClient client = connectToClient(host, httpsPort);
    String request;
    request += String("Get /results?search_query=cheese");
    request += " HTTP/1.1\r\n";
    request += "Host: ";
    request.concat(host);
    request += "\r\n";
    request += "Connection: close\r\n\r\n";

    // GET /results?search_query=cheese HTTP/1.1
    // Host: www.youtube.com
    client.print(request);
    // client.print(String("GET /results?search_query=cheese") + " HTTP/1.1\r\n" +
                // "Host: " + host + "\r\n" +
                // "Connection: close\r\n" +
                // "\r\n"
            // );
    Serial.println("[Response:]");
    while (client.connected() || client.available())
    {
        if (client.available())
        {
            String line = client.readStringUntil('\n');
            Serial.println(line);
        }
    }
    client.stop();
    Serial.println("\n[Disconnected]");
}

void loop() {

}