
#include "Arduino.h"
#include "LCD.h"

// Pins are defined in LCD.h!
#define BAUDRATE 115200

int incomingByte;

void sendCommandsFromSerialInput()
{
    // Listens the serial port for any commands and calls the necessary functions.
    incomingByte = Serial.read();
    if(incomingByte > 0)
    {
        Serial.printf("NOT IMPLEMENTED!!!\n");
    }

}

void setup()
{
    // In this function we set all of the pins as output.
    // And also initialize the serial connection.

    // Serial.begin(BAUDRATE);
    // Serial.flush();
    // Serial.println();
    // Serial.println("[ESP8266] Listening...");

    pinMode(REGSELECT, OUTPUT);
    // pinMode(READWRITE, OUTPUT);
    pinMode(ENABLE   , OUTPUT);
    // pinMode(DATAPIN0 , OUTPUT);
    // pinMode(DATAPIN1 , OUTPUT);
    // pinMode(DATAPIN2 , OUTPUT);
    // pinMode(DATAPIN3 , OUTPUT);
    pinMode(DATAPIN4 , OUTPUT);
    pinMode(DATAPIN5 , OUTPUT);
    pinMode(DATAPIN6 , OUTPUT);
    pinMode(DATAPIN7 , OUTPUT);
    // pinMode(CONTRAST, OUTPUT);

    // analogWrite(CONTRAST, 250);
}

void loop()
{
    digitalWrite(DATAPIN7, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN5, HIGH);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, LOW);
    setAllToLow();
    delay(1000);
    



    digitalWrite(DATAPIN7, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN5, HIGH);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, LOW);
    setAllToLow();

    digitalWrite(DATAPIN7, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, LOW);
    setAllToLow();
    delay(1000);




    delay(100);
    digitalWrite(DATAPIN7, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, LOW);
    setAllToLow();

    digitalWrite(DATAPIN7, HIGH);
    digitalWrite(DATAPIN6, HIGH);
    digitalWrite(DATAPIN5, HIGH);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, LOW);
    setAllToLow();
    delay(1000);

    delay(100);
    digitalWrite(DATAPIN7, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, LOW);
    setAllToLow();

    digitalWrite(DATAPIN7, LOW);
    digitalWrite(DATAPIN6, HIGH);
    digitalWrite(DATAPIN5, HIGH);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, LOW);
    setAllToLow();
    delay(3000);




    delay(100);
    digitalWrite(DATAPIN7, LOW);
    digitalWrite(DATAPIN6, HIGH);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, HIGH);
    setAllToLow();

    digitalWrite(DATAPIN7, HIGH);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(REGSELECT, HIGH);
    setAllToLow();
    delay(3000);


}
