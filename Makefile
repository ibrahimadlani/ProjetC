CC=cc
PROG=./src/*.c
PROGEX=main.out
CFLAGS= -pedantic -Wall -Wnewline-eof

clean:
	-rm -r *.o *.err *.out *.dSYM
	-clear

comp:
	-$(CC) $(PROG) $(CFLAGS) -o $(PROGEX)
	-./$(PROGEX)
