#include "ESP8266WiFi.h"

#define SITE "api.github.com"
#define SHA1 "59 74 61 88 13 CA 12 34 15 4D 11 0A C1 7F E6 67 07 69 42 F5"
#define LOCAL_AREA_CONNECTION_TIMEOUT 5000
#define WDR while(true){}  // Causes watchdog to reset.

const char* host = SITE;
const uint16_t httpsPort = 443;
const char fingerprint[] PROGMEM = SHA1;


const char* ssid = "UPC1625583";
const char* password = "DQJRFCNJ";

uint8_t connectToLocalNetwork()
{
    uint16_t ti = millis();
    Serial.printf("\nConnecting to %s ", ssid);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(125);
        Serial.print(".");
    }
    if (millis() - ti >= LOCAL_AREA_CONNECTION_TIMEOUT)
    {
        Serial.println();
        return 0;
    }

    Serial.printf("Connected to %s. \n", ssid);
    return 1;
}

uint8_t secureConnectToSite(WiFiClientSecure *client, const char* host, const uint16_t port, const char* fingerprint) {
    

    /*
        Connects to the given address using the fingerprint.
        If successful returns 1
        There are two return values for unsuccessful connection.
        returns -2 if fingerprint does not match.
        returns -1 if connection was unsuccessful.
    */
    
    Serial.print("Connecting to ");
    Serial.println(host);

    Serial.printf("Using fingerprint '%s'\n", fingerprint);
    client->setFingerprint(fingerprint);
    if (!client->connect(host, httpsPort))
    {
        return -1;
    }
    
    if (!client->verify(fingerprint, host)) {
        return -2;
    }
    return 1;
}


String getGetRequest(const char* url, const char* host)
{
    String requestBody("GET ");
    requestBody += url;
    requestBody += " HTTP/1.1\r\n";
    requestBody += "Host ";
    requestBody += host;
    requestBody += "\r\n";
    requestBody += "User-Agent: BuildFailureDetectorESP8266\r\n";
    requestBody += "Connection: close\r\n\r\n";
    return requestBody;
}


void setup() {

    Serial.begin(115200);
    Serial.println();

    if (!connectToLocalNetwork())
    {
        WDR;
    }

    // Connect to site.
    WiFiClientSecure client;
    uint8_t result = secureConnectToSite(&client, host, httpsPort, fingerprint); 
    if(result)
    {
        Serial.println("Connection successful.");
    } else if (result == -2)
    {
        Serial.println("Certificate doesn't match.");
        WDR;
    } else
    {
        Serial.println("Connection failed");
        WDR;
    }

    // Make a request here.
    const char* url = "/repos/esp8266/Arduino/commits/master/status";
    // const char* url = "";
    Serial.println("Requesting URL: ");
    String request = getGetRequest(url, host);
    Serial.println(request);
    doGetRequest(request, &client);
}

void doGetRequest(String request, WiFiClientSecure* client) {

    while(client->connected())
    {
        String responseLine = client->readStringUntil('\n');  // Read chars until line break.
        if(responseLine == "\r")
        {
            Serial.println("Headers recieved...");
        }
        responseLine = client->readStringUntil('\n');
        Serial.println(responseLine);
        if (responseLine.startsWith("{\"state\":\"success\"")) {
        Serial.println("esp8266/Arduino CI successfull!");
        } else {
            Serial.println("esp8266/Arduino CI has failed");
        }
        Serial.println("reply was:");
        Serial.println("==========");
        Serial.println(responseLine);
        Serial.println("==========");
        Serial.println("closing connection");
    }
}

void loop(){

}