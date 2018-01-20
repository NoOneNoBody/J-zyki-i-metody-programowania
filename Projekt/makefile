#Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
CC = gcc  

all: main.o pong.o
	$(CC) main.o pong.o -lncursesw -Wall -pedantic -Wextra -Werror -lm -o ProjectPong.exe

main.o: main.c
	$(CC) main.c -lncursesw -Wall -pedantic -Wextra -Werror -lm -c -o main.o
	
pong.o: pong.c pong.h
	$(CC) pong.c -lncursesw -Wall -pedantic -Wextra -Werror -lm -c -o pong.o