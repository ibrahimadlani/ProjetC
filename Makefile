CC=cc
PROG=./src/main.c ./src/exo1.c ./src/exo2.c ./src/menu.c  ./src/exo3.c    ./src/exo4.c ./src/exo5.c
PROGEX=main.out
CFLAGS= -pedantic -Wall

clean:
	-rm -r *.o *.err *.out *.dSYM
	-clear

comp:
	-$(CC) $(PROG) $(CFLAGS) -o $(PROGEX)
	-./$(PROGEX)