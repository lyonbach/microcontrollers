/*  This is a test for getting familiar with the controls of HD44780 HITACHI LCD Module.

// INSTRUCTIONS - Applied according to https://www.sparkfun.com/datasheets/LCD/HD44780.pdf - Table 13 //
/*
    DESCRIPTIONS:
    0 -> LOW
    1 -> HIGH

    |==========================================================|
    |               INSTRUCTION 1 - CLEAR DISPLAY              |
    |==========================================================|
    | RS | R/W | DB7 | DB6 | DB5 | DB4 | DB3 | DB2 | DB1 | DB0 |
    | 0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |
    |==========================================================|
    |               INSTRUCTION 2 - RETURN HOME                |
    |==========================================================|
    | RS | R/W | DB7 | DB6 | DB5 | DB4 | DB3 | DB2 | DB1 | DB0 |
    | 0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  *  | -> *: NOT USED (but we set the pin to LOW)
    |==========================================================|
    |              INSTRUCTION 3 - ENTRY MODE SET              |
    |==========================================================|
    | RS | R/W | DB7 | DB6 | DB5 | DB4 | DB3 | DB2 | DB1 | DB0 | -> I/D: Increments (I/D=1) / decrements (I/D=0).
    | 0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  | I/D |  S  | -> S  : If I/D == 1 shifts the display to right else left.
    |==========================================================|
    |              INSTRUCTION 4 - DISPLAY ON/OFF              |
    |==========================================================|
    | RS | R/W | DB7 | DB6 | DB5 | DB4 | DB3 | DB2 | DB1 | DB0 | -> D: Display on or off. C: Cursor on/off.
    | 0  |  0  |  0  |  0  |  0  |  0  |  1  |  D  |  C  |  B  | -> B: Cursor blinking on/off.
    |==========================================================|
    |           INSTRUCTION 5 - CURSOR or DISPLAY SHIFT        |
    |==========================================================|
    | RS | R/W | DB7 | DB6 | DB5 | DB4 | DB3 | DB2 | DB1 | DB0 | -> S/C: Cursor or screen to be shifted.
    | 0  |  0  |  0  |  0  |  0  |  0  | S/C | R/L |  *  |  *  | -> R/L: Right or Left. *: Don't care.
    |==========================================================|
    |               INSTRUCTION 6 - FUNCTION SET               |
    |==========================================================|
    | RS | R/W | DB7 | DB6 | DB5 | DB4 | DB3 | DB2 | DB1 | DB0 | -> DL: Data length, if HIGH 8-bits else 4-bits.
    | 0  |  0  |  0  |  0  |  1  |  DL |  N  |  F  |  *  |  *  | -> N: Number of dispaly lines. F: Font. *: Don't care.
    |==========================================================|
    |             INSTRUCTION 7 - SET CGRAM ADDRESS            |
    |==========================================================|
    | RS | R/W | DB7 | DB6 | DB5 | DB4 | DB3 | DB2 | DB1 | DB0 | -> Sets the CGRAM address binary AAAAAA into the
    | 0  |  0  |  0  |  1  |  A  |  A  |  A  |  A  |  A  |  A  | address counter. Then data is read or written from the MPU.
    |==========================================================|
                           <---- Higher Order  Lower Order ---->

For ESP8266, the pin selection is described in the table below.
* We try to avoid the TX, DX pins because they are being used by the serial communication.

    |========|=======|============||===========|
    | PIN    | NAME  | DEFINITION ||  HD44780  |
    |========|=======|============||===========|
    | GPIO16 | (D0)  | DATAPIN7   ||    D7     |↑
    | GPIO5  | (D1)  | DATAPIN6   ||    D6     |
    | GPIO4  | (D2)  | DATAPIN5   ||    D5     |d
    | GPIO0  | (D3)  | DATAPIN4   ||    D4     |a
    | GPIO2  | (D4)  | DATAPIN3   ||    D3     |t
    | GPIO14 | (D5)  | DATAPIN2   ||    D2     |a
    | GPIO12 | (D6)  | DATAPIN1   ||    D1     |
    | GPIO13 | (D7)  | DATAPIN0   ||    D0     |↓
    | GPIO15 | (D8)  | ENABLE     ||    EN     |
    | GPIO10 | (SD3) | REGSELECT  ||    RS     |
    | GPIO9  | (SD2) | READWRITE  ||    RW     |
    | GND    | (GND) | GROUND     ||    GND    |
    |=============================||===========|

⭓ We need to connect VSS (of HD44780) to 5V+ and VDD to GND for power of the LCD.
⭓ Additionally, we need to connect A (anode) to 5V+ and K (kathode) to GND for the backlight,
*/

#include "Arduino.h"

// PIN DEFINITIONS
#define DATAPIN7 16
#define DATAPIN6 5
#define DATAPIN5 4
#define DATAPIN4 0
#define DATAPIN3 2
#define DATAPIN2 14
#define DATAPIN1 12
#define DATAPIN0 13
#define   ENABLE 15
#define REGSELECT 10
#define READWRITE 9

// OTHER
#define BAUDRATE 115200

int incomingByte;

void setAllToLow()
{
digitalWrite(REGSELECT, LOW);
digitalWrite(READWRITE, LOW);
digitalWrite(ENABLE  , LOW);
digitalWrite(DATAPIN0, LOW);
digitalWrite(DATAPIN1, LOW);
digitalWrite(DATAPIN2, LOW);
digitalWrite(DATAPIN3, LOW);
digitalWrite(DATAPIN4, LOW);
digitalWrite(DATAPIN5, LOW);
digitalWrite(DATAPIN6, LOW);
digitalWrite(DATAPIN7, LOW);
}

void testPIN(int pin, char* pinName=nullptr)
{
    // A convenience function for individual testing of pins.
    if(!pinName)
    {
        Serial.printf("Pin name not provided but connected on %d", pin);
    }

    Serial.printf("\nTesting the %s", pinName);
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
    delay(1000);
}


// Implementation of the instructions.
void clearDisplay()
{
    Serial.println("[ESP8266][INSTRUCTION]-> \"Clear Display\"");
    digitalWrite(DATAPIN0, HIGH);
    digitalWrite(DATAPIN1, LOW);
    digitalWrite(DATAPIN2, LOW);
    digitalWrite(DATAPIN3, LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN7, LOW);
    delay(10);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(READWRITE, LOW);
    digitalWrite(REGSELECT, LOW);
}

void returnHome()
{   digitalWrite(DATAPIN0, LOW);
    digitalWrite(DATAPIN1, HIGH);
    digitalWrite(DATAPIN2, LOW);
    digitalWrite(DATAPIN3, LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN7, LOW);
    delay(10);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(READWRITE, LOW);
    digitalWrite(REGSELECT, LOW);
}

void entryModeSet(int increment, int shift)
{
    Serial.println("[ESP8266][INSTRUCTION]-> \"Return Home\"");
    digitalWrite(DATAPIN0, shift);
    digitalWrite(DATAPIN1, increment);
    digitalWrite(DATAPIN2, HIGH);
    digitalWrite(DATAPIN3, LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN7, LOW);
    delay(10);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(READWRITE, LOW);
    digitalWrite(REGSELECT, LOW);
}

void setDisplayOnOff(int display, int cursor, int blinking)
{
    Serial.println("[ESP8266][INSTRUCTION]-> \"Return Home\"");
    digitalWrite(DATAPIN0, blinking);
    digitalWrite(DATAPIN1, cursor);
    digitalWrite(DATAPIN2, display);
    digitalWrite(DATAPIN3, HIGH);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN7, LOW);
    delay(10);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(READWRITE, LOW);
    digitalWrite(REGSELECT, LOW);
}

void shiftDisplayOrCursor(int SC, int LR)
{
    Serial.println("[ESP8266][INSTRUCTION]-> \"Return Home\"");
    digitalWrite(DATAPIN0, LOW);
    digitalWrite(DATAPIN1, LOW);
    digitalWrite(DATAPIN2, LR);
    digitalWrite(DATAPIN3, SC);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN7, LOW);
    delay(10);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(READWRITE, LOW);
    digitalWrite(REGSELECT, LOW);
}

void functionSet(int dataLength, int numLines, int font)
{
    Serial.println("[ESP8266][INSTRUCTION]-> \"Return Home\"");
    digitalWrite(DATAPIN0, LOW);
    digitalWrite(DATAPIN1, LOW);
    digitalWrite(DATAPIN2, LOW);
    digitalWrite(DATAPIN3, font);
    digitalWrite(DATAPIN4, numLines);
    digitalWrite(DATAPIN5, dataLength);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN7, LOW);
    delay(10);
    digitalWrite(ENABLE, HIGH);
    digitalWrite(READWRITE, LOW);
    digitalWrite(REGSELECT, LOW);
}

void setCGRAMAddress(int address)
{   /*Sets the instruction for 8 - bit; two line display; 5 x 10 pixels font mode*/
    Serial.println("Instruction -> Function Set");

    //TODO: Parse address to fit in first 6 bits.
    // Port B Pins
    digitalWrite(DATAPIN0, LOW);
    digitalWrite(DATAPIN1, LOW);
    digitalWrite(DATAPIN2, LOW);
    digitalWrite(DATAPIN3, LOW);
    digitalWrite(DATAPIN4, HIGH);
    digitalWrite(DATAPIN5, HIGH);
    digitalWrite(DATAPIN6, HIGH);
    digitalWrite(DATAPIN7, LOW);
    delay(100);
    // Port A Pins
    digitalWrite(REGSELECT, LOW);
    digitalWrite(READWRITE, LOW);
    digitalWrite(ENABLE, HIGH);
    delay(25);
}
