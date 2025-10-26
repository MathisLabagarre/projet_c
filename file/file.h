#ifndef FILE_H
#define FILE_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeInFile(FILE *file, char *toWrite);

char *readNextLine(FILE *file);