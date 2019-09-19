.PHONY:clean

process_create:process_create.o
	gcc -o process_create process_create.o
process_create.o:process_create.c
	gcc -o process_create.o -c process_create.c

clean:
	rm -f process_create.o process_create

