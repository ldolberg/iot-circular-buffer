src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lm -Wall

main: $(obj)
	mkdir -p bin
	$(CC) -o bin/$@ $^ $(LDFLAGS)
	rm -f $(obj)

.PHONY: clean
clean:
	rm -f $(obj) main
