#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  /*List* local= (List*) malloc (sizeof(List));
  if (local == NULL){
    return NULL;
  }
  firstList(&local);
  nextList(&local);
  
  return local;*/
  return NULL;
}

void * firstList(List * list) {
  
    return NULL;
}

void * nextList(List * list) {
    return NULL;
}

void * lastList(List * list) {
    return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
  Node* newNode = createNode(data);
  if (list->head == NULL) {
    list->head = newNode;
    } 
  else {
     newNode->next = list->head;
    list->head = newNode;
    }
  list->current = newNode;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  if (list->current == NULL) {
    return;
  }
   Node* nuevoNodo = (Node*)malloc(sizeof(Node));
  nuevoNodo->data = data;
  nuevoNodo->next = list->current->next;
  nuevoNodo->prev = list->current;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  /*if (list->current == NULL) {
    return NULL;
    }
  Node* nodoAEliminar = list->current;
  void* data = nodoAEliminar->data;
  if (nodoAEliminar == list->head){
    list->head = nodoAEliminar;
  }*/
  return NULL
}


void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}