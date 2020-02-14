# This script automates the sketch build ready for uploading arduino pro mini
# Board specifications should be checked but it should work for arduino Uno too.
# Output type to upload is ".hex".
# Everthing is done in in two steps:
# We use arduino builder executable file to create the hex file and upload it using avrdude.
# Step 1 - Build Step
# Step 2 - Upload Step
# This script only handles Step 1.
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

createDir()
{
    mkdir $1
    # Check if we created the directory, otherwise abort and raise error.
    if [ ! -d $1 ];then
        error 'Unable to create the directory!'
        info 'You might not have the permission. Try running using \"sudo\"...'
        exit
    fi
}
removeDir()
{
    rm -drf $1
    if [ -d $1 ];then
        error 'Unable to remove directory!'
        info 'You might not have the permission. Try running using \"sudo\"...'
        exit
    fi
}

DEFAULT_TEMP=/tmp

# Entry Point
if [ $# -eq 0 ];then
    error 'Usage: ./ul_arduino.sh <FILENAME>.ino'
    exit
fi

FILE_FULL_NAME=$(readlink $1 -f --canonicalize)

# Check if file is an ".ino" file, abort otherwise.
if [[ ! $FILE_FULL_NAME == *".ino" ]];then
    error "Only arduino (\".ino\") files are supported!"
    exit
fi

# Check if the source file is there, abort otherwise.
if [ ! -f $FILE_FULL_NAME ];then
    error 'Could not locate the file!'
    exit
fi

# Generate an output file name using the source file name.
FILE_BASENAME=$(basename "$1")
name_len=${#FILE_BASENAME}
FILE_NAME_WITHOUT_EXT="${FILE_BASENAME:0:$((name_len-4))}"
BUILD_PATH=$DEFAULT_TEMP/$(date +%d%m%y)_$FILE_NAME_WITHOUT_EXT

# Create output directory.
# First we check if user requested overwrite.
overwrite=false
for arg in "$@";do
    if [ "$arg" == "-ow" ];then
        overwrite=true
        break
    fi
done

# Check if it is already existent if not create.
if [ ! -d $BUILD_PATH ];then
    info 'Creating build directory here ->' $BUILD_PATH
    createDir $BUILD_PATH
fi

# At this point directory is existent, it is up the -ow flag.
if [ $overwrite == false ];then
    info 'Target directory is already existent, if you are sure run the script again using overwrite flag "-ow"'
    exit
fi

# Force delete everything in with this directory.
info 'Overwriting existing files.'
removeDir $BUILD_PATH
# Here it should be possible to create the directory.
createDir $BUILD_PATH

# Build Command
BUILDER=/home/lyonbach/Programs/arduino-1.8.10/arduino-builder

FLAGS="-compile \
-logger=machine \
-logger=machine \
-hardware /home/lyonbach/Programs/arduino-1.8.10/hardware \
-hardware /home/lyonbach/.arduino15/packages \
-tools /home/lyonbach/Programs/arduino-1.8.10/tools-builder \
-tools /home/lyonbach/Programs/arduino-1.8.10/hardware/tools/avr \
-tools /home/lyonbach/.arduino15/packages \
-built-in-libraries /home/lyonbach/Programs/arduino-1.8.10/libraries \
-libraries /home/lyonbach/Arduino/libraries
-fqbn=arduino:avr:pro:cpu=16MHzatmega328 \
-ide-version=10810 \
-warnings=all \
-prefs=build.warn_data_percentage=75 \
-prefs=runtime.tools.arduinoOTA.path=/home/lyonbach/.arduino15/packages/arduino/tools/arduinoOTA/1.3.0 \
-prefs=runtime.tools.arduinoOTA-1.3.0.path=/home/lyonbach/.arduino15/packages/arduino/tools/arduinoOTA/1.3.0 \
-prefs=runtime.tools.avr-gcc.path=/home/lyonbach/.arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5 \
-prefs=runtime.tools.avr-gcc-7.3.0-atmel3.6.1-arduino5.path=/home/lyonbach/.arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5 \
-prefs=runtime.tools.avrdude.path=/home/lyonbach/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17  \
-prefs=runtime.tools.avrdude-6.3.0-arduino17.path=/home/lyonbach/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17 \
-verbose
-build-path $BUILD_PATH"
COMMAND="$BUILDER $FLAGS $FILE_FULL_NAME"
# Fire
$COMMAND

# -build-cache $BUILD_PATH/$CACHE_FILE_NAME \
# Check if we build the file successfully
OUTPUT_FILE_FULL_NAME=$BUILD_PATH/$FILE_BASENAME.hex
if [ ! -f "$OUTPUT_FILE_FULL_NAME" ];then
    error 'Could not create the hex file!'
    exit
fi
info "\"$OUTPUT_FILE_FULL_NAME\" was successfully created."
