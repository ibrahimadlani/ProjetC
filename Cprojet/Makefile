CC=cc
PROG=main.c
PROGEX=main.out
CFLAGS=-g -pedantic -Wall

clean:
	-rm -r *.o *.err *.out *.dSYM
	-clear

comp:
	-$(CC) $(CFLAGS) $(PROG) -o $(PROGEX)
	-clear
	-./$(PROGEX)
