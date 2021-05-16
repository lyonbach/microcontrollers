import machine
import time
import constants
import server

def flash_on(indicator_pin, led_flash_pin):

    # Blink three times to indicate that flash will be on.
    for i in range(2):
        indicator_pin.off() # actually on.
        time.sleep(.05)
        indicator_pin.on()  # actually off.
        time.sleep(.05)

    # Light up the led flash.
    led_flash_pin.on()

def flash_off(led_flash_pin):

    led_flash_pin.off()
    

def run():

    # Initialize pins.
    indicator_pin = machine.Pin(constants.ON_BOARD_LED, machine.Pin.OUT)
    led_flash_pin = machine.Pin(constants.LED_FLASH_PIN, machine.Pin.OUT)

    indicator_pin.on()  # Because of NodeMCU esp8266 reverse connection on is actually off for pin 2.

    print("Running main program...")
    socket = server.start_server()
    should_continue = True
    while should_continue:
        connection, client_address = socket.accept()
        print("{} connected!".format(client_address))
        data = server.receive_data(connection)

        if data == constants.TURN_ON:
            print("Received turn on command!")
            flash_on(indicator_pin, led_flash_pin)

        elif data == constants.TURN_OFF:
            print("Received turn off command!")
            flash_off(led_flash_pin)

        elif data == constants.STOP:
            print("Shutting down...")
            should_continue = False
            flash_off(led_flash_pin)

        connection.close()
