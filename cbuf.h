#ifndef CBUF_H_   /* Include guard */
#define CBUF_H_

typedef struct circular_buf_t Queue;

struct circular_buf_t {
    uint8_t *buffer;
    size_t head;
    size_t tail;
    size_t size;
};

void init(Queue *q, size_t size);

void add_elem(Queue *cbuf, uint8_t data);


size_t read(Queue *cbuf);

size_t average(Queue *cbuf);

#endif // CBUF_H_