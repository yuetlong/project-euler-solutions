CC = gcc

CFLAGS = -ansi -pedantic

DBGFLAGS = -ggdb3

WARNINGS = -Wall -Wextra -Werror -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
        -Wcast-align -Wstrict-overflow=5 -Wwrite-strings \
        -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum \
        -Wconversion -Wunreachable-code -Wformat=2 -Winit-self \
        -Wuninitialized

EXECUTABLE = p030.out

OBJECTFILES = p030.o

MFLAG = -lm

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTFILES)
	$(CC) $(DBGFLAGS)  $^ $(MFLAG) -o $@

p027.o: p030.c
	$(CC) $(CFLAGS) $(DBGFLAGS) $(WARNINGS) -c $^ $(MFLAG)

clean:
	rm -f *.out
	rm -f *#
	rm -f *~
	rm -f *.o
	rm -f *.gch
	rm -f $(EXECUTABLE)
