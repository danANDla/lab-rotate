CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = image.o bmp_writer.o bmp_reader.o file_io.o main.o
TARGET = bmp_rotator

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o  $(TARGET) $(OBJFILES) $(LDFLAGS)

%.o: %.c
	$(CC) -g -O -c $<

clean:
	rm -f $(OBJFILES) 
