#ifndef HASH_H
#define HASH_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

char *hashString(char *string, int algo);