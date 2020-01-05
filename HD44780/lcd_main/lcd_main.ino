#include "Arduino.h"
#include "lcd4.h"

// Pins are defined in LCD.h!
#define BAUDRATE 115200

// Command mapping for tests
#define FUNCTION_SET1 "f1"
#define FUNCTION_SET2 "f2"
#define SET_DISPLAY "sd"
#define SET_ENTRY_MODE "sem"
#define RETURN_HOME "ret"
#define C_L "ll"
#define C_B "bb"
#define C_COL "col" 
#define C_LC "leftc"
#define READ_BUSY_FLAG "rbf"
#define CLEAR_SCREEN "cls"

lcd4 *LCD;

void getCommandsFromSerialInput()
{
    // Listens the serial port for any commands and calls the necessary functions.
    String readString;
    while (Serial.available()) {
        delay(3);  //delay to allow buffer to fill
        if (Serial.available() > 0) {
        char c = Serial.read();  //gets one byte from serial buffer
        readString += c; //makes the string readString
        Serial.println(c);

        }
    }

    if (readString.length() >0) {
        Serial.println(readString); //see what was received
        if (readString == FUNCTION_SET1)
            LCD->iFunctionSet1();
        else if (readString == FUNCTION_SET2)
            LCD->iFunctionSet(1, 1, 0);
        else if (readString == SET_DISPLAY)
            LCD->iSetDisplay(1, 1, 1);
        else if (readString == SET_ENTRY_MODE)
            LCD->iSetEntryMode(1, 0);
        else if (readString == RETURN_HOME)
            LCD->iReturnHome();
        else if (readString == C_L)
            LCD->wChar('L');
        else if (readString == C_B)
            LCD->wChar('B');
        else if (readString == C_COL)
            LCD->wChar(':');
        else if (readString == C_LC)
            LCD->wChar(')');
        else if (readString == READ_BUSY_FLAG)
            LCD->rBusyFlag();
        else if (readString == CLEAR_SCREEN)
            LCD->iClearDisplay();
    }

}


void setup()
{
    // In this function we set all of the pins as output.
    // And also initialize the serial connection.

    Serial.begin(BAUDRATE);
    Serial.flush();
    Serial.println();
    Serial.println("[ESP8266] Listening...");

    pinMode(REGSELECT, OUTPUT);
    pinMode(READWRITE, OUTPUT);
    pinMode(ENABLE   , OUTPUT);
    pinMode(DATAPIN4 , OUTPUT);
    pinMode(DATAPIN5 , OUTPUT);
    pinMode(DATAPIN6 , OUTPUT);
    pinMode(DATAPIN7 , OUTPUT);
    LCD = new lcd4();

}

void loop()
{
    getCommandsFromSerialInput();
}
