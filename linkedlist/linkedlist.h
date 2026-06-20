#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>

typedef struct Node Node;
typedef struct LinkedList LinkdedList;

typedef struct Node {
    void* data;
    Node* next;
}Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;

    Node* (*find)(LinkedList* list, void* data);
    void (*pop)(LinkedList* list);
    void (*push)(LinkedList* list, void* data);
    void (*insert)(LinkedList* list, Node* node);
}LinkedList;

Node* findNode(LinkedList* list, void* data);
void pop(LinkedList* list);
void push(LinkedList* list, void* data);
void insertNode(LinkedList* list, Node* node);

#endif