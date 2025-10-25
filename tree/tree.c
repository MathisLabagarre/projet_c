#include "tree.h"


treeNode * createNode(char *value){
    treeNode * node = calloc(1, sizeof(treeNode));
    node->value = value;
    return node;
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



treeNode *balance(treeNode *root){

}



treeNode *balanceTree(treeNode *root){
    if(root->right != NULL && root->left != NULL)
    {
        treeNode * temp = root;
        if((root->right->value - root->left->value) > 2){
            
        }
        else if((root->left->value - root->right->value) > 2){

        }
    }
    else if(root->right != NULL && root->left == NULL){

    }
    else if(root->right == NULL && root->left != NULL){

    }
}



void printTree(treeNode * root, int gap){
    if(root->right != NULL){
        printTree(root->right, gap + 1);
    }
    for(int i = 0; i < gap; i++){
        printf("    ");
    }
    printf("%s\n", root->value);
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