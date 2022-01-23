#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

void push(LinkedList *ptr, char *data);
Node *allocNode();
Node *createNode(char *data);
char *pop(LinkedList *ptr);
void cleanMemory(LinkedList *ptr);
void printData(LinkedList *ptr);


int main(int argc, char const *argv[]){
    LinkedList *queue = malloc(sizeof(LinkedList));
    queue->qtdNodes = 0;
    queue->first = NULL;
    
    push(queue,"a");
    push(queue,"b");
    push(queue,"c");
    printf("%s \n",pop(queue));
    push(queue,"d");
    push(queue,"a");
    push(queue,"b");
    push(queue,"c");
    

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

void push(LinkedList *ptr, char *data){
    Node *ptrAux = ptr->first;
    Node *ptrPrev;
    Node *ptrNewNode = createNode(data);
    if (ptrAux){
        int i = 0;
        while (ptrAux->next)
        {
            ptrAux = ptrAux->next;
        }
        ptrAux->next = ptrNewNode; 
           
    }else {
        ptr->first = ptrNewNode;
    }
    

    ptr->qtdNodes++;
}

char *pop(LinkedList *ptr){
    char *data;
    Node *ptrAux = ptr->first;
    Node *ptrPrev = ptrAux;
    if (ptr->qtdNodes = 0)
    {
        printf("the list is empty");

    }else{
        while (ptrAux->next){
            ptrPrev = ptrAux;
            ptrAux = ptrAux->next;
        }
        ptrPrev->next = NULL;
        data = ptrAux->data;
        free(ptrAux);
        ptr->qtdNodes--;
    }

    return data;
}

void cleanMemory(LinkedList *ptr){
    while (ptr->qtdNodes>0)
    {
        pop(ptr);
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