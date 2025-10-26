EXEC = main
CC = gcc
CFLAGS = -Wall -g -lcrypto
SOURCES = main.c tree/tree.c hash/hash.c file/file.c
OBJECTS = $(SOURCES:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS) $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC)

fclean: clean

.PHONY: all clean
