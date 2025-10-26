#include <stdio.h>
#include <stdlib.h>
#include "./tree/tree.h"
#include "./file/file.h"
#include "./hash/hash.h"

void test(){
    treeNode * node = createNode("premiertest");
    printf("%s\n\n", node->value);
    deleteNode(node);

    treeNode * node0 = createNode("1");
    treeNode * node1 = createNode("2");
    treeNode * node2 = createNode("3");
    treeNode * node3 = createNode("4");
    treeNode * node4 = createNode("5");
    treeNode * node5 = createNode("6");
    treeNode * node6 = createNode("7");
    treeNode * node7 = createNode("8");

    addToTheTree(node0, node1);
    addToTheTree(node0, node2);
    addToTheTree(node0, node3);
    addToTheTree(node0, node4);
    addToTheTree(node0, node5);
    addToTheTree(node0, node6);
    addToTheTree(node0, node7);
    printTree(node0, 0);
    printf("\n\n");

    treeNode *newtree = balanceTree(node0);
    newtree = balanceTree(newtree);
    printTree(newtree, 0);
    
    deleteTree(newtree);
}

int main(int argc, char* argv[]){
    //test();
    const char *hachage[] = {"sha256", "sha512", "md5", "sha1"};

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
                fprintf(fichierSortie, "%s\n", hashString(word, hashType));
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
            while((scanf("%s", request) == 1) && (strcmp(request, "exit") != 0)){
                if(findInTree(root, hashString(request, hashType))){
                    printf("Trouvé !\n");
                }
                else{
                    printf("Aucun hash ne correspond à votre mot dans le dictionnaire.\n");
                }
            }
            
            deleteTree(root);
        }










        else if(strcmp(argv[1], "-GL") == 0){

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