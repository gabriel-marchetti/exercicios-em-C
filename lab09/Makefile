FLAGS=-std=c99 -pedantic
BINARY=bin
OBJECTS=ArvoreBinaria.o Arvore_a.o

all: $(BINARY)
	echo 'executado'

$(BINARY): $(OBJECTS)
	gcc -o $@ $^

%.o : %.c 
	gcc $(FLAGS) -c -o $@ $^

test1:
	./$(BINARY) test1.txt

test2:
	./$(BINARY) test2.txt

clean:
	rm ./*.o
	rm bin
