CC = gcc
CFLAGS = -Wall -Wextra

TARGET = main
OBJS = main.o calculate_grade.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c calculate_grade.h
	$(CC) $(CFLAGS) -c main.c

calculate_grade.o: calculate_grade.c calculate_grade.h
	$(CC) $(CFLAGS) -c calculate_grade.c

clean:
	rm -f *.o $(TARGET)
