CC=cc
PROG=./src/*.c
PROGEX=main.out
CFLAGS= -pedantic -Wall 

clean:
	-rm -r *.o *.err *.out *.dSYM
	-clear

comp:
	-$(CC) $(PROG) $(CFLAGS) -o $(PROGEX)
	-./$(PROGEX)
