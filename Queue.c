#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

void insert(LinkedList *ptr, char *data);
Node *allocNode();
Node *createNode(char *data);
char *removeNode(LinkedList *ptr);
void cleanMemory(LinkedList *ptr);
void printData(LinkedList *ptr);


int main(int argc, char const *argv[]){
    LinkedList *queue = malloc(sizeof(LinkedList));
    queue->qtdNodes = 0;
    queue->first = NULL;
    
    insert(queue,"a");
    insert(queue,"b");
    insert(queue,"c");
    printf("%s \n",removeNode(queue));
    insert(queue,"d");
    insert(queue,"a");
    insert(queue,"b");
    insert(queue,"c");
    printf("%s \n",removeNode(queue));
    printf("%s \n",removeNode(queue));
    

    printData(queue);
    
    cleanMemory(queue);
    return 0;
}

Node *allocNode(){
    Node *ptr = malloc(sizeof(Node));

    return ptr;
}

Node *createNode(char *data){
    Node *ptr = allocNode();
    ptr->data = strdup(data);
    ptr->next = NULL;

    return ptr;
}

void insert(LinkedList *ptr, char *data){
    Node *ptrAux = ptr->first;
    Node *ptrNewNode = createNode(data);

    if (ptrAux){
        while (ptrAux->next){
            ptrAux = ptrAux->next;

        }
        if (ptrAux->next == NULL)
        {
            ptrAux->next = ptrNewNode;
        }

    }else {
        ptr->first = ptrNewNode;
    }
    

    ptr->qtdNodes++;
}

char *removeNode(LinkedList *ptr){
    char *data;
    Node *ptrAux = ptr->first;
    if (ptr->qtdNodes = 0)
    {
        printf("the list is empty");

    }else{
        data = ptrAux->data;
        ptr->first = ptrAux->next;
        ptr->qtdNodes--;
    }

    return data;
}

void cleanMemory(LinkedList *ptr){
    while (ptr->qtdNodes>0)
    {
        removeNode(ptr);
    }
    ptr = NULL;
}

void printData(LinkedList *ptr){
    Node *ptrAux = ptr->first;
    printf("\n");
    while (ptrAux) {
        printf(" %s ->",ptrAux->data);
        ptrAux = ptrAux->next;
    }
    printf("\n");
}