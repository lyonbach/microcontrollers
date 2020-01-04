#!/bin/bash
# This script tests the serialRead.ino sketch with the following pin configuration.
# Pin numbers are translated as below:

# |=======|======|============|
# | PIN   | NAME | DEFINITION |
# |=======|======|============|
# | GPIO4 | (D2) | REDPIN     |
# | GPIO0 | (D3) | GREENPIN   |
# | GPIO2 | (D4) | BLUEPIN    |
# |===========================|

# DEFINITIONS
DEVICE_ADDRESS=/dev/ttyUSB0
TEST_CYCLE_LIMIT=1000
SPOTS=6
LAST_COLOR_CHOICE=NONE

# FUNCTIONS
red()
{
    echo "r" > $DEVICE_ADDRESS
    return 0
}

green()
{
    echo "g" > $DEVICE_ADDRESS
    return 1
}

blue()
{
    echo "b" > $DEVICE_ADDRESS
    return 2
}

white()
{
    echo "w" > $DEVICE_ADDRESS
    return 3
}

off()
{
    echo "o" > $DEVICE_ADDRESS
    return 4
}

random_switch()
{
    if [ $(($RANDOM % $SPOTS)) == 0 ]
    then
        red
    elif [ $(($RANDOM % $SPOTS)) == 1 ]
    then
        green
    elif [ $(($RANDOM % $SPOTS)) == 2 ]
    then
        blue
    elif [ $(($RANDOM % $SPOTS)) == 3 ]
    then
        white
    fi
    return $?
}

test_flash_all()
{
    COUNTER=0
    while [ $COUNTER -lt $TEST_CYCLE_LIMIT ]
    do
    random_switch

    result=$?
    # if [ $result == $LAST_COLOR_CHOICE ]
    # then
    #     echo "SKIPPED at $COUNTER"
    #     continue
    # else
    COUNTER=$(($COUNTER+1))
    sleep .$1
    # fi
    LAST_COLOR_CHOICE=$result

    done
}

# TESTS
echo "[INFO]: Starting tests..."
while [ true ]
do
    for i in {1..3}
    do
    red
    sleep .5
    green
    sleep .5
    blue
    sleep .5
    done

    for i in {1..60}
    do
    white
    sleep .01
    off
    sleep .03
    done
done
