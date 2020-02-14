# This script uploads the given hex file to arduino.
############################################################################# Bahadir Arslan ########################### 

# Definitions
error ()
{
    echo "[ERROR]: $*"
}

info ()
{
    echo "[INFO]: $*"

}

DEFAULT_PORT=/dev/ttyUSB0
DEFAULT_BAUD_RATE=57600
CHIP_NAME=m328p

# Entry Point
if [ $# -eq 0 ];then
    error 'Usage: ./ul_arduino.sh <FILE FULL NAME>.hex'
    exit
fi

INPUT_HEX_FILE=$1
if [ ! -f "$INPUT_HEX_FILE" ];then
    error Could not locate the file!
    exit
fi


# Check if file is an ".hex" file, abort otherwise.
FILE_FULL_NAME=$(readlink $1 -f --canonicalize)
if [[ ! $FILE_FULL_NAME == *".hex" ]];then
    error "Only \".hex\" files are supported!"
    exit
fi

# Check if arduino is reachable.
if [ "$(ls /dev/* | grep $DEFAULT_PORT)" != "$DEFAULT_PORT" ];then
    error 'Device not reachable!'
    exit
fi
info 'Successfully found device on '$DEFAULT_PORT
info 'Starting upload...'

# Build command.
UPLOADER=/home/lyonbach/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/bin/avrdude
CONFIGURATION_FILE=/home/lyonbach/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf
PROGRAMMER=arduino
FLAGS="-v \
-C$CONFIGURATION_FILE \
-c$PROGRAMMER \
-p$CHIP_NAME \
-P$DEFAULT_PORT \
-b$DEFAULT_BAUD_RATE \
-D \
-Uflash:w:$INPUT_HEX_FILE:i"
COMMAND="$UPLOADER $PROGRAMMER $FLAGS"
info 'Using '$UPLOADER
eval $COMMAND
