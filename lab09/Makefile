FLAGS=-std=c99 -pedantic
BINARY=bin
OBJECTS=ArvoreBinaria.o Arvore_a.o
OBJECTS2=ArvoreBinaria.o testEnv.o
OBJECTS3=ArvoreBinaria.o Arvore_b.o
TEST=bin2

all: $(BINARY)
	echo 'executado'

$(BINARY): $(OBJECTS)
	gcc -o $@ $^

%.o : %.c 
	gcc $(FLAGS) -c -o $@ $^

makeexerc2: 
	gcc $(FLAGS) -c ArvoreBinaria.c -o ArvoreBinaria.o 
	gcc $(FLAGS) -c Arvore_b.c -o Arvore_b.o
	gcc $(FLAGS) -o $(BINARY) $(OBJECTS3)

exerc2test1:
	./$(BINARY) test1.txt

exerc2test2:
	./$(BINARY) test2.txt

exerc2test3:
	./$(BINARY) test3.txt

exerc2test4:
	./$(BINARY) test4.txt

test1:
	./$(BINARY) test1.txt

test2:
	./$(BINARY) test2.txt

teste:
	gcc ArvoreBinaria.c -c -o ArvoreBinaria.o
	gcc testEnv.c -c -o testEnv.o
	gcc -o $(TEST) $(OBJECTS2)

testerun:
	./$(TEST) 

clean:
	rm ./*.o
	rm bin
	
testeclean:
	rm ./*.o
	rm bin2 

cleanall:
	rm ./*.o 
	rm bin 
	rm bin2
