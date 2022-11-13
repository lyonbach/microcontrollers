import machine
import time
import math

led = machine.PWM(machine.Pin(3), freq=500)

def pulse(l ,t):
    for i in range(20):
        l.duty(int(math.sin(i/10*math.pi) * 500 + 500))
        time.sleep_ms(t)

pulse(led, 20)
