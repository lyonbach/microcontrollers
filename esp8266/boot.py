# This file is executed on every boot (including wake-boot from deepsleep)
#import esp
#esp.osdebug(None)

import gc
import mcrp_autoconnect
import led_turn_on
#import webrepl
#webrepl.start()
gc.collect()

