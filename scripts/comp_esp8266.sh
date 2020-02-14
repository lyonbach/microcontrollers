# This script automates the sketc build and upload.
# Using the arduino extension for vscode was a little slower so I wanted to automate the upload process using a script.
# It basically calls what arduino ide is doing while we build and upload the sketches.
# I wanted to use averdude directly but arduino ide was using esptool.py to flash the mcu and upload the binary file so
# I stepped back and did the same.
#
#
# Everthing is done in in two steps:
# Step 1 - Build Step
# Step 2 - Upload Step
############################################################################# Bahadir Arslan ###########################

# Defaults Definitions
DEFAULT_TEMP=/tmp
DEFAULT_PORT=/dev/ttyUSB0
DEFAULT_BAUD_RATE=115200
CHIP_NAME=esp8266
SEPERATOR="#############################################################################"

# Entering Build Step
# Get Build Directory from File Name
FILE_FULL_NAME=$(readlink $1 -f --canonicalize)
FILE_BASENAME=$(basename "$1")
name_len=${#FILE_BASENAME}
FILE_NAME_WITHOUT_EXT="${FILE_BASENAME:0:$((name_len-4))}"
BUILD_PATH=$DEFAULT_TEMP/$(date +%d%m%y)_$FILE_NAME_WITHOUT_EXT

# Check if file is an ".ino" file, abort otherwise.
if [[ ! $FILE_FULL_NAME == *".ino" ]];then
    echo "[ERROR]: Only arduino (\".ino\") files! Aborted..."
    exit
fi

# Create the Directory if not [ -d "/path/to/dir" ]
if [ ! -d $BUILD_PATH ];then
    echo "[INFO]: Creating build directory here -> "$BUILD_PATH
    mkdir $BUILD_PATH
    if [ ! -d $BUILD_PATH ];then
        echo "[ERROR]: Unable to create the directory!"
        echo "[INFO]: Try running using \"sudo\"..."
    fi
    else
    echo "[INFO]: Directory already exists, using -> "$BUILD_PATH
fi

echo "[INFO]: Starting build."
# Call builder
# TODO: Instead of using huge amount of arguments pass a configuration file.
/home/lyonbach/Programs/arduino-1.8.10/arduino-builder \
    -compile \
    -logger=machine \
    -hardware /home/lyonbach/Programs/arduino-1.8.10/hardware \
    -hardware /home/lyonbach/.arduino15/packages \
    -tools /home/lyonbach/Programs/arduino-1.8.10/tools-builder \
    -tools /home/lyonbach/Programs/arduino-1.8.10/hardware/tools/avr \
    -tools /home/lyonbach/.arduino15/packages \
    -built-in-libraries /home/lyonbach/Programs/arduino-1.8.10/libraries \
    -libraries /home/lyonbach/Arduino/libraries \
    -ide-version=10810 \
    -warnings=all \
    -prefs=build.warn_data_percentage=75 \
    -prefs=runtime.tools.mklittlefs.path=/home/lyonbach/.arduino15/packages/esp8266/tools/mklittlefs/2.5.0-4-69bd9e6 \
    -prefs=runtime.tools.mklittlefs-2.5.0-4-69bd9e6.path=/home/lyonbach/.arduino15/packages/esp8266/tools/mklittlefs/2.5.0-4-69bd9e6 \
    -prefs=runtime.tools.python3.path=/home/lyonbach/.arduino15/packages/esp8266/tools/python3/3.7.2-post1 \
    -prefs=runtime.tools.python3-3.7.2-post1.path=/home/lyonbach/.arduino15/packages/esp8266/tools/python3/3.7.2-post1 \
    -prefs=runtime.tools.mkspiffs.path=/home/lyonbach/.arduino15/packages/esp8266/tools/mkspiffs/2.5.0-4-b40a506 \
    -prefs=runtime.tools.mkspiffs-2.5.0-4-b40a506.path=/home/lyonbach/.arduino15/packages/esp8266/tools/mkspiffs/2.5.0-4-b40a506 \
    -prefs=runtime.tools.xtensa-lx106-elf-gcc.path=/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506 \
    -prefs=runtime.tools.xtensa-lx106-elf-gcc-2.5.0-4-b40a506.path=/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506 \
    -fqbn=esp8266:esp8266:nodemcuv2:xtal=80,vt=flash,exception=legacy,ssl=all,eesz=4M2M,led=2,ip=lm2f,dbg=Disabled,lvl=None____,wipe=none,baud=115200 \
    -build-cache /home/lyonbach/Downloads/tmp/cache \
    -build-path $BUILD_PATH \
    -verbose \
    $FILE_FULL_NAME

BUILT_BIN=$BUILD_PATH/$FILE_BASENAME.bin
if [ -f $BUILT_BIN ];then
    echo $SEPERATOR
    echo "[INFO]: File successfully created as -> "$BUILT_BIN
    else
    echo $SEPERATOR
    echo "[ERROR]: Unable to create the binary. Please check the terminal to understand what went wrong, aborted..."
    exit
fi

echo "[INFO]: File compiled!"
echo "[SUMMARY]:"
echo "Sketch Full Name: "$FILE_FULL_NAME
echo "Created Binary  : "$BUILT_BIN