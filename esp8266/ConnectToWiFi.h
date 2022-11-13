#include "ESP8266WiFi.h"

#define WDR while(true) // Watch Dog Reset
#define STASSID "UPC1625583"
#define STAPSK "DQJRFCNJ"
#define BAUD 115200

char* ssid = STASSID;
char* pass = STAPSK;

void Connect() {
    
    int status = WiFi.begin(ssid, pass);
    status = WiFi.waitForConnectResult();
    if ( status != WL_CONNECTED )
    {
        Serial.println("Couldn't get a wifi connection");
        WDR;
    }
    Serial.printf("Connected to %s.\n", ssid);
}
