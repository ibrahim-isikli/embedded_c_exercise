# Derleyiciyi ve Bayrakları Tanımla
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Projenin Adı (Oluşturulacak Çalıştırılabilir Dosya Adı)
TARGET = program_adi

# Kaynak Dosyalar
SRCS = main.c sensor.c

# Nesne Dosyaları (Otomatik Oluşturulur)
OBJS = $(SRCS:.c=.o)

# Tümünü Derleme Kuralı (Default Kural)
all: $(TARGET)

# Çalıştırılabilir Dosyanın Oluşturulması
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Nesne Dosyalarının Oluşturulması (Bağımlılıklar dahil)
%.o: %.c sensor.h
	$(CC) $(CFLAGS) -c $< -o $@

# Temizleme Kuralı (Derleme Dosyalarını Siler)
clean:
	rm -f $(OBJS) $(TARGET)

# Sahte Hedefler
.PHONY: all clean