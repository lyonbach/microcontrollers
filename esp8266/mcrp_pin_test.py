import machine

pin = machine.Pin(2, machine.Pin.OUT)

v = pin.value()
print("initial: {}\n".format(v))
pin.value(int(not bool(pin.value())))
v = pin.value()
print("final: {}\n".format(v))
