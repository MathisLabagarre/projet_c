#ifndef TREE_H
#define TREE_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct treeNode_t{
    struct treeNode_t *right;
    struct treeNode_t *left;
    char *value;
    int maxDepthBelow;
} treeNode;


treeNode * createNode(char *value);

void addToTheTree(treeNode *root, treeNode *node);

bool findInTree(treeNode *root, char *toFind);

void balanceTree(treeNode *root);

void printTree(treeNode *root, int gap);

void deleteNode(treeNode *node);

void deleteTree(treeNode *root);