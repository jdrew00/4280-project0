//Jacob Drew
//4280 P0
//tree.h

#include <string>
#ifndef TREE_H  
#define TREE_H

void printPreorder(struct node_t *n, FILE* outputFile);     
void printPostorder(struct node_t *n, FILE* outputFile);
void printInorder(struct node_t *n, FILE* outputFile);
int tree_height(struct node_t* root);
node_t *buildTree(std::ifstream& file);
node_t *insertNode(node_t *node, std::string inputString);
node_t *createNode(std::string inputString);

#endif