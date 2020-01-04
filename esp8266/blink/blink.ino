
// ESP8266 RGB TEST
// Pin numbers are translated as below:
// | PIN   | NAME | DEFINITION |
// |=======|======|============|
// | GPIO4 | (D2) | REDPIN     |
// | GPIO0 | (D3) | GREENPIN   |
// | GPIO2 | (D4) | BLUEPIN    |
// |===========================|

#include <iostream>
#include "Arduino.h"

#define REDPIN 4
#define GREENPIN 0
#define BLUEPIN 2

int leds[] = {REDPIN, GREENPIN, BLUEPIN};
int counter = 0;
int limit = 25;

void resetAll()
    {
        analogWrite(leds[0], 0);
        analogWrite(leds[1], 0);
        analogWrite(leds[2], 0);
    }

void flashRGB()
{
// Flash five times for each color r -> g -> b for three seconds.
    for (int num_p=0; num_p < 3; num_p++)
    {
        analogWrite(leds[num_p], 1000);
        delay(60);
        analogWrite(leds[num_p], 0);
        delay(25);
    }
}

void gradualRGB(float strenghtCoeff)
{
    // Init each of the colors to 0 strenght.
    resetAll();
    // Gradually change from red -> green -> blue.
    for (int num_p = 0; num_p < 3; num_p++)
    {

        if (num_p == 0)
        {
            Serial.println("REDPIN");
        }
        else if (num_p == 1)
        {
            Serial.println("GREENPIN");
        }
        else if (num_p == 2)
        {
            Serial.println("BLUEPIN");
        }

        for (int strength = 0; strength < 1000; strength++)
        {
            analogWrite(leds[num_p], strength * strenghtCoeff);
            delay(5);
        }
        resetAll();
    }
}

void setup() {
// Setup everyone as ouput.
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    for(int i = 0; i < 3; i++)
        {
            float ranCoeff = (float)std::rand()/RAND_MAX;
            Serial.println(ranCoeff);
            gradualRGB(ranCoeff);
        }
    for(int i = 0; i < 300; i++)
        flashRGB();
}
