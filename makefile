src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lm -Wall

main: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)
	rm -f $(obj)

.PHONY: clean
clean:
	rm -f $(obj) main
