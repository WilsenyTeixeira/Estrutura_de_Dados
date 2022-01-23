#ifndef NODE
#define NODE

typedef struct Node
{
    char *data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    int qtdNodes;
    Node *first;
} LinkedList;

#endif