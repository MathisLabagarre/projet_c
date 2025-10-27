#ifndef FILE_H
#define FILE_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../hash/hash.h"

char *readNextLine(FILE *file);

char *t3cFormat(char *clair, int hashType);

bool writeT3C(FILE * rFile, FILE * wFile);

bool readT3cLine(FILE * file, char **clair, char **hash);