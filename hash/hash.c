#include "hash.h"

char *hashString(char *string, int algo){
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    const EVP_MD *alg;

    switch (algo)
    {
    case 0:
        alg = EVP_sha256();
        break;
    case 1:
        alg = EVP_sha512();
        break;
    case 2:
        alg = EVP_md5();
        break;
    case 3:
        alg = EVP_sha1();
        break;
    default:
        alg = EVP_sha256();
        break;
    }

    EVP_DigestInit_ex(mdctx, alg, NULL);	    /* Initializes digest type */
	EVP_DigestUpdate(mdctx, string, strlen(string));	/* Add input to hash context */
	EVP_DigestFinal_ex(mdctx, md_value, &md_len);

    char *toReturn = malloc((md_len * 2) + 1); 
    for(int i = 0; i < md_len; i++){
        sprintf(toReturn + i*2, "%02x", md_value[i]);
    }
    toReturn[md_len * 2] = '\0';     
    return toReturn;
}