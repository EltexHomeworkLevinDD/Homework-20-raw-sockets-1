CFLAGS := -Wall -Wextra -g

.PHONY: all clean

all: main

main: main.o
	gcc $^ -o $@

main.o: main.c
	gcc -c $^

clean:
	rm -f main
	rm -f main.o