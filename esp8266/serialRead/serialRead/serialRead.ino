/*  This is a test for controlling my brother's Philips Ambilight like project.
    We use nodemcu kit 12E with esp8266 to control the led lights.
    This is one of the basic test files to get familiar with Arduino interface.
    The actual application may also use python to communicate with serial port
    if desired read/write speed is achieved.
    Bahadir Arslan arslan.bah@gmail.com

// Pin numbers are translated as below:
    |=======|======|============|
    | PIN   | NAME | DEFINITION |
    |=======|======|============|
    | GPIO4 | (D2) | REDPIN     |
    | GPIO0 | (D3) | GREENPIN   |
    | GPIO2 | (D4) | BLUEPIN    |
    |===========================|
*/
// Imports
#include <Arduino.h>
#include "helpers.h"

// Definitions
#define BAUDRATE 115200
#define LED_COLOR_STATE 0

#define REDPIN 4
#define GREENPIN 0
#define BLUEPIN 2

int leds[] = {REDPIN, GREENPIN, BLUEPIN};
int incomingByte = 0;
int red = 0;
int green = 0;
int blue = 0;
struct RGBColor
    {
        int red, green, blue;

    RGBColor(int r, int g, int b)
    {
        this->red = r;
        this->green = g;
        this->blue = b;
    }
};

void switchColor( RGBColor& color )
{
    Serial.println("Switching");
    Serial.printf("[RED  ]: %d \n", color.red);
    Serial.printf("[GREEN]: %d \n", color.green);
    Serial.printf("[BLUE ]: %d \n", color.blue);

    analogWrite(leds[0], color.red);
    analogWrite(leds[1], color.green);
    analogWrite(leds[2], color.blue);
}


void setup ()
{
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    Serial.begin(BAUDRATE);
    Serial.println("[ESP8266] Listening...");
    resetAll(leds);

}


void loop ()
{
    incomingByte = Serial.read();
    if(incomingByte > 0)
    {
        if(incomingByte == 82 || incomingByte == 114)
        {
            RGBColor targetColor (999, 0, 0);
            switchColor(targetColor);
        }
        else if(incomingByte == 71 || incomingByte == 103)
        {
            RGBColor targetColor (0, 999, 0);
            switchColor(targetColor);
        }
        else if(incomingByte == 66 || incomingByte == 98)
        {
            RGBColor targetColor (0, 0, 999);
            switchColor(targetColor);
        }
        else if(incomingByte == 87 || incomingByte == 119)
        {
            RGBColor targetColor (999, 999, 999);
            switchColor(targetColor);
        }
        else if(incomingByte == 79 || incomingByte == 111)
        {
            resetAll(leds);
        }
    }
        
}
