Using board 'nodemcuv2' from platform in folder: /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2
Using core 'esp8266' from platform in folder: /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2
Detecting libraries used...
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-g++ -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/include -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/lwip2/include -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/libc/xtensa-lx106-elf/include -I/home/lyonbach/Downloads/tmp/core -c -w -Os -g -mlongcalls -mtext-section-literals -fno-rtti -falign-functions=4 -std=gnu++11 -ffunction-sections -fdata-sections -fno-exceptions -w -x c++ -E -CC -DNONOSDK22x_190703=1 -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536 -DLWIP_FEATURES=1 -DLWIP_IPV6=0 -DARDUINO=10600 -DARDUINO_ESP8266_NODEMCU -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_NODEMCU\"" -DLED_BUILTIN=2 -DFLASHMODE_DIO -DESP8266 -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/cores/esp8266 -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/variants/nodemcu /home/lyonbach/Downloads/tmp/sketch/WeihnachtsMorse.ino.cpp -o /dev/null
Generating function prototypes...
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-g++ -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/include -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/lwip2/include -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/libc/xtensa-lx106-elf/include -I/home/lyonbach/Downloads/tmp/core -c -w -Os -g -mlongcalls -mtext-section-literals -fno-rtti -falign-functions=4 -std=gnu++11 -ffunction-sections -fdata-sections -fno-exceptions -w -x c++ -E -CC -DNONOSDK22x_190703=1 -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536 -DLWIP_FEATURES=1 -DLWIP_IPV6=0 -DARDUINO=10600 -DARDUINO_ESP8266_NODEMCU -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_NODEMCU\"" -DLED_BUILTIN=2 -DFLASHMODE_DIO -DESP8266 -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/cores/esp8266 -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/variants/nodemcu /home/lyonbach/Downloads/tmp/sketch/WeihnachtsMorse.ino.cpp -o /home/lyonbach/Downloads/tmp/preproc/ctags_target_for_gcc_minus_e.cpp
/home/lyonbach/Programs/arduino-1.8.10/tools-builder/ctags/5.8-arduino11/ctags -u --language-force=c++ -f - --c++-kinds=svpf --fields=KSTtzns --line-directives /home/lyonbach/Downloads/tmp/preproc/ctags_target_for_gcc_minus_e.cpp
Compiling sketch...
/home/lyonbach/.arduino15/packages/esp8266/tools/python3/3.7.2-post1/python3 /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/signing.py --mode header --publickey /home/lyonbach/Repositories/dcc19/Microcontrollers/arduino/WeihnachtsMorse/test/public.key --out /home/lyonbach/Downloads/tmp/core/Updater_Signing.h
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-g++ -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/include -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/lwip2/include -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/libc/xtensa-lx106-elf/include -I/home/lyonbach/Downloads/tmp/core -c -w -Os -g -mlongcalls -mtext-section-literals -fno-rtti -falign-functions=4 -std=gnu++11 -MMD -ffunction-sections -fdata-sections -fno-exceptions -DNONOSDK22x_190703=1 -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536 -DLWIP_FEATURES=1 -DLWIP_IPV6=0 -DARDUINO=10600 -DARDUINO_ESP8266_NODEMCU -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_NODEMCU\"" -DLED_BUILTIN=2 -DFLASHMODE_DIO -DESP8266 -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/cores/esp8266 -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/variants/nodemcu /home/lyonbach/Downloads/tmp/sketch/WeihnachtsMorse.ino.cpp -o /home/lyonbach/Downloads/tmp/sketch/WeihnachtsMorse.ino.cpp.o
Compiling libraries...
Compiling core...
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/cont.S.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_info.c.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_integrity.c.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_local.c.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_poison.c.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/Esp-frag.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/FunctionalInterrupt.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/FSnoop.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/FS.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/IPAddress.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/StackThunk.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/Esp-version.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/Esp.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/Print.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/StreamString.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/MD5Builder.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/WMath.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/HardwareSerial.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/Tone.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/Stream.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-g++ -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/include -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/lwip2/include -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/libc/xtensa-lx106-elf/include -I/home/lyonbach/Downloads/tmp/core -c -w -Os -g -mlongcalls -mtext-section-literals -fno-rtti -falign-functions=4 -std=gnu++11 -MMD -ffunction-sections -fdata-sections -fno-exceptions -DNONOSDK22x_190703=1 -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536 -DLWIP_FEATURES=1 -DLWIP_IPV6=0 -DARDUINO=10600 -DARDUINO_ESP8266_NODEMCU -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_NODEMCU\"" -DLED_BUILTIN=2 -DFLASHMODE_DIO -DESP8266 -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/cores/esp8266 -I/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/variants/nodemcu /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/cores/esp8266/Updater.cpp -o /home/lyonbach/Downloads/tmp/core/Updater.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/cbuf.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/WString.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_app_entry_noextra4k.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/cont_util.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/base64.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_features.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_flash_utils.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/Schedule.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_eboot_command.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_si2c.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_main.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_postmortem.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_noniso.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_phy.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_spi_utils.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_timer.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_waveform.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_sigma_delta.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_pulse.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_analog.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_digital.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_pwm.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/crc32.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/gdb_hooks.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/debug.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/flash_hal.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/heap.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/libc_replacements.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/spiffs_api.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/sqrt32.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/sntp-lwip2.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_shift.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/libb64/cencode.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/libb64/cdecode.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/time.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_cache.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/uart.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_check.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_hydrogen.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_gc.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_nucleus.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_malloc.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/abi.cpp.o
Using previously compiled file: /home/lyonbach/Downloads/tmp/core/core_esp8266_i2s.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/cont.S.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_info.c.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_integrity.c.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_local.c.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_poison.c.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/Esp-frag.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/Esp-version.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/Esp.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/FS.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/FSnoop.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/FunctionalInterrupt.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/HardwareSerial.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/IPAddress.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/MD5Builder.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/Print.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/Schedule.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/StackThunk.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/Stream.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/StreamString.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/Tone.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/Updater.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/WMath.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/WString.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/abi.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/base64.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/cbuf.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/cont_util.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_app_entry_noextra4k.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_eboot_command.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_features.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_flash_utils.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_i2s.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_main.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_noniso.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_phy.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_postmortem.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_si2c.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_sigma_delta.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_spi_utils.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_timer.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_waveform.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_analog.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_digital.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_pulse.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_pwm.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/core_esp8266_wiring_shift.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/crc32.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/debug.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/flash_hal.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/gdb_hooks.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/heap.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/libb64/cdecode.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/libb64/cencode.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/libc_replacements.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/sntp-lwip2.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_cache.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_check.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_gc.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_hydrogen.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/spiffs/spiffs_nucleus.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/spiffs_api.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/sqrt32.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/time.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/uart.cpp.o
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-ar cru /home/lyonbach/Downloads/tmp/core/core.a /home/lyonbach/Downloads/tmp/core/umm_malloc/umm_malloc.cpp.o
Linking everything together...
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-gcc -CC -E -P -DVTABLES_IN_FLASH /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/ld/eagle.app.v6.common.ld.h -o /home/lyonbach/Downloads/tmp/local.eagle.app.v6.common.ld
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-gcc -fno-exceptions -Wl,-Map -Wl,/home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.map -g -w -Os -nostdlib -Wl,--no-check-sections -u app_entry -u _printf_float -u _scanf_float -Wl,-static -L/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/lib -L/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/lib/NONOSDK22x_190703 -L/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/ld -L/home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sdk/libc/xtensa-lx106-elf/lib -Teagle.flash.4m2m.ld -Wl,--gc-sections -Wl,-wrap,system_restart_local -Wl,-wrap,spi_flash_read -o /home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.elf -Wl,--start-group /home/lyonbach/Downloads/tmp/sketch/WeihnachtsMorse.ino.cpp.o /home/lyonbach/Downloads/tmp/core/core.a -lhal -lphy -lpp -lnet80211 -llwip2-536-feat -lwpa -lcrypto -lmain -lwps -lbearssl -laxtls -lespnow -lsmartconfig -lairkiss -lwpa2 -lstdc++ -lm -lc -lgcc -Wl,--end-group -L/home/lyonbach/Downloads/tmp
/home/lyonbach/.arduino15/packages/esp8266/tools/python3/3.7.2-post1/python3 /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/elf2bin.py --eboot /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/bootloaders/eboot/eboot.elf --app /home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.elf --flash_mode dio --flash_freq 40 --flash_size 4M --path /home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin --out /home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.bin
Creating BIN file "/home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.bin" using "/home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.elf"
/home/lyonbach/.arduino15/packages/esp8266/tools/python3/3.7.2-post1/python3 /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/signing.py --mode sign --privatekey /home/lyonbach/Repositories/dcc19/Microcontrollers/arduino/WeihnachtsMorse/test/private.key --bin /home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.bin --out /home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.bin.signed --legacy /home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.bin.legacy_sig
/home/lyonbach/.arduino15/packages/esp8266/tools/python3/3.7.2-post1/python3 /home/lyonbach/.arduino15/packages/esp8266/hardware/esp8266/2.6.2/tools/sizes.py --elf /home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.elf --path /home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin
/home/lyonbach/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-4-b40a506/bin/xtensa-lx106-elf-size -A /home/lyonbach/Downloads/tmp/WeihnachtsMorse.ino.elf
Sketch uses 260552 bytes (24%) of program storage space. Maximum is 1044464 bytes.
Global variables use 26816 bytes (32%) of dynamic memory, leaving 55104 bytes for local variables. Maximum is 81920 bytes.
