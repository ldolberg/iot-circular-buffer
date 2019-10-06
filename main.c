#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct circular_buf_t Queue;

struct circular_buf_t {
    uint8_t *buffer;
    size_t head;
    size_t tail;
    size_t size;
};

void init(Queue *q, size_t size){
  q->buffer = malloc(sizeof(uint8_t) * size);  
}

void add_elem(Queue *cbuf, uint8_t data){
  if (cbuf->head == 49){
    cbuf->head = 0;
  }

  cbuf->buffer[cbuf->head] = data;
  cbuf->head += 1;
  if(cbuf->head == cbuf->tail){
    cbuf->tail += 1;
  }
  cbuf->size+=1;
}

size_t read(Queue *cbuf){
  size_t res = cbuf->buffer[cbuf->tail];
  if (cbuf->tail == 49){
    cbuf->tail = 0;
  }else{
    cbuf->tail +=1;
  }
  cbuf->size-=1;
  return res;
}

size_t average(Queue *cbuf){
  size_t val = 0;
  int n = 0;
  while(cbuf->size > 0){
    val += read(cbuf);
    n++;
  }
  return val/n;
}

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