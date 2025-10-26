#include "tree.h"


treeNode * createNode(char *value){
    treeNode * node = calloc(1, sizeof(treeNode));
    node->value = value;
    return node;
}


int greaterDepth(treeNode *node){
    if(isLeaf(node)){
        return 0;
    }
    else if(node->left != NULL && node->right != NULL){
        if(node->left->maxDepthBelow - node->right->maxDepthBelow < 0){
            return node->right->maxDepthBelow + 1;
        }
        return node->left->maxDepthBelow + 1;               //même si ils sont = on va renvoyer l'un des deux donc autant que ce soit le gauche ¯\_(ツ)_/¯
    }
    else if(node->left != NULL){
        return node->left->maxDepthBelow + 1;
    }
    else if(node->right != NULL){
        return node->right->maxDepthBelow + 1;
    }
    return -1;
}


void addToTheTree(treeNode *root, treeNode *node){
    if(root == NULL || node == NULL){
        printf("Un des paramètres est nul : addToTheTree");
    }
    else{
        if(strcmp(root->value, node->value) > 0){
            if(root->left != NULL){
                addToTheTree(root->left, node);
            }
            else{
                root->left = node;
            }
        }
        else if(strcmp(root->value, node->value) < 0){
            if(root->right != NULL){
                addToTheTree(root->right, node);
            }
            else{
                root->right = node;
            }
        }
    }
    root->maxDepthBelow = greaterDepth(root);
}



bool findInTree(treeNode *root, char *toFind){
    if(strcmp(root->value, toFind) > 0){
        if(root->left != NULL){
            if(findInTree(root->left, toFind)) return true;
        }
    }
    if(strcmp(root->value, toFind) < 0){
        if(root->right != NULL){
            if(findInTree(root->right, toFind)) return true;
        }
    }
    if(strcmp(root->value, toFind) == 0){
        return true;
    }
    return false;
}

//plus lourd à gauche
treeNode *balanceLeft(treeNode *root){
    treeNode *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->maxDepthBelow = greaterDepth(root);
    return temp;
}

//plus lourd à droite
treeNode *balanceRight(treeNode *root){
    treeNode *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->maxDepthBelow = greaterDepth(root);
    return temp;
}



treeNode *balanceTree(treeNode *root){
    printTree(root, 0);
    if(isLeaf(root)){
        return root;
    }
    else if((root->right == NULL && root->maxDepthBelow >= 2)){
        root = balanceLeft(root);
    }
    else if((root->left == NULL && root->maxDepthBelow >= 2)){ 
        root = balanceRight(root);
    }
    else if(root->left != NULL && root->right != NULL){
        if(root->left->maxDepthBelow - root->right->maxDepthBelow >= 2){
            root = balanceLeft(root);
        }
        if((root->right->maxDepthBelow - root->left->maxDepthBelow >= 2)){
            root = balanceRight(root);
        }
    }
    if(root->right != NULL){
        root->right = balanceTree(root->right);
    }
    if(root->left != NULL){
        root->left = balanceTree(root->left);
    }
    root->maxDepthBelow = greaterDepth(root);
    return root;
}


void printTree(treeNode * root, int gap){
    if(root->right != NULL){
        printTree(root->right, gap + 1);
    }
    for(int i = 0; i < gap; i++){
        printf("    ");
    }
    printf("%s, %d\n", root->value, root->maxDepthBelow);
    if(root->left != NULL){
        printTree(root->left, gap + 1);
    }

}



bool isLeaf(treeNode *node){
    if((node->right == NULL) && (node->left == NULL)){
        return true;
    }
    return false;
}



void deleteNode(treeNode *node){
    free(node);
}



void deleteTree(treeNode *root){
    if(root->right != NULL){
        deleteTree(root->right);
    }
    if(root->left != NULL){
        deleteTree(root->left);
    }
    deleteNode(root);
}