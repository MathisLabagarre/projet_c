#include <stdio.h>
#include <stdlib.h>
#include "./tree/tree.h"

void test(){
    treeNode * node = createNode("premiertest");
    printf("%s\n\n", node->value);
    deleteNode(node);

    treeNode * node0 = createNode("1");
    treeNode * node1 = createNode("2");
    treeNode * node2 = createNode("3");
    treeNode * node3 = createNode("5");
    treeNode * node4 = createNode("4");

    addToTheTree(node0, node1);
    addToTheTree(node0, node2);
    addToTheTree(node0, node3);
    addToTheTree(node0, node4);
    printTree(node0, 0);

    printf("%d\n", findInTree(node0,"7"));
    
    deleteTree(node0);
}

int main(int argc, char* argv[]){

    test();

}