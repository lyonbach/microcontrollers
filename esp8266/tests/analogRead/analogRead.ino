#include "Arduino.h"
#include "math.h"

#define DATAPIN D2
#define PRECISION 3

bool readReady = false;
uint_fast16_t lastRead = 0;  // ms
uint_fast16_t readDelay = 25;  // ms

int currentVal = 0;

void checkReadAvailable()
{
    /*
    Checks elapsed time and modifies the read flag.
    */
   readReady = (millis() - lastRead > readReady) ? true : false;
}

void setup()
{

Serial.begin(115200);
Serial.println();
Serial.println("Hello!");

// Pin setup
pinMode(DATAPIN, INPUT);

}

void loop()
{
    checkReadAvailable();
    if(readReady)
    {

        int testVal = analogRead(DATAPIN);
        if (abs(currentVal - testVal) > PRECISION)
        {
            Serial.print("Current Reading: ");
            currentVal = testVal;
            currentVal = (currentVal > 1024 - PRECISION) ? 1024 : currentVal;
            currentVal = (currentVal < PRECISION) ? 0 : currentVal;
            Serial.println(currentVal);
        }
    }
}