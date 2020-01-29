#include <ESP8266WiFi.h>

void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.print("Setting soft-AP ... ");
    boolean result = (WiFi.softAP("ESPsoftAP", "2062")) ? "Ready" : "Failed!";
}

void loop()
{
    Serial.printf("Connected = %d\n", WiFi.softAPgetStationNum());
    delay(3000);
}