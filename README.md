# ESP32 WiFi STA project skeleton with VSCode and esp-idf menu config for WiFi settings

## Configuration

Before compiling, you need to alter several settings in **menuconfig**. Make sure you save
this file, as it will be used in the `build` section to configure WiFi settings.

- Open the menuconfiguration with the command `make menuconfig`
- Scroll through each section of the menu, and make these changes:


* Serial flasher config
    * Default serial port = **/dev/tty.usbserial-<AAA>**
* WiFi Configuration
    * WiFi SSID = **YOUR SSID**
    * WiFi Password = **YOUR PASSWORD**