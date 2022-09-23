// Jacob Drew
// 4280 P0
// tree.cpp

#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "node.h"
#include "tree.h"
using namespace std;

// https://www.cprogramming.com/tutorial/lesson18.html
// build a tree and insert the node
// declare a root node
struct node_t *root;

node_t *buildTree(std::ifstream &file)
{
    string inputString;
    node_t *root = NULL;

    while (file >> inputString)
    {
        root = insertNode(root, inputString);
    }

    return root;
}

node_t *insertNode(node_t *node, string inputString)
{
    if (node == NULL)
    {
        node = createNode(inputString);
    }
    else if (node->word[0] > inputString[0])
    {
        node->left = insertNode(node->left, inputString);
    }
    else if (node->word[0] < inputString[0])
    {
        node->right = insertNode(node->right, inputString);
    }
    else if (node->word[0] == inputString[0])
    {
        node->middle = insertNode(node->middle, inputString);
    }

    return node;
}

node_t *createNode(string inputString)
{
    node_t *node = NULL;
    node = new node_t;
    node->word = inputString;
    node->firstLetter = inputString[0];
    node->left = NULL;
    node->middle = NULL;
    node->right = NULL;
    return node;
}

// traversals:
//  based on https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

// preorder traversal
// takes in root node and prints traversal
void printPreorder(struct node_t *n, FILE *outputFile)
{
    if (n != NULL)
    {
        fprintf(outputFile, "%s %c %s %s \n", string(tree_height(n) * 2, ' ').c_str(), n->firstLetter, ":", n->word.c_str());
        printPreorder(n->left, outputFile);
        printPreorder(n->middle, outputFile);
        printPreorder(n->right, outputFile);
    }
}

// postorder traversal
// takes in root node and prints traversal
void printPostorder(struct node_t *n, FILE *outputFile)
{
    if (n != NULL)
    {
        printPostorder(n->left, outputFile);
        printPostorder(n->middle, outputFile);
        printPostorder(n->right, outputFile);
        fprintf(outputFile, "%s %c %s %s \n", string(tree_height(n) * 2, ' ').c_str(), n->firstLetter, ":", n->word.c_str());
    }
}

// inorder traversal
// takes in root node and prints traversal
void printInorder(struct node_t *n, FILE *outputFile)
{
    // fprintf(outputFile, "tree");

    if (n != NULL)
    {

        printInorder(n->left, outputFile);
        fprintf(outputFile, "%s %c %s %s \n", string(tree_height(n) * 2, ' ').c_str(), n->firstLetter, ":", n->word.c_str());
        printInorder(n->middle, outputFile);
        printInorder(n->right, outputFile);
    }
}

// Find height of a tree, defined by the root node
// https://www.journaldev.com/34979/height-of-a-binary-tree-in-c-plus-plus
int tree_height(struct node_t *root)
{
    // Get the height of the tree
    if (!root)
        return 0;
    else
    {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int middle_height = tree_height(root->middle);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
        {
            if (left_height >= middle_height)
            {
                return left_height + 1;
            }
            else
            {
                return middle_height + 1;
            }
        }

        else
        {
            if (right_height >= middle_height)
            {
                return right_height + 1;
            }
            else
            {
                return middle_height + 1;
            }
        }
    }
}