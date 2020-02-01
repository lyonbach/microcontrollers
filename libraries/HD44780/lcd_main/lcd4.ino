#include "lcd4.h"

void lcd4::rBusyFlag()
{
    // Reads the busy flag. So the pin setup must be chhanged to get the data.
    int busyFlag;

    pinMode(DATAPIN7, INPUT);
    delay(5);
    digitalWrite(READWRITE, HIGH);
    digitalWrite(REGSELECT, LOW);
    delay(5);
    digitalWrite(ENABLE, HIGH);
    delay(3);
    busyFlag = digitalRead(DATAPIN7);
    digitalWrite(READWRITE, LOW);
    digitalWrite(ENABLE, LOW);
    pinMode(DATAPIN7, OUTPUT);
    Serial.printf("READ BUSY FLAG AS %d\n", busyFlag);
} 


void lcd4::iSetAll(int *bits)
{
    for (int i = 0; i < 4; i++)
    {
        // for (int iPin = 0; iPin < 4; iPin++)
        digitalWrite(dataPins[i], bits[i]);
    }
    digitalWrite(REGSELECT, bits[4]);
    digitalWrite(READWRITE, bits[5]);
}


void lcd4::iSetAllToLow()
{
    Serial.println("[ESP8266][INSTRUCTION]-> \"Set All To LOW\"");
    digitalWrite(REGSELECT, LOW);
    digitalWrite(READWRITE, LOW);
    digitalWrite(ENABLE  , LOW);
    digitalWrite(DATAPIN4, LOW);
    digitalWrite(DATAPIN5, LOW);
    digitalWrite(DATAPIN6, LOW);
    digitalWrite(DATAPIN7, LOW);
}


void lcd4::iCommitWrite() 
{   
    delay(5);
    digitalWrite(ENABLE, HIGH);
    delay(5);
    digitalWrite(ENABLE, LOW);
}


void lcd4::iFunctionSet1()
{
    // Sets the instructions for 4 - bit;
    Serial.println("[ESP8266][INSTRUCTION]-> \"Function Set 1\"");
    int bits[6] = {0, 1, 0, 0, 0, 0}; 
    iSetAll(bits);  // 0 1 0 0 00
    iCommitWrite();
    iSetAllToLow();
}


void lcd4::iFunctionSet(int dataLength, int displayLines, int font) 
{
    Serial.println("[ESP8266][INSTRUCTION]-> \"Function Set 2\"");
    int bits[6] = {dataLength, 1, 0, 0, 0, 0};  
    iSetAll(bits);  // DL 1 0 0 00
    iCommitWrite();

    bits[0] = 0;
    bits[1] = 0;
    bits[2] = font;
    bits[3] = displayLines;
    iSetAll(bits);  // 00FN 00
    iCommitWrite();
    iSetAllToLow();

}


void lcd4::iSetDisplay(int display, int cursor, int blink)
{
    Serial.printf("[ESP8266][INSTRUCTION]-> \"Set Display %s - %s cursor - blink %s\"\n", 
                  (display) ? "On" : "Off",
                  (cursor) ? "with" : "without",
                  (blink) ? "On" : "Off");

    int bits[6] = { 0, 0, 0, 0, 0, 0 };
    iSetAll(bits);  // 0 0 0 0 00
    iCommitWrite();

    bits[0] = display;  // D C B 1 00 -> D: display, C: cursor, B: blink
    bits[1] = cursor;
    bits[2] = blink;
    bits[3] = 1;
    iSetAll(bits);
    iCommitWrite();
    iSetAllToLow();
}

void lcd4::iShiftCursorOrDisplay(int target, int direction)
{
    // Shifts the cursor or display to the left or right.
    Serial.printf("[ESP8266][INSTRUCTION]-> \"Shift %s to %s\"",
    (target) ? "Display": "Cursor",
    (direction) ? "Left" : "Right");
    int bits[6] = { 1, 0, 0, 0, 0, 0 };
    iSetAll(bits);
    iCommitWrite();
    // int bits[6] = { 0, 0, direction, target, 0, 0 };
    bits[0] = 0;
    bits[2] = direction;
    bits[3] = target;

    iSetAll(bits);
    iCommitWrite();
    iSetAllToLow();
}


void lcd4::iSetEntryMode(int increment, int shift)
{
    Serial.printf("[ESP8266][INSTRUCTION]-> \"Entry Mode Set\" - increment %d - shift %s\n",
                  increment,
                  (shift) ? "On" : "Off");
    int bits[6] = {0, 0, 0, 0, 0, 0};  // 0 0 0 0 00
    iSetAll(bits);
    iCommitWrite();

    bits[0] = shift;
    bits[1] = increment;
    bits[2] = 1;
    iSetAll(bits);  // S I/D 1 0 00 -> S: shift, I/D: increment(or decrement)
    iCommitWrite();
}


void lcd4::iReturnHome()
{   
    Serial.println("[ESP8266][INSTRUCTION]-> \"Return Home\"");
    iSetAllToLow();
    iCommitWrite();

    int bits[6] = {0, 1, 0, 0, 0, 0};
    iSetAll(bits);
    iCommitWrite();

}


void lcd4::iClearDisplay()
{
    Serial.println("[ESP8266][INSTRUCTION]-> \"Clear Display\"");
    iSetAllToLow();
    iCommitWrite();

    int bits[6] = {1, 0, 0, 0, 0, 0};
    iSetAll(bits);
    iCommitWrite();
}


void lcd4::setScriptMode(bool state)
{
    Serial.printf("Script Mode: %s.\n" , (state) ? "On" : "Off");
    this->scriptMode = state;
}


void lcd4::wChar(char c)
{
    int* bits = getRomCode(c);

    {
    // Write Higher Order Bits
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(dataPins[i], bits[i]);
        // Serial.printf("dataPins -> %d bits-> %d\n", dataPins[i], bits[i]);
    }
    digitalWrite(REGSELECT, HIGH);
    digitalWrite(READWRITE, LOW);
    iCommitWrite();

    // Write Higher Order Bits
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(dataPins[i], bits[4+i]);
        // Serial.printf("dataPins -> %d bits-> %d\n", dataPins[i], bits[i]);
    }
    digitalWrite(REGSELECT, HIGH);
    digitalWrite(READWRITE, LOW);
    iCommitWrite();
}
}