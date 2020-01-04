SKETCH=$1
# SKETCH=/home/lyonbach/Repositories/dcc19/Microcontrollers/arduino/WeihnachtsMorse/test/WeihnachtsMorse.ino
ARDUINO_BUILDER=/home/lyonbach/Programs/arduino-1.8.10/arduino-builder
BUILT_IN_LIBRARIES_FOLDERS=/home/lyonbach/Programs/arduino-1.8.10/libraries
FBQN=esp8266:esp8266:nodemcuv2:xtal=80,vt=flash,exception=legacy,ssl=all,eesz=4M2M,led=2,ip=lm2f,dbg=Disabled,lvl=None____,wipe=none,baud=115200
OTHER_LIBRARIES_FOLDERS=/home/lyonbach/Arduino/libraries
HARDWARE_FOLDER1=/home/lyonbach/Programs/arduino-1.8.10/hardware
HARDWARE_FOLDER2=/home/lyonbach/.arduino15/packages
TOOLS_FOLDER1=/home/lyonbach/Programs/arduino-1.8.10/tools-builder
TOOLS_FOLDER2=/home/lyonbach/Programs/arduino-1.8.10/hardware/tools/avr
TOOLS_FOLDER3=/home/lyonbach/.arduino15/packages
RTIV=10600

CURRENT=$(pwd)

echo Creating temporary folder.
mkdir -p $CURRENT/tmp

# echo 'Creating options json...'
# OPTIONS_FILE_FULL_NAME=$CURRENT/tmp/'options.json'

# echo '{' > $OPTIONS_FILE_FULL_NAME
# echo "    \"additionalFiles\":" "\"\"," >> $OPTIONS_FILE_FULL_NAME
# echo "    \"builtInLibrariesFolders\":" "\"$BUILT_IN_LIBRARIES_FOLDERS\"," >> $OPTIONS_FILE_FULL_NAME
# echo "    \"customBuildProperties\":" "\"\"," >> $OPTIONS_FILE_FULL_NAME
# echo "    \"fqbn\":" "\"$FBQN\"," >> $OPTIONS_FILE_FULL_NAME
# echo "    \"hardwareFolders\":" "\"$HARDWARE_FOLDERS\"," >> $OPTIONS_FILE_FULL_NAME
# echo "    \"otherLibrariesFolders\":" "\"$OTHER_LIBRARIES_FOLDERS\"," >> $OPTIONS_FILE_FULL_NAME
# echo "    \"runtime.ide.version\":" "\"$RTIV\"," >> $OPTIONS_FILE_FULL_NAME
# echo "    \"sketchLocation\":" "\"$SKETCH\"," >> $OPTIONS_FILE_FULL_NAME
# echo "    \"toolsFolders\":" "\"$TOOLS_FOLDERS\"" >> $OPTIONS_FILE_FULL_NAME
# echo '}' >> $OPTIONS_FILE_FULL_NAME


# clear the temporary folder with its contents
# HARDWARE
# TOOLS
$ARDUINO_BUILDER \
    -built-in-libraries $BUILT_IN_LIBRARIES_FOLDERS \
    -libraries $OTHER_LIBRARIES_FOLDERS \
    -build-path $CURRENT/tmp \
    -fqbn $FBQN \
    -hardware $HARDWARE_FOLDER1 \
    -hardware $HARDWARE_FOLDER2 \
    -tools $TOOLS_FOLDER1 \
    -tools $TOOLS_FOLDER2 \
    -tools $TOOLS_FOLDER3 \
    -verbose \
    $SKETCH
# rm $OPTIONS_FILE_FULL_NAME -drfv
    # -built-in-libraries /home/lyonbach/Programs/arduino-1.8.10/libraries \
    # -libraries /home/lyonbach/Arduino/libraries \
    # -build-path /home/lyonbach/Downloads/tmp \
    # -fqbn esp8266:esp8266:nodemcuv2:xtal=80,vt=flash,exception=legacy,ssl=all,eesz=4M2M,led=2,ip=lm2f,dbg=Disabled,lvl=None____,wipe=none,baud=115200 \
    # -verbose \
    # $SKETCH

    # -hardware /home/lyonbach/Programs/arduino-1.8.10/hardware \
    # -hardware /home/lyonbach/.arduino15/packages \
    # -tools /home/lyonbach/Programs/arduino-1.8.10/tools-builder \
    # -tools /home/lyonbach/Programs/arduino-1.8.10/hardware/tools/avr \
    # -tools /home/lyonbach/.arduino15/packages \
    # -fqbn arduino:avr:uno \
#   -hardware /usr/share/arduino/hardware \
#   -tools /usr/share/arduino/hardware/tools \
#   -tools /usr/share/arduino/tools-builder \
#   -libraries lib \
#   src/main.ino