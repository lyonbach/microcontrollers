#!./../../../venv/bin/python
import time
import random
import serial
import sys

PORT_NAME = "/dev/ttyUSB0"
BAUDRATE = 115200
LED_COUNT = 30

def check_serial_port(port_name):
    esp = serial.Serial(port_name)  # we know that we are connected to this port but normally we should get this via code.
    print(esp.name)

def write(port_name, message):

    with serial.Serial(port_name, BAUDRATE, timeout=1) as esp:
        esp.write(message)

def is_ok_to_send(port_name):

    with serial.Serial(port_name, BAUDRATE, timeout=1) as esp:
        return esp.read(10) == b'over'

def write_to_port(command):
    command_part_1 = "<" + command[:135] + ">"
    write(PORT_NAME, bytes(command_part_1, "utf-8"))
    time.sleep(.05)
    command_part_2 = "<" + command[135:] + ">"
    write(PORT_NAME, bytes(command_part_2, "utf-8"))

def test_proc_1():

    """
    Test Procedure 1
    Send Complete Red to each led every second. Turn off all others. -> Once
    Wait 3 seconds. (While waiting first 3 leds will be used as a counter.)
    Turn On All Leds Complete White for 1 second.
    Turn Off All Leds.
    Wait 3 seconds. (While waiting first 3 leds will be used as a counter.)
    """

    def _get_command(leds_, red=None, green=None, blue=None):

        command =  ""
        r = "255" if red else "000"
        b = "255" if blue else "000"
        g = "255" if green else "000"
        for led in leds_:
            command += f"{r}{g}{b}" if led == 1 else "000000000"
        return command

    # Send Complete Red to each led every second.
    def _test_proc_1_1(leds_):

        print("Inside Test Proc 1 - 1")
        for i in range(len(leds_)):
            leds_[i] = 1
            if i > 0:
                leds[i-1] = 0
            command = _get_command(leds_, red=True)
            write_to_port(command)
            print(command)
            if i >= LED_COUNT - 1:
                leds[i] = 0
            time.sleep(.12)

    def _test_proc_1_2(leds_):
        
        print("Inside Test Proc 1 - 2")
        for i in range(3):  # We use only first 3
            leds_[i] = 1
            command = _get_command(leds_, red=True, green=True, blue=True)
            print(command)
            write_to_port(command)
            time.sleep(.12)
    
    leds = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  # We use only first 3
    _test_proc_1_1(leds)
    _test_proc_1_2(leds)

# get_command = lambda : ''.join([str(random.randint(0, 255)).zfill(3) for i in range(43)])


if __name__ == "__main__":
    test_proc_1()