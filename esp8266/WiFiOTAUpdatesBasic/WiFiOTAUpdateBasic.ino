#include "ESP8266WiFi.h"

void setup()
{
    Serial.begin(115200);
    delay(500);
    Serial.println('\n');

    uint32_t avail =  ESP.getFreeSketchSpace();
    Serial.println(avail);
}

void loop()
{

}
// 1830912