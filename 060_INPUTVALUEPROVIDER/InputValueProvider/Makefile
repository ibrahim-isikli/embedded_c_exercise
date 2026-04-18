# Compiler and flags
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_IOManager \
		 -I../Abstract_IOManager/lInput/inc \
		 -I../Abstract_IOManager/IOutput/inc \
		 -Wall -Wextra -g

# Source and output files
SRC = ./build/main.c \
	  ./src/InputValueProvider.c \
	  ./src/InputValueProvider_ruInit.c \
	  ./src/InputValueProvider_ruRefresh.c \
	  ../Abstract_IOManager/lInput/src/IInput.c \
	  ../Abstract_IOManager/IOutput/src/IOutput.c

OUTPUT = ./build/main.exe

# Target
all: $(OUTPUT)

# Output file
$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC)


# Clean
clean:
	if exist build\*.exe del /Q build\*.exe