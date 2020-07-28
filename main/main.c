/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

#include "nvs_flash.h"

// #include "esp_spi_flash.h"
// #include "esp_event.h"
#include "esp_system.h"
#include "esp_log.h"
#include "sdkconfig.h"

// NOTE: For ip4_addr_t struct
#include "lwip/sockets.h"
#include "lwip/sys.h"

#include "wlan.h"

static const char *TAG = "wlan";
static ip4_addr_t s_ip_addr;

void on_wifi_ready(ip4_addr_t ip)
{
  ESP_LOGI(TAG, "WIFI is ready: Init camera!");
  s_ip_addr = ip;
  vTaskDelay(100 / portTICK_PERIOD_MS);
}

void flash_init()
{
  esp_err_t err = nvs_flash_init();
  if (err != ESP_OK)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ESP_ERROR_CHECK(nvs_flash_init());
  }
}

void app_main()
{
  printf("Configured Wi-Fi SSID is set to %s\n", CONFIG_ESP_WIFI_SSID);
  flash_init();
  wifi_init();

  /* Print chip information */
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
         chip_info.cores,
         (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
         (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

  printf("silicon revision %d, ", chip_info.revision);

  for (int i = 30; i >= 0; i--)
  {
    printf("Restarting in %d seconds...\n", i);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  printf("Restarting now.\n");
  fflush(stdout);
  esp_restart();
}
