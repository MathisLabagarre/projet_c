#include "file.h"

void writeInFile(FILE *file, char *toWrite){
    if(file != NULL){

    }
}

char *readNextLine(FILE *file){
    char *word = malloc(1000 * sizeof(char));
    if(!word) return NULL;
    if(fscanf(file, "%s\n", word) != 1) 
    {
        free(word);
        return NULL;
    }
    char *finalWord = malloc((strlen(word) + 1) * sizeof(char));
    strcpy(finalWord, word);
    free(word);
    return finalWord;
}