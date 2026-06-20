#include <stdio.h>
#include <stdlib.h>

#define DEFINE_NODE(type, name)\
    typedef struct name##Node name##Node;\
    typedef struct name##Node {\
        type data;\
        name##Node* next;\
        name##Node* prev;\
    } name##Node;\
    \
name##Node* name##Node##_new(type data)\
{\
    name##Node* new_node = malloc(sizeof(name##Node));\
    if (new_node == NULL) return NULL;\
    new_node->next = NULL;\
    new_node->prev = NULL;\
    new_node->data = data;\
    return new_node;\
}\
\

#define DEFINE_LIST(type, name)\
    DEFINE_NODE(type, name)\
    \
    typedef struct name##List {\
        name##Node* head;\
        name##Node* tail;\
    } name##List;\
    \
    \
name##List* name##List##_new()\
{\
    name##List* new_list = malloc(sizeof(name##List));\
    if(new_list == NULL) return NULL;\
    new_list->head = NULL;\
    new_list->tail = NULL;\
    return new_list;\
}\
\
void name##List##_addNode(name##List* list, name##Node* node)\
{\
    if (node == NULL || list == NULL) return;\
    if (list->head == NULL)\
    {\
        list->head = node;\
        list->tail = node;\
        return;\
    }\
    list->tail->next = node;\
    node->prev = list->tail;\
    list->tail = node;\
    list->tail->next = NULL;\
}\
\
void name##List##_push(name##List* list, type data)\
{\
    if (list == NULL) return;\
    name##List##_addNode(list, name##Node##_new(data));\
}\
\
void name##List##_free(name##List* list)\
{\
    if (list == NULL) return;\
    while (list->head != NULL)\
   {\
        name##Node* temp = list->head;\
        list->head = list->head->next;\
        free(temp);\
    }\
    list->tail = NULL;\
}\
\
void name##List##_popHead(name##List* list)\
{\
    if (list == NULL || list->head == NULL) return;\
    name##Node* node = list->head;\
    list->head = list->head->next;\
    free(node);\
    list->head->prev = NULL;\
}\
void name##List##_popTail(name##List* list)\
{\
    if (list == NULL || list->tail == NULL) return;\
    if (list->head == list->tail)\
    {\
        list->head = NULL;\
        list->tail = NULL;\
    }\
    name##Node* node = list->tail;\
    list->tail = list->tail->prev;\
    free(node);\
}\
\
name##Node* name##List##_find(name##List* list, type data)\
{\
    if (list == NULL || list->tail == NULL) return NULL;\
    for (name##Node* node = list->tail; node != NULL; node = node->prev)\
        if (node->data == data) return node;\
    \
    return NULL;\
}\
\
