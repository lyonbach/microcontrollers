import sys
import machine
import time
import math

led_n = 2 
amnt = .020

led = machine.Pin(led_n, machine.Pin.OUT)
for i in range(1, 51):
    
    led.value(0)
    time.sleep(amnt)
    led.value(1)
    time.sleep(amnt)
