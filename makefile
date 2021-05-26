os : os.o data.o
	gcc -o os os.o data.o

os.o : os.c data.h
	gcc -c -Wall os.c
data.o : data.c data.h
	gcc -c -Wall data.c

clean : 
	rm os *.o 
