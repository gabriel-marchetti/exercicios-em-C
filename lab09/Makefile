all:
	gcc ArvoreBinaria.c -c ArvoreBinaria.o
	gcc Arvore_a.c -c Arvore_a.o
	gcc -o ArvoreBinaria.o Arvore_a.o main

%.c: %.o:
	gcc -c -o $@ $^
	
run teste1:
	./Arvore_a test1.txt
clean:
	rm ./*.exe 
	rm ./*.o