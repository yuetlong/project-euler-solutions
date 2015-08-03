CC = gcc

CFLAGS = -ansi -pedantic

DBGFLAGS = -ggdb3

WARNINGS = -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
        -Wcast-align -Wstrict-overflow=5 -Wwrite-strings \
        -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum \
        -Wconversion -Wunreachable-code -Wformat=2 -Winit-self \
        -Wuninitialized -Werror-implicit-function-declaration

EXECUTABLE = p027.out

OBJECTFILES = p027.o sieve.o

MFLAG = -lm

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTFILES)
	$(CC) $(DBGFLAGS)  $^ $(MFLAG) -o $@

p027.o: p027.c
	$(CC) $(CFLAGS) $(DBGFLAGS) $(WARNINGS) -c $^ $(MFLAG)

sieve.o: sieve.c
	$(CC) $(CFLAGS) $(DBGFLAGS) $(WARNINGS) -c $^

clean:
	rm -f *.out
	rm -f *#
	rm -f *~
	rm -f *.o
	rm -f *.gch
	rm -f $(EXECUTABLE)
