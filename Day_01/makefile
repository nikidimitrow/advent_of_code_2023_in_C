default: main.o
	gcc main.o -o out

clean:
	rm -r *.o out

main.o: main.c
	gcc -c -o main.o main.c -O2 -Wall

run:
	gcc main.o -o out
	./out