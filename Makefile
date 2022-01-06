TARGET = oskb
LIBS = $(shell pkg-config --libs gtk+-3.0) -lgtk-layer-shell

CC = gcc
CFLAGS = -g -Wall -I/usr/include/gtk-layer-shell $(shell pkg-config --cflags gtk+-3.0)

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
