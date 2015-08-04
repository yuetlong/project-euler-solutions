CC = gcc

CFLAGS = -lgmp -pedantic

DBGFLAGS = -ggdb3

WARNINGS = -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
        -Wcast-align -Wstrict-overflow=5 -Wwrite-strings \
        -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum \
        -Wconversion -Wunreachable-code -Wformat=2 -Winit-self \
        -Wuninitialized -Werror-implicit-function-declaration

EXECUTABLE = p025.out

OBJECTFILE = p025.o

SOURCE = p025.c

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTFILE)
	$(CC) $(CFLAGS) $(DBGFLAGS) $(WARNINGS) $^ -o $@

$(OBJECTFILE): $(SOURCE)
	$(CC) $(CFLAGS) $(DBGFLAGS) $(WARNINGS) -c $^

clean:
	rm -f a.out

	rm -f *~
	rm -f *.o
	rm -f *.gch
	rm -f $(EXECUTABLE)
