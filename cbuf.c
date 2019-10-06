
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "cbuf.h"
#define MAX_SIZE 49

void init(Queue *q, size_t size){
  q->buffer = malloc(sizeof(uint8_t) * size);  
}

void add_elem(Queue *cbuf, uint8_t data){
  if (cbuf->head == MAX_SIZE){
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
  if (cbuf->tail == MAX_SIZE){
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