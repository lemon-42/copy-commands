CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

.PHONY: build
build: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c

.PHONY: clean
clean:
	rm -f main
