# micropython

from machine import Pin

def callback(pin):
    print("pin change", pin)

# create two pins and configure as inputs
pi0 = Pin(0, Pin.IN)
pi1 = Pin(1, Pin.IN)

# here we define the pins to trigger when they detect an event
p0.irq(trigger=Pin.IRQ_FALLING, handler=callback)
p1.irq(trigger=Pin.IRQ_RAISING | Pin.IRQ_FALLING, handler=callback)
