CC = gcc
CFLAGS = -Wall -Wextra

TARGET = main
OBJS = main.o random_num.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c random_num.h
	$(CC) $(CFLAGS) -c main.c

random_num.o: random_num.c random_num.h
	$(CC) $(CFLAGS) -c random_num.c

clean:
	rm -f *.o $(TARGET)
