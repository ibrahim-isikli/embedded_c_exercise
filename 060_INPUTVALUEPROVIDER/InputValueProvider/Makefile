# Compiler and flags
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I./Abstract_IOManager \
		 -I./Abstract_IOManager/IInput/inc \
		 -I./Abstract_IOManager/IOutput/inc \
		 -Wall -Wextra -g

# Source and output files
SRC = ./build/main.c \
	  ./src/InputValueProvider.c \
	  ./src/InputValueProvider_ruInit.c\
	  ./src/InputValueProvider_ruRefresh.c \
	  ../Abstract_IOManager/IInput/src/IInput.c \
	  ../Abstract_IOManager/IInput/src/IOutput.c

OUTPUT = ./build/main.exe

# Target
all: $(OUT)

# Output file
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)


# Clean
clean:
	if exist build\*.exe del /Q build\*.exe