FLAGS=-std=c99 -pedantic -Wall
BINARY=bin
OBJECTS=FilaPrioridade.o main.o

all: $(BINARY)

$(BINARY): $(OBJECTS)
	gcc -o $@ $^

%.o : %.c
	gcc $(FLAGS) -c -o $@ $^

run:
	./bin teste1.txt
clean:
	rm ./bin
	rm ./*.o