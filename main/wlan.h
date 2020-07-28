
#ifndef __WLAN_H_
#define __WLAN_H_
 
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "sdkconfig.h"

#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "esp_event_loop.h"
 
#endif


void on_wifi_ready();
void wifi_init();
esp_err_t event_handler(void *ctx, system_event_t *event);
