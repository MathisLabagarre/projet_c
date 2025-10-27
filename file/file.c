#include "file.h"

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

char *t3cFormat(char *clair, int hashType){
    if((clair == NULL) || (strcmp(clair, "") == 0)) return "";
    char *hash = hashString(clair, hashType);
    char *finalString = malloc((strlen(hash) + strlen(clair) + 2) * sizeof(char)); //+2 -> 1 pour le : et un pour le '\0'
    finalString = strcat(strcat(clair, ":"), hash);
    return finalString; 
}

bool writeT3C(FILE * rFile, FILE * wFile){
        if(rFile && wFile){
        char *word;
        while((word = readNextLine(rFile)) != NULL){
            fprintf(wFile, "%s\n", t3cFormat(word, 0));
        }
        return true;
    }
    else{
        printf("Fichier non ouvert : writeT3C\n");
        return false;
    }
}

bool readT3cLine(FILE * file, char **clair, char **hash){
    if(file){
        char *line = readNextLine(file);
        if(line == NULL) return false;
        int sep;
        for(int i = strlen(line) - 1; i >= 0; i--){
            if(line[i] == ':'){
                sep = i;
                break;
            }
        }
        *clair = malloc(sep * sizeof(char)); // -1 pour le séparateur et +1 pour le '\0'
        *hash = malloc(strlen(line) - sep + 1); //strlen ne prend pas en compte '\0'
        memcpy(*clair, line, sep);
        *clair = strcat(*clair, "\0");
        memcpy(*hash, line + sep + 1, strlen(line) - sep);
        return true;
    }
    else{
        printf("Fichier non ouvert : readT3cLine\n");
        return false;
    }
}