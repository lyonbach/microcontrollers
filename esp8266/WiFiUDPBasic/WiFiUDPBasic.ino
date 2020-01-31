#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "esp8266/ConnectToWiFi.h"

#ifndef WDR
#define WDR while(true) // Watch Dog Reset
#endif

WiFiUDP Udp;

unsigned int localUDPPort = 512;
char incomingPacket[256];
char replyPacket[] = "Cheese!";
long int lastPacketCountUpdate = millis();
int packetCount = 0;

void setup(){
    
    Serial.begin(BAUD);
    Serial.println('\n');
    Serial.flush();

    Connect();
    Udp.begin(localUDPPort);
    Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUDPPort);

}

void loop() {

    if (millis() - lastPacketCountUpdate > 15000)
    {
        lastPacketCountUpdate = millis();
        Serial.printf("Overall packet count: %d\n", packetCount);
        packetCount = 0;
        Serial.println("Now you can start testing...");
    }

    int packetSize = Udp.parsePacket();

    if (packetSize)
    {
        Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
        int len = Udp.read(incomingPacket, 255);
        Serial.printf("UDP packet contents: %s\n", incomingPacket);
        if (len > 0)
        {
            incomingPacket[len] = 0;
        }
        packetCount++;
        // send back a reply, to the IP address and port we got the packet from
        Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
        Udp.write(replyPacket);
        Udp.endPacket();
    }

}