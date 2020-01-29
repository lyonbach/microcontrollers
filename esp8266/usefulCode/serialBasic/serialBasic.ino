#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

#define COMMAND_CHAR_COUNT 270
#define DATA_CHUNKSIZE 135
#define COMMANDSTART '<'
#define COMMANDEND '>'
#define LED_COUNT 30
#define DATA_PIN 2

const int commandCharCount = COMMAND_CHAR_COUNT;
char command[commandCharCount];
int charCounter = 0;  // Indicates that the command is completed.
bool receivingState = false;
int ledCount = LED_COUNT;
const int static dataPin = DATA_PIN;
unsigned int r = 0;
unsigned int g = 0;
unsigned int b = 0;

Adafruit_NeoPixel strip(ledCount, dataPin, NEO_GRB + NEO_KHZ800);

void parseCommand()
{

    // Serial.println(command);
    for (int n = 0; n < 30; n++)  // For each LED in our case we have 30.
    {
        r = 0;
        g = 0;
        b = 0;
        for (int i = 0; i < 3; i++)
        {
            int dec = pow(10, 2-i);
            // Define colors.
            r += (command[(n * 9 + i + 0)] - 48) * dec;
            g += (command[(n * 9 + i + 3)] - 48) * dec;
            b += (command[(n * 9 + i + 6)] - 48) * dec;
        }
        Serial.printf("LED %d\n", n);
        Serial.printf("red: %d green: %d blue: %d\n", r, g, b);
        strip.setPixelColor(n, r, g, b);
        delay(5);
    }
    strip.show();
    Serial.flush();
    // Serial.write("over");
    charCounter = 0;

}

void listen()
{
    while(Serial.available() > 0)
    {
        char currentChar = Serial.read();
        if(currentChar == '<')
            receivingState = true;

        if(charCounter < commandCharCount)
        {
            if(receivingState && isdigit(currentChar))
            {
                command[charCounter] = currentChar;
                charCounter++;
            }
        }

        else if(charCounter >= commandCharCount || currentChar == '>')
        {
            receivingState = false;
            parseCommand();
        }
    }
}

void setup()
{
    Serial.begin(115200);
    Serial.println("<ESP is ready>");
    for(int i = 1; i < COMMAND_CHAR_COUNT; i++)
    {
        command[i] = '#';
    }
    strip.begin();
    strip.setBrightness(255);
}


void loop() 
{
    listen();
}
