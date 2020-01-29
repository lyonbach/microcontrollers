#!./../../../venv/bin/python
import time
import random
import serial

PORT_NAME = "/dev/ttyUSB0"
BAUDRATE = 115200

def check_serial_port(port_name):
    esp = serial.Serial(port_name)  # we know that we are connected to this port but normally we should get this via code.
    print(esp.name)

def parse_command(command):

    print(len(command))
    for n in range(30):
        r, g, b = 0, 0, 0
        for i in range(3):
            dec = (10**(2-i))
            r += int(command[9 * n + i + 0]) * dec
            g += int(command[9 * n + i + 3]) * dec
            b += int(command[9 * n + i + 6]) * dec
        print(r, g, b)

get_command = lambda : ''.join([str(random.randint(0, 255)).zfill(3) for i in range(45)])
command = get_command() + get_command()
print(command)
parse_command(command)

