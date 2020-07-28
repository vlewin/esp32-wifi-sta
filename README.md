# ESP32 WiFi STA project skeleton with basic VSCode setup and esp-idf menu config for WiFi settings

## Setting up

You will need to install ESP-IDF (ESP32 SDK). You can follow the steps below or the detailed instruction on https://docs.espressif.com/projects/esp-idf/en/stable/get-started/#setup-toolchain.

1. As a first step, download ESP32 toolchain: https://docs.espressif.com/projects/esp-idf/en/stable/get-started/#setup-toolchain

2. Get ESP-IDF:
   Export the environment variable IDF_PATH:

   ```
   export IDF_PATH=$HOME/<esp-idf>
   
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
  
## Build 
1. Set path to esp-idf SDK
```bash
export IDF_PATH=$HOME/<esp-idf>
```
2. Build the example:
```bash
make -j4
```
3. Flash the example and open the serial terminal:

```
make flash && make monitor
```
