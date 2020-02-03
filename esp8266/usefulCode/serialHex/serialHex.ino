#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

#define READWRITE 2
#define DATAPIN D2

char dataRead;
const static uint8_t colorLength = 6;  // We use hexcolors.
const static uint8_t ledCount = 30;
const static uint8_t commandLength = colorLength * ledCount;
// const static uint8_t refreshPeriod = 150;  // Milliseconds
static char command[commandLength];

Adafruit_NeoPixel strip(ledCount, READWRITE, NEO_GRB + NEO_KHZ800);


uint8_t toDecimal(char val) {

    /*
    Converts a hex char to decimal value.
    */
    return (val >= 65) ? val - 55 : val - 48;
}


void flash() {

    /*
        Convenient function to be able to tell if any suitable data is recieved without occupying the serial comm.
    */
    digitalWrite(READWRITE, LOW);
    delay(20);
    digitalWrite(READWRITE, HIGH);
    delay(20);
}


void listen() {

    if(Serial.available() > 0)
    {
        dataRead = Serial.peek();  // Here we check if the read char is #. If it is that means it is our entry point.
        if (dataRead == '#')
        {
            Serial.read();
            parseData();
            // At this point the "command" variable is modified so we are able to do what we want with the command.
            updateStrip();
            Serial.flush();
        }

    }

}


void parseData() {

    /*
        This function modifies the global "command" variable.
    */
    flash();
    int counter = 0;
    while (Serial.available() > 0)
    {
        dataRead = Serial.read();
        delay(1);
        command[counter] = dataRead;
        counter++;
    }
    Serial.flush();
}

void updateStrip() {

    /*
        As the parseData function this function also uses the global command variable.
    */
    uint8_t r, g, b;
    for (uint8_t n = 0; n < ledCount; n++)
    {
        r = toDecimal(command[n*colorLength + 0])*16 + toDecimal(command[n*colorLength + 1]);
        g = toDecimal(command[n*colorLength + 2])*16 + toDecimal(command[n*colorLength + 3]);
        b = toDecimal(command[n*colorLength + 4])*16 + toDecimal(command[n*colorLength + 5]);
        strip.setPixelColor(n, r, g, b);
        Serial.printf("%d, %d, %d", r, g, b);
    }
    strip.show();
}

void setup() {

    // Setup serial comm.
    Serial.begin(115200);
    pinMode(READWRITE, OUTPUT);

    // Setup the led strip.
    strip.begin();
    strip.setBrightness(255);

}

void loop() {
    
    listen();

}