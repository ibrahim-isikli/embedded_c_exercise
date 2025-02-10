CC = gcc
CFLAGS = -Wall -Wextra

TARGET = main
OBJS = main.o numbers.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c numbers.h
	$(CC) $(CFLAGS) -c main.c

numbers.o: numbers.c numbers.h
	$(CC) $(CFLAGS) -c numbers.c

clean:
	rm -f *.o $(TARGET)
