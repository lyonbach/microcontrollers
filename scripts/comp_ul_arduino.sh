# This script automates the steps below.
# Step 1 - Compile arduino.ino sketch into a hex file.
# Step 2 - Upload hex file to arduino.
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

COMPILE_SCRIPT_PATH=./comp_arduino.sh
UPLOAD_SCRIPT_PATH=./ul_arduino.sh

echo "$COMPILE_SCRIPT_PATH"
echo "$UPLOAD_SCRIPT_PATH"

# Entry Point
if [ $# -eq 0 ];then
    error 'Usage: ./comp_ul_arduino.sh <FILENAME>.ino'
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

OVERWRITE=
for arg in "$@";do
    if [ "$arg" == "-ow" ];then
        OVERWRITE=-ow
        break
    fi
done

# Buld command.
 COMMAND="$COMPILE_SCRIPT_PATH $FILE_FULL_NAME $OVERWRITE"
output="eval $COMMAND"

success=$($output | grep 'was successfully created')
if [ "$success" == '' ];
    echo test
fi
# #TODO: verbose option.
# if [ "$( == '' ];then
#     echo $output
#     error "There was an error creating file."
# fi