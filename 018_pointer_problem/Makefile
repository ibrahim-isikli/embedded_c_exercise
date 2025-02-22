CC = gcc
CFLAGS = -Wall -Wextra

TARGET = main
OBJS = main.o matrix.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

clean:
	rm -f *.o $(TARGET)
