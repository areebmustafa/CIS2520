

CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g -Iinclude -c -o


main:
	
	$(CC) $(CFLAGS) bin/SinglyLinkedListAPI.o src/SinglyLinkedListAPI.c
	$(CC) $(CFLAGS) bin/main.o src/main.c
	$(CC) bin/main.o bin/SinglyLinkedListAPI.o -o bin/runMe
clean:
	rm bin/*.o bin/runMe