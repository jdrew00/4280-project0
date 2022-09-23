// Jacob Drew
// 4280 P0
// node.h
#ifndef NODE_H 
#define NODE_H

#include <string>

typedef struct node_t
{
    std::string word;
    char firstLetter;
    struct node_t *left;
    struct node_t *middle;
    struct node_t *right;

} node_t;

#endif 
