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
  List* local= (List*) malloc (sizeof(List));
  if (local == NULL){
    return NULL;
  }
  local->head=NULL;
  local->tail=NULL;
  local->current=NULL;
  
  return local;
}

void * firstList(List * list) {
  if(list->head==NULL){
    return NULL;
  }
  list->current->next=list->head;
    return list->head->data;
}

void * nextList(List * list) {
  if(list->current==NULL){
    return NULL;
  }
  if(list->current->next==NULL){
    return NULL;
  }
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
  if(list->current==NULL){
    return NULL;
  }
  if(list->tail==NULL){
    return NULL;
  }
  list->current=list->tail;
    return list->tail->data;
}

void * prevList(List * list) {
  if(list->current==NULL){
    return NULL;
  }
  if(list->current->prev==NULL){
    return NULL;
  }
    list->current = list->current->prev;
    return list->current->data;
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
  list->tail = list->current;
}

void pushBack(List * list, void * data) {
  
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* newNode = createNode(data);
  if (list->head == NULL) {
    pushFront(list, list->head->data);
  }
  else{ 
    
    newNode->prev = list->current;
    list->current->next = newNode;
    list->tail = newNode;
  }
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
  if (list->current == NULL) {
    return NULL;
    }
  if (list->current->next == NULL){
    return NULL;
  }
  Node* nodoAEliminar = list->current;
  void* data = list->current->data;
  if (nodoAEliminar == list->head){
    list->head = nodoAEliminar->next;
    nodoAEliminar->next=NULL;
    list->head->prev = NULL;
  }
  if(nodoAEliminar-> next != NULL && nodoAEliminar->prev != NULL){
    nodoAEliminar->next->prev=nodoAEliminar->prev;
    nodoAEliminar->prev->next=nodoAEliminar->next;
  }
  if (nodoAEliminar == list->tail){
    list->tail = nodoAEliminar->prev;
    list->tail->next = NULL;
    nodoAEliminar->prev= NULL;
  }

  list->current = list->current->next;
  return data;
}


void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}