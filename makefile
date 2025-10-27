EXEC = main
CC = gcc
CFLAGS = -Wall -g -lcrypto
SOURCES = main.c tree/tree.c hash/hash.c file/file.c

all: $(EXEC)

$(EXEC): $(SOURCES)
	$(CC) -o $(EXEC) $(SOURCES) $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(EXEC)

fclean: clean

.PHONY: all clean
