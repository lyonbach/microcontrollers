#define LED_BUILTIN 13

void strobe()
{
    for (uint8_t i = 0; i < 5; i++)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(25);
        digitalWrite(LED_BUILTIN, LOW);
        delay(25);
    }
    delay(1250);
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);    
}

void loop()
{

    strobe();

}