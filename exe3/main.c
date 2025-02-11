#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int BTN_PIN2 = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN);
  gpio_pull_up(BTN_PIN2);
  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  
  int r = 0;
  int g = 0;

  while (true) {
    if (!gpio_get(BTN_PIN) && r%2 == 0) {
      printf("Botao 1\n");
      gpio_put(LED_PIN_R, 1);
      r++;
      while (!gpio_get(BTN_PIN)) {
      };
    }
    else if (!gpio_get(BTN_PIN) && r%2 != 0) {
      printf("Botao 1\n");
      gpio_put(LED_PIN_R, 0);
      r++;
      while (!gpio_get(BTN_PIN)) {
      };
    }
    
    if (!gpio_get(BTN_PIN2) && g%2 == 0) {
      printf("Botao 2\n");
      gpio_put(LED_PIN_G, 1);
      g++;
      while (!gpio_get(BTN_PIN2)) {
      };
    }
    else if (!gpio_get(BTN_PIN2) && g%2 != 0) {
      printf("Botao 1\n");
      gpio_put(LED_PIN_G, 0);
      g++;
      while (!gpio_get(BTN_PIN2)) {
      };
    }
    
  }
  
}
