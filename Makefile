CC=cc
PROG=./src/main.c ./src/exo1.c ./src/exo2.c ./src/menu.c
PROGEX=main.out
CFLAGS= -pedantic -Wall -Wnewline-eof

clean:
	-rm -r *.o *.err *.out *.dSYM
	-clear

comp:
	-$(CC) $(PROG) $(CFLAGS) -o $(PROGEX)
	-clear
	-./$(PROGEX)
