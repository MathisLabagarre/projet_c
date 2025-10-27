#include <stdio.h>
#include <stdlib.h>
#include "./tree/tree.h"
#include "./file/file.h"
#include "./hash/hash.h"

//définition des constantes globales
const char *hachage[] = {"sha256", "sha512", "md5", "sha1"};

void test(){
    // treeNode * node = createNode("premiertest");
    // printf("%s\n\n", node->value);
    // deleteNode(node);

    // treeNode * node0 = createNode("1");
    // treeNode * node1 = createNode("2");
    // treeNode * node2 = createNode("3");
    // treeNode * node3 = createNode("4");
    // treeNode * node4 = createNode("5");
    // treeNode * node5 = createNode("6");
    // treeNode * node6 = createNode("7");
    // treeNode * node7 = createNode("8");

    // addToTheTree(node0, node1);
    // addToTheTree(node0, node2);
    // addToTheTree(node0, node3);
    // addToTheTree(node0, node4);
    // addToTheTree(node0, node5);
    // addToTheTree(node0, node6);
    // addToTheTree(node0, node7);
    // printTree(node0, 0);
    // printf("\n\n");

    // treeNode *newtree = balanceTree(node0);
    // newtree = balanceTree(newtree);
    // printTree(newtree, 0);
    
    // deleteTree(newtree);



    // FILE * rFile = fopen("./storage/file.txt", "r");
    // FILE * wFile = fopen("./sortie.txt", "w");
    // if(rFile && wFile){
    //     char *word;
    //     while((word = readNextLine(rFile)) != NULL){
    //         fprintf(wFile, "%s\n", t3cFormat(word, 0));
    //     }
    // }
    // else{
    //     printf("Problème\n");
    // }
    // fclose(rFile);
    // fclose(wFile);


    // //lecture du fichier T3C
    // FILE * file = fopen("./sortie.txt", "r");
    // if(file){
    //     char *clair;
    //     char *hash;
    //     while(readT3cLine(file, &clair, &hash)){
    //         if(clair != NULL && hash != NULL){
    //             printf("%s et %s\n", clair, hash);
    //         }
    //     }
    // }
    // else{
    //     printf("Problème");
    // }
}

bool Gparam(int argc, char *argv[], FILE * paramFile){
    for(int i = 0; i < argc; i++){
        printf("%s, %d\n", argv[i], i);
    }
    return true;
}

bool Lparam(int argc, char *argv[], FILE * paramFile){
    for(int i = 0; i < argc; i++){
    
    }
    return true;
}

bool GLparam(int argc, char *argv[], FILE * paramFile){
    int hashType = 0;
    FILE * outputFile;

    for(int i = 0; i < argc; i++){

        if(strcmp(argv[i], "-H") == 0){
            for(int j = 0; j < hachage; j++){
                if(argv[i + 1] != NULL || strcmp(argv[i + 1], "") != 0){
                    if(strcmp(argv[i + 1], hachage[i])){
                        hashType = j;
                        break;
                    }
                }
                
            }
        }

        if(strcmp(argv[i], "-o") == 0){
            if(argv[i + 1] != NULL || strcmp(argv[i + 1], "") != 0){
                if((outputFile = fopen(argv[i + 1], "w")) == NULL){
                    printf("Impossible d'ouvrir %s en écriture. Ouverture du fichier par défaut : ./storage/hash.txt.\n");
                    if((outputFile = fopen("./storage/hash.txt", "w")) == NULL){
                        printf("Impossible d'ouvrir un fichier en écriture.\n");
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]){
    test();

    if(argc <= 1){
        printf("Veuillez ajouter -G ou -L au lancement pour générer ou comparer des hashs.\n");
    }
    else if ((argc - 1) % 2 != 0){
        printf("Chaque mode requiert un paramètre, veuillez compléter votre requête.\n");
    }
    else{
        FILE * paramFile = fopen(argv[2], "r");
        if(paramFile == NULL){  
            printf("Chemin %s non valide.\n", argv[2]);
        }
        else{
            if(strcmp(argv[1], "-G") == 0){
                if(!Gparam(argc - 3, argv + 3, paramFile)){
                    return 0;
                }
            }
            else if(strcmp(argv[1], "-L") == 0){
                if(!Lparam(argc - 3, argv + 3, paramFile)){
                    return 0;
                }
            }
            else if(strcmp(argv[1], "-GL") == 0){
                if(!GLparam(argc - 3, argv + 3, paramFile)){
                    return 0;
                }
            }
            else{
                printf("Paramètre obligatoire non reconnu.\n");
            }
        }
    }
    printf("Fin du programme.\n");
}
/*    const char *hachage[] = {"sha256", "sha512", "md5", "sha1"};

    if(argc <= 1){
        printf("Veuillez ajouter -G ou -L au lancement pour générer ou comparer des hashs.\n");
        return 0;
    }
    else if ((argc - 1) % 2 != 0){
        printf("Chaque mode requiert un paramètre, veuillez compléter votre requête.\n");
        return 0;
    }
    else{
        FILE * fichier = NULL;
        if((fichier = fopen(argv[2], "r")) != NULL){
            printf("Début de la lecture ...\n");
        }
        else{
            printf("Le fichier %s n'existe pas. Veuillez vérifier l'emplacement du fichier.\n", argv[2]);
            return 0;
        }
        
        
        
        
        
        if(strcmp(argv[1], "-G") == 0){
            char * outputFile = malloc(100 * sizeof(char));
            int hashType = 0;
            outputFile = "./storage/hash.txt"; //sortie par défaut

            for(int i = 3; i < argc; i++){
                if(strcmp(argv[i], "-H") == 0){
                    if(strlen(argv[i + 1]) > 6){
                        printf("Choisissez un alogrithme de hachage valide SVP : sha1, sha256, sha512, md5\n");
                        return 0;
                    }
                    for(int j = 0; j < 4; j++){
                        if(strcmp(hachage[j], argv[i + 1]) == 0){
                            hashType = j;
                            break;
                        }
                    }
                }

                if(strcmp(argv[i], "-o") == 0){
                    if(strlen(argv[i + 1]) > 1000){
                        printf("Privilégiez un chemin relatif à un chemin absolu. Si ça ne suffit pas, songez à choisir un dossier de sortie plus proche de celui-ci.\n");
                        return 0;
                    }
                    strcpy(outputFile, argv[i + 1]);
                }
            }
            FILE * fichierSortie = fopen(outputFile, "w");
            
            char *word;
            while((word = readNextLine(fichier)) != NULL){
                char * ouioui = hashString(word, hashType);
                fprintf(fichierSortie, "%s\n", ouioui);
                free(ouioui);
            }
            fclose(fichierSortie);
        }






        else if(strcmp(argv[1], "-L") == 0){
            char *hash = malloc(100 * sizeof(char));
            int hashType = 0;

            bool alreadyHash = false;
            for(int i = 3; i < argc; i++){
                if(strcmp(argv[i], "-s") == 0){
                    strcpy(hash, argv[i + 1]);
                    alreadyHash = true;
                }
                else if(strcmp(argv[i], "-S") == 0){
                    strcpy(hash, argv[i + 1]);
                }
                else if(strcmp(argv[i], "-H") == 0){
                    if(strlen(argv[i + 1]) > 6){
                        printf("Choisissez un alogrithme de hachage valide SVP : sha1, sha256, sha512, md5.\n");
                        return 0;
                    }
                    for(int j = 0; j < 4; j++){
                        if(strcmp(hachage[j], argv[i + 1]) == 0){
                            hashType = j;
                            break;
                        }
                    }
                }
            }
            char * monHash;
            if(!alreadyHash){
                if(strcmp(hash, "") != 0)
                    monHash = hashString(hash, hashType);
            }
            else{
                monHash = hash;
            }
            //fin du traitement de l'entrée

            char *mot;
            if((mot = readNextLine(fichier)) == NULL){
                printf("Veuillez fournir un fichier non vide.\n");
                return 0;
            }
            treeNode *root = createNode(mot);
            int compteur = 0;
            while((mot = readNextLine(fichier)) != NULL){
                addToTheTree(root, createNode(mot));
                //root = balanceTree(root);
                compteur++;
            }

            if((monHash != NULL) && (!hash)){
                if(findInTree(root, monHash)){
                    printf("Le hash de votre mot est dans le dictionnaire !\n");
                }
                else{
                    printf("Le hash de votre mot n'est pas dans le dictionnaire.\n");
                }
            }
            
            char *request = malloc(100 * sizeof(char));
            printf("Entrez le mot à hasher : ");
            while((scanf("%s", request) == 1) && (strcmp(request, "exit") != 0)){
                char * motHash = hashString(request, hashType);
                if(findInTree(root, motHash)){
                    printf("Trouvé !\n");
                }
                else{
                    printf("Aucun hash ne correspond à votre mot dans le dictionnaire.\n");
                }
                free(motHash);
            }
            free(request);
            free(hash);
            free(monHash);
            deleteTree(root);
        }










        else if(strcmp(argv[1], "-GL") == 0){
            int hashType = 0;
            for(int i = 3; i < argc; i++){
                if(strcmp(argv[i], "-H") == 0){
                    if(argv[i + 1] != NULL){
                        for(int j = 0; j < 4; j++){
                            if(strcmp(argv[i + 1], hachage[j]) == 0){
                                hashType = i;
                                break;
                            }
                        }
                    }
                }   
            }      
            char *word;
            if((word = readNextLine(fichier)) == NULL){
                printf("Veuillez fournir un fichier non vide.\n");
                return 0;
            }
            treeNode *root = createNode(hashString(word, hashType));
            while((word = readNextLine(fichier)) != NULL){
                addToTheTree(root, createNode(hashString(word, hashType)));
            }

            char *request = malloc(100 * sizeof(char));
            printf("Entrez le mot à hasher : ");
            while((scanf("%s", request) == 1) && (strcmp(request, "exit") != 0)){
                char * hashATrouver = hashString(request, hashType);
                if(findInTree(root, hashATrouver)){
                    printf("Trouvé !\n");
                }
                else{
                    printf("Aucun hash ne correspond à votre mot dans le dictionnaire.\n");
                }
                free(hashATrouver);
            }
            printTree(root, 0);
            deleteTree(root);
        }
        else{
            printf("Argument non reconnu.\n");
            return 0;
        }
        fclose(fichier);
    }
    printf("Fin du programme.\n");
    return 0;
}

*/