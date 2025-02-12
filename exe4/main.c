#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LEDRED = 5;
const int LEDPUR = 8;
const int LEDBLU = 11;
const int LEDYEL = 15;
const int BTN_PIN = 28;

int main() {
  stdio_init_all();

  gpio_init(LEDRED);
  gpio_init(LEDPUR);
  gpio_init(LEDBLU);
  gpio_init(LEDYEL);
  gpio_init(BTN_PIN);
  gpio_set_dir(LEDRED, GPIO_OUT);
  gpio_set_dir(LEDPUR, GPIO_OUT);
  gpio_set_dir(LEDBLU, GPIO_OUT);
  gpio_set_dir(LEDYEL, GPIO_OUT);
  gpio_pull_up(BTN_PIN);

  
  while (true) {
    if (!gpio_get(BTN_PIN)) {
      printf("Botao 1\n");
      gpio_put(LEDRED, 1);
      sleep_ms(300);
      gpio_put(LEDRED, 0);
      gpio_put(LEDPUR, 1);
      sleep_ms(300);
      gpio_put(LEDPUR, 0);
      gpio_put(LEDBLU, 1);
      sleep_ms(300);
      gpio_put(LEDBLU, 0);
      gpio_put(LEDYEL, 1);
      sleep_ms(300);
      gpio_put(LEDYEL, 0);
      while (!gpio_get(BTN_PIN)) {
      };
      
    }
    
  }
}
