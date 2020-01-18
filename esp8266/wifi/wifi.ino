#include <ESP8266WiFi.h>
#include <GDBStub.h>

#define BAUDRATE 115200

void setup()
{
    Serial.begin(BAUDRATE);
    gdbstub_init();
    Serial.println();

    WiFi.begin("UPC1625583", "DQJRFCNJ");
    Serial.print("Connecting");
     while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    int networksFound = WiFi.scanNetworks();
    delay(1000);
    for (int i = 0; i < networksFound; i++)
    {
        Serial.println(WiFi.SSID(i));
        Serial.println(WiFi.RSSI(i));
    }
    delay(2000);
    Serial.println("Diagnostics:");
    WiFi.printDiag(Serial);
}