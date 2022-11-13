/*  This is a test for getting familiar with the controls of HD44780 HITACHI LCD Module.

// INSTRUCTIONS - Applied according to https://www.sparkfun.com/datasheets/LCD/HD44780.pdf
    This library was prepared to be able to use 4 bit operations.
    Please note that when we are communicating in 4-bits, we need to send two 4 bits of data to be able to send one
    instruction to the MPU.*
    

    * One exception for this is functionSet1 instruction, which is automatically applied as it is in 8 bit mode.
    DESCRIPTIONS:
    LOW  -> 0
    HIGH -> 1

    |============================================================|
    | INSTRUCTIONS                                               |
    |===================================||=======================|
    | Higher Order Bits                 || Lower Order Bits      |  
    |===================================||=======================|
    | RS  | R/W | DB7 | DB6 | DB5 | DB4 || DB7 | DB6 | DB5 | DB4 |
    |===================================||=======================|
    | SET ALL TO LOW (iSetAllToLow)     ||                       |
    |-----------------------------------||-----------------------|  
    |  0  |  0  |  0  |  0  |  0  |  0  || (NA) Sent Once        |
    |===================================||=======================|
    | FUNCTION SET 1                    ||
    |-----------------------------------||-----------------------|
    |  0  |  0  |  0  |  0  |  1  |  0  || (NA) Sent Once        |
    |===================================||=======================|
    | FUNCTION SET                      ||                       |
    |-----------------------------------||-----------------------|
    |  0  |  0  |  0  |  0  |  1  |  0  || 0  |  0  |  0  |  0   |
      

For ESP8266, the pin selection is described in the table below.
* We try to avoid the TX, DX pins because they are being used by the serial communication.

    |==========================================|
    | PIN SETUP FOR 4 BIT DATA TRANSFER        |
    |========|=======|============||===========|
    | PIN    | NAME  | DEFINITION ||  HD44780  |
    |========|=======|============||===========|
    | GPIO0  | (D3)  | DATAPIN4   ||    D4     |d
    | GPIO4  | (D2)  | DATAPIN5   ||    D5     |a
    | GPIO5  | (D1)  | DATAPIN6   ||    D6     |t
    | GPIO16 | (D0)  | DATAPIN7   ||    D7     |a
    | GPIO15 | (D8)  | ENABLE     ||    EN     |
    | GPIO10 | (SD3) | REGSELECT  ||    RS     |
    | GPIO9  | (SD2) | READWRITE  ||    RW     |
    | MOSI   | (SD1) | CONTRAST   ||    V0     | * We use this pin to set the screen contrast.    
    | GND    | (GND) | GROUND     ||    GND    | It has to be defined as analog output.
    |=============================||===========|

⭓ We need to connect VSS (of HD44780) to 3.3V+ and VDD to GND for power of the LCD.
⭓ Additionally, we need to connect A (anode) to 3.3V+ and K (kathode) to GND for the backlight,
*/
#ifndef LCD4_HEADER
#define LCD4_HEADER

#include "Arduino.h"
#include "lcd4_helpers.h"

// PIN DEFINITIONS
#define DATAPIN4 D3 //0
#define DATAPIN5 D2 //4
#define DATAPIN6 D1 //5
#define DATAPIN7 D0 //16
#define   ENABLE D8 //2
#define REGSELECT D5 //14
#define READWRITE D6 //12

struct lcd4
{
    // Vars
    const int dataPins[4] = {DATAPIN4, DATAPIN5, DATAPIN6, DATAPIN7};
    bool scriptMode = false;
    bool debugMode = false;
    
    // Read Functions
    /*
        TODO: PLEASE FINISH IMPLEMENTATION OF READ FUNCTIONS!
    */
    void rBusyFlag();

    // Instruction Functions
    void iCommitWrite();
    void iSetAll(int *bits);

    void iSetAllToLow();
    void iFunctionSet1();
    void iFunctionSet(int dataLength, int displayLines, int font);
    void iSetDisplay(int display, int cursor, int blink);
    void iShiftCursorOrDisplay(int target, int direction);
    void iSetEntryMode(int increment, int shift);
    void iReturnHome();
    void iClearDisplay();

    void setScriptMode(bool state);

    // Write Functions
    void wChar(char c);


    /*
        TODO: PLEASE IMPLEMENT WRITE FUNCTIONS
    */
    };

#endif /*LCD4_HEADER*/
