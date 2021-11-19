CC=gcc
CFLAGS=-c -Wall -Wextra -O2

SOURCES=main.c cane.c errors.c
EXECUTABLE=cane

OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o main

main.o: main.c
	$(CC) $(FLAGS) main.c

cane.o: cane.c
	$(CC) $(CFLAGS) cane.c

errors.o: errors.c
	$(CC) $(CFLAGS) errors.c

clean:
	rm -rf *.o cane