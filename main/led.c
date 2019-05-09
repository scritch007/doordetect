#include <stdio.h>
#include <stdlib.h>

#include <freertos/FreeRTOS.h>
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_event_loop.h"
#include "driver/gpio.h"
#include "esp_system.h"

static const char *TAG = "led";

void led_init(){

    #define GPIO_OUTPUT_IO_0    2
    #define GPIO_OUTPUT_IO_1    16
    #define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_IO_0) | (1ULL<<GPIO_OUTPUT_IO_1))
    int cnt = 0;

    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    while (1) {
        ESP_LOGI(TAG, "cnt: %d\n", cnt++);
        vTaskDelay(1000 / portTICK_RATE_MS);
        esp_err_t err;
        if ((err = gpio_set_level(GPIO_OUTPUT_IO_0, cnt % 2)) && err){
            ESP_LOGE(TAG, "Failed %d", err);
        }
        if ((err = gpio_set_level(GPIO_OUTPUT_IO_1, (cnt+1) % 2 )) && err){
            ESP_LOGE(TAG, "Failed %d", err);
        }
    }
}
