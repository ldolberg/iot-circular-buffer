#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "cbuf.h"


int main(void) {
  printf("Hello World\n");
  Queue *cbuf = malloc(sizeof(Queue));
  init(cbuf, 50);
  printf("%p\n", cbuf);
  printf("%ld\n", cbuf->head);
  printf("%ld bytes\n", sizeof(Queue));
  add_elem(cbuf, (uint8_t) 1);
  printf("%ld\n", cbuf->head);
  add_elem(cbuf, (uint8_t) 2);
  for(size_t i = 1000; i < 1200; i++){
    add_elem(cbuf, (uint_fast16_t) i);
    //printf("%ld %ld\n", read(cbuf), read(cbuf));
  }
  printf("max %ld\n", (uint_fast16_t) 1200);
  size_t val = average(cbuf);
  printf("%ld\n", val);
  static uint8_t o[50] = {0};
  Queue q = {o, 0, 0};
  add_elem(&q, 1);
  add_elem(&q, 2);
  add_elem(&q, 3);
  printf("%ld\n", average(&q));
  return 0;

}