#include "Arduino.h"

void resetAll(int* leds)
{
    Serial.println("[HELPERS]: All pins were reset!");
    analogWrite(leds[0], 0);
    analogWrite(leds[1], 0);
    analogWrite(leds[2], 0);
}