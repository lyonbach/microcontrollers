#!/home/lyonbach/Programs/python375/bin/python3
"""
This program serves as a tiny automation tool for my arduino program development
pipeline.
Usage: Run the tool from the commandline via python with the full pathname of the file
to be uploaded as the only argument.
"""

import os
import sys
import shutil
import subprocess
import time
import tempfile

BOARDTAG = 'pro5v328'

ARDUINO_REPO = '/home/lyonbach/repositories/microcontrollers/arduino'

MAKEFILE = ['MAKEFILE_COMMANDS = "ARDUINO_DIR = /usr/share/arduino"\n',
            'ARDUINO_PORT = /dev/ttyUSB0',
            'USER_LIB_PATH = /home/pi/sketchbook/libraries\n',
            'BOARD_TAG = {}\n\n'.format(BOARDTAG),
            'include /usr/share/arduino/Arduino.mk']
BUILDNAME = 'current_arduino_build'
TEMPDIR = '/tmp/{}'.format(BUILDNAME)

# The hex file to be uploaded after a successful build.
HEXFILE = '{}/build-{}/{}.hex'.format(TEMPDIR, BOARDTAG, BUILDNAME)


class NotEnoughArgumentsError(Exception):
    pass

class CanNotCreateTempBuildDirectoryError(Exception):
    pass

class FileNotFoundError(Exception):
    pass

class BuildUnsuccessfullError(Exception):
    pass

def build():

    # Wait until the directory being created.
    while True:
        if os.path.isdir(TEMPDIR):
            break

    # Create the command to be called to build the hex code using Arduino.mk.

    ti = time.time()
    command = ["make", "-C", TEMPDIR]
    proc = subprocess.Popen(command, shell=False)

    o, e = proc.communicate()

    if e:
        print (e)
        raise BuildUnsuccessfullError

    return time.time() - ti, o

# Check argument.
if len(sys.argv) <= 1:
    raise NotEnoughArgumentsError

file_full_name = sys.argv[1]

if not os.path.exists(file_full_name):
    raise FileNotFoundError

try:
    if not os.path.exists(TEMPDIR):
        os.mkdir(TEMPDIR)

    file_name = os.path.basename(file_full_name)
    shutil.copyfile(file_full_name, os.path.join(TEMPDIR, file_name))

except:
    raise CanNotCreateTempBuildDirectoryError

with open('{}/Makefile'.format(TEMPDIR), 'w') as makefile:
    makefile.writelines(MAKEFILE)

dt, output = build()

print("Build was done in {:.1f}s".format(dt))
print("Starting upload...")
# if os.path.isfile(HEXFILE):
command = 'sudo avrdude -c linuxgpio -p atmega328p -v -U flash:w:"{}":i'.format(HEXFILE)
subprocess.call(command, shell=True)
print (command)

