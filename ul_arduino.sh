# This script auto-uploads the sketches using avrdude via SPI interface from RaspberryPi (ver:B+)
# For additional information how to use the tool the original website can be found at:
# http://savannah.nongnu.org/projects/avrdude

# Board Information:
# Name: Arduino Pro Mini
# Chip: ATmega328 running at 16MHz
# Version: 5V

# Pin Info
# The board and RaspberryPi connections are depicted below.
# 
#     ==========================================
#     | RasbPi (Num\Desc) | Arduino (Num\Desc) |
#     ==========================================
# PIN |                   |      10 (SS)       |
# PIN |                   |      11 (MOSI)     |
# PIN |                   |      12 (MISO)     |
# PIN |                   |      13 (SCK)      |

# Checks
if [ "$#" -ne 2 ];then
    echo 'Exactly two argument is expected for script name.'
    echo 'First argument: sketch'
    echo 'Second argument: board'
    exit
fi

FILENAME=$1
BOARD=$2

name_len=${#FILENAME}
extension="${FILENAME:$((name_len-4)):4}"
if [ ! $extension == '.ino' ]; then
    echo 'Only files with .ino extensions are supported.'
    exit
fi

echo $FILENAME
echo $BOARD

AVAILABLE_BOARDS='pro5v328 esp8266'

