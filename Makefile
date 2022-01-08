CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = image.o bmp_writer.o bmp_reader.o file_io.o transform.o main.o
TARGET = image-transformer

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o  $(TARGET) $(OBJFILES) $(LDFLAGS)

%.o: %.c
	$(CC) -g -O -c $<

image.o: image/image.c
	$(CC) -g -O -c $<

bmp_writer.o: bmp_util/bmp_writer.c
	$(CC) -g -O -c $<

bmp_reader.o: bmp_util/bmp_reader.c
	$(CC) -g -O -c $<

file_io.o: file_io/file_io.c
	$(CC) -g -O -c $<

transform.o: transform/transform.c
	$(CC) -g -O -c $<
clean:
	rm -f $(OBJFILES)
