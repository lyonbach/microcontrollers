
#include "blink.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include <WiFiClient.h>
//To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266-webupdate.local/update

#ifndef STASSID
#define STASSID "UPC1625583"
#define STAPSK "DQJRFCNJ"
#define BAUDRATE 115200
#define UPLOAD_COMMAND "upload"
#define DUTY_COMMAND "duty"
#endif


const char* host = "esp8266";
const char* ssid = STASSID;
const char* password = STAPSK;
static bool waitForUpdates = true;
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

const String dutyCommand = String(DUTY_COMMAND);
const String uploadCommand = String(UPLOAD_COMMAND);

void listenForModeCommand()
{
    if (Serial.available() > 0)
    {
        String command;

        while(Serial.available() > 0)
        {
            char c = Serial.read();
            delay(3);
            command += c;
            Serial.print(c);
        }

        if(command == dutyCommand + "\0")
        {
            Serial.println("[INFO]: Switching to duty mode.");
            waitForUpdates = false;
        }
        else if (command == uploadCommand + "\0")
        {
            Serial.println("[INFO]: Switching to on air upload mode.");
            waitForUpdates = true;
        }
        Serial.flush();
    }
}

void setup(void) {

    Serial.begin(BAUDRATE);
    Serial.println();
    Serial.println("Booting Sketch...");
    WiFi.mode(WIFI_AP_STA);
    WiFi.begin(ssid, password);

    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        WiFi.begin(ssid, password);
        Serial.println("WiFi failed, retrying.");
    }

    MDNS.begin(host);

    httpUpdater.setup(&httpServer);
    httpServer.begin();

    MDNS.addService("http", "tcp", 80);
    Serial.printf("HTTPUpdateServer ready! Open http://%s/update in your browser\n", host);

    Serial.println("[INFO]: After the restart we first mode is upload on air mode.");
    Serial.println("[INFO]: To start the original mode, please enter the command ->");
    Serial.print(UPLOAD_COMMAND);

}

void loop(void)
{
    listenForModeCommand();
    if (waitForUpdates)
    {
        httpServer.handleClient();
        MDNS.update();
    } else 
    {
        duty();
    }
    
}

void duty()
{
    Serial.println("Duty mode...");
    delay(1000);
    blink_ino::_duty();
    Serial.println("Please implemend your actual code and use it here...");
}