CC=cc
PROG=main.c exo1.c exo2.c menu.c
PROGEX=main.out
CFLAGS=-g -pedantic -Wall -Wnewline-eof

clean:
	-rm -r *.o *.err *.out *.dSYM
	-clear

comp:
	-$(CC) $(PROG) $(CFLAGS) -o $(PROGEX)
	-clear
	-./$(PROGEX)
