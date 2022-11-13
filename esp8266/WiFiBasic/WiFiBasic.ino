#include <ESP8266WiFi.h>
#include <Arduino.h>

#ifndef STASSID
#define STASSID "UPC1625583"
#define STAPSK "DQJRFCNJ"
#endif

void setup()
{

        Serial.begin(115200);
        int status;
        Serial.flush();


        Serial.print("Trying connect to ");
        Serial.println(STASSID);

        // attempt to connect to Wifi network:
        status = WiFi.begin(STASSID, STAPSK);
        status = WiFi.waitForConnectResult();
        if (status != WL_CONNECTED)
        {
            Serial.println("Connection Failed");
            while (true) {}
        }

        Serial.println("Connected.");
        Serial.print("MAC: ");
        Serial.println(WiFi.macAddress());
        Serial.print("IP:  ");
        Serial.println(WiFi.localIP());
        Serial.print("Subnet: ");
        Serial.println(WiFi.subnetMask());
        Serial.print("Gateway; ");
        Serial.println(WiFi.gatewayIP());
        Serial.print("DNS: ");
        Serial.println(WiFi.dnsIP());
        Serial.print("Channel: ");
        Serial.println(WiFi.channel());
        Serial.print("Status: ");
        Serial.println(WiFi.status());
}

void loop()
{
    Serial.printf("In Loop...\n");
    delay(2500);
}
