#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"


void insert(LinkedList *ptr, char *data, int index);
Node *allocNode();
Node *createNode(char *data);
void delete(LinkedList *ptr,int index);
void cleanMemory(LinkedList *ptr);
void printData(LinkedList *ptr);



int main(int argc, char const *argv[]){

    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    linkedlist->qtdNodes = 0;
    linkedlist->first = NULL;

    insert(linkedlist,"a",0);
    insert(linkedlist,"b",1);
    insert(linkedlist,"c",2);
    insert(linkedlist,"d",3);

    insert(linkedlist,"new C",2);

    printData(linkedlist);
    
    cleanMemory(linkedlist);
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

void insert(LinkedList *ptr, char *data, int index){
    Node *ptrAux = ptr->first;
    Node *ptrPrev;
    Node *ptrNewNode = createNode(data);

    if (index > ptr->qtdNodes){
        printf("The element with this index, dosen't exist!");

    }
    else if (index > 0){
        while (index > 0){
            ptrPrev = ptrAux;
            ptrAux = ptrAux->next;
            index--;
        }
        
        ptrPrev->next = ptrNewNode;
        ptrNewNode->next = ptrAux;
        ptr->qtdNodes++;

    }else {
        if (ptrAux)
        {
            ptrNewNode->next = ptrAux;
        }

        ptr->first = ptrNewNode;
        ptr->qtdNodes++;
    }
}

void delete(LinkedList *ptr,int index){
    Node *ptrAux = ptr->first;
    Node *ptrPrev = ptrAux;
    if (ptr->qtdNodes = 0)
    {
        printf("the list is empty");

    }else if (index > ptr->qtdNodes){
        printf("The element with this index, dosen't exist!");

    }else if(index = 0){
        ptr->first = ptr->first->next;
        free(ptrAux);
        ptr->qtdNodes--;

    }else{
        while (index>0){
            ptrPrev = ptrAux;
            ptrAux = ptrAux->next;
            index--;
        }
        ptrPrev->next = ptrAux->next;
        free(ptrAux);
        ptr->qtdNodes--;

    }
}

void cleanMemory(LinkedList *ptr){
    while (ptr->qtdNodes>0)
    {
        delete(ptr,0);
    }
    ptr = NULL;
}

void printData(LinkedList *ptr){
    Node *ptrAux = ptr->first;
    printf("\n");
    while (ptrAux) {
        printf(" %s ->",ptrAux->data);
        //gets(ptrAux->data);
        ptrAux = ptrAux->next;
    }
    printf("\n");
}