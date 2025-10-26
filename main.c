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
    
    deleteTree(node0);
}

int main(int argc, char* argv[]){

    test();

}