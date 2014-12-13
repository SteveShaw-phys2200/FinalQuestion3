CC = gcc
CFLAGS = -Wall -O0 -g -std=c99
LFLAGS = -O0 -g
LIBS =-lm

run: sum
	./sum
sum: sum.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

clean : 
	rm -f *~
	rm -f *.o
veryclean : clean
	rm -f sum
