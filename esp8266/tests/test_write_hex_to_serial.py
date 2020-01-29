#!./../../venv/bin/python
import time
import random
import serial
import sys

PORT_NAME = "/dev/ttyUSB0"
BAUDRATE = 256000
LED_COUNT = 30
def get_command():

    command = ""
    for i in range(LED_COUNT):
        # command += ''.join([str(hex(random.randrange(255))).ljust(4, '0')[-2:].upper() for i in range(3)])
        # print(command)
        command += random.choice(("FF0000", "00FF00", "0000FF"))
    
    return '#' + command

def write(port_name, message):

    with serial.Serial(port_name, BAUDRATE, timeout=1) as esp:
        esp.write(message)

if __name__ == "__main__":
    command = get_command()
    print(command)
    write(PORT_NAME, bytes(command, 'utf-8'))
    sys.exit()
    bits_sent = 0
    ti = time.time()
    # for i in range(5):
    while True:
        bits_sent += 181
        command = get_command()
        # command = "#191919191919181818181818181818181818181818191919191919191919191919191919191919191919191919191919191919191919191919191919B3B3B31919191919191919191919192B2B2B4747472B2B2B4747472B2B2B"
        write(PORT_NAME, bytes(command, 'utf-8'))
        time.sleep(.22)
        print("last command:")
        print(command)
        print(bits_sent)
        print(time.time() - ti)
