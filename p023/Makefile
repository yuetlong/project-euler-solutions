CC = gcc

CFLAGS = -ansi -pedantic

DBGFLAGS = -ggdb3

WARNINGS = -Wall -Werror -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
        -Wcast-align -Wstrict-overflow=5 -Wwrite-strings \
        -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum \
        -Wconversion -Wunreachable-code -Wformat=2 -Winit-self \
        -Wuninitialized -Werror-implicit-function-declaration

EXECUTABLE = p023.out

all: $(EXECUTABLE)

$(EXECUTABLE): p023.c
	$(CC) $(CFLAGS) $(DBGFLAGS) $(WARNINGS) $^ -o $@ -lm

clean:
	rm -f a.out
	rm -f *~
	rm -f *.o
	rm -f *.gch
	rm -f $(EXECUTABLE)
