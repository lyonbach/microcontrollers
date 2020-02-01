#include "Arduino.h"
#include "lcd4.h"

// Pins are defined in LCD.h!
#define BAUDRATE 115200

// Command mapping for tests
#define FUNCTION_SET1 "f1"
#define FUNCTION_SET2 "f2"
#define SET_DISPLAY_ON "sd1"
#define SET_DISPLAY_OFF "sd0"
#define SET_ENTRY_MODE_SR "smr"
#define SET_ENTRY_MODE_SL "sml"
#define RETURN_HOME "rt"
#define READ_BUSY_FLAG "rbf"
#define CLEAR_SCREEN "cls"
#define SHIFT_DISPLAY_TO_RIGHT "sdr"
#define SHIFT_DISPLAY_TO_LEFT "sdl"
#define SHIFT_CURSOR_TO_RIGHT "scr"
#define SHIFT_CURSOR_TO_LEFT "scl"
#define SCRIPT_MODE_ON "sm1"
#define SCRIPT_MODE_OFF "sm0"

lcd4 *LCD;

void initPins()
{
    pinMode(REGSELECT, OUTPUT);
    pinMode(READWRITE, OUTPUT);
    pinMode(ENABLE   , OUTPUT);
    pinMode(DATAPIN4 , OUTPUT);
    pinMode(DATAPIN5 , OUTPUT);
    pinMode(DATAPIN6 , OUTPUT);
    pinMode(DATAPIN7 , OUTPUT);
}


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
        if (LCD->scriptMode)
        {
            if (readString == SCRIPT_MODE_OFF)
            {
                LCD->setScriptMode(false);
                return;
            }
            for (char c : readString)
            {
                LCD->wChar(c);
            }
            return;
        }

        if (readString == FUNCTION_SET1)
            LCD->iFunctionSet1();
        else if (readString == FUNCTION_SET2)
            LCD->iFunctionSet(1, 1, 0);
        else if (readString == SET_DISPLAY_ON)
            LCD->iSetDisplay(1, 1, 1);
        else if (readString == SET_DISPLAY_OFF)
            LCD->iSetDisplay(0, 1, 1);
        else if (readString == SET_ENTRY_MODE_SR)
            LCD->iSetEntryMode(1, 0);
        else if (readString == SET_ENTRY_MODE_SL)
            LCD->iSetEntryMode(1, 1);
        else if (readString == RETURN_HOME)
            LCD->iReturnHome();
        else if (readString == READ_BUSY_FLAG)
            LCD->rBusyFlag();
        else if (readString == CLEAR_SCREEN)
            LCD->iClearDisplay();
        else if (readString == SHIFT_DISPLAY_TO_RIGHT)
            LCD->iShiftCursorOrDisplay(1, 0);
        else if (readString == SHIFT_DISPLAY_TO_LEFT)
            LCD->iShiftCursorOrDisplay(1, 1);
        else if (readString == SHIFT_CURSOR_TO_RIGHT)
            LCD->iShiftCursorOrDisplay(0, 1);
        else if (readString == SHIFT_CURSOR_TO_LEFT)
            LCD->iShiftCursorOrDisplay(0, 0);
        else if (readString == SCRIPT_MODE_ON)
            {
                LCD->setScriptMode(true);
            }
        }
        if (LCD->debugMode)
        {
            Serial.println(readString); //see what was received
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

    initPins();

    LCD = new lcd4();

}

void loop()
{
    getCommandsFromSerialInput();
}
