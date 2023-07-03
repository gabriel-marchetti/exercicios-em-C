FLAGS=-std=c99 -pedantic -Wall
CC=gcc
OBJECTS=Graos.o ArvoreBinaria.o 

all: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o programa

ArvoreBinaria.o : ArvoreBinaria.c 
	$(CC) $(FLAGS) -c ArvoreBinaria.c -o ArvoreBinaria.o

Graos.o : Graos.c
	$(CC) $(FLAGS) -c Graos.c -o Graos.o 

clean:
	rm -f $(OBJECTS) programa
