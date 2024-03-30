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
  List * new_list = (List *)malloc(sizeof(List));
  assert(new_list != NULL);
  new_list->head = NULL;
  new_list->tail = NULL;
  new_list->current = NULL;
  return new_list;
}


void * firstList(List * list) {

  if (list->head == NULL) {
    return NULL;
  }
  list->current = list->head;
  return list->current->data;
}


void * nextList(List * list) {
  if (list->current == NULL || list->current->next == NULL) {
    return NULL;
  }
  list->current = list->current->next;
  return list->current->data;
}


void * lastList(List * list) {
  if (list->tail == NULL) {
      return NULL;
  }
  list->current = list->tail;
  return list->current->data;
}


void * prevList(List * list) {
  if (list->current == NULL || list->current->prev == NULL) {
    return NULL;
  }
  list->current = list->current->prev;
  return list->current->data;
}


void pushFront(List * list, void * data) {
  Node * new_node = createNode(data);
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } 
  else {
    new_node->next = list->head;
    list->head->prev = new_node;
    list->head = new_node;
  }
}


void pushBack(List * list, void * data) {
  Node * new_node = createNode(data);
  if (list->tail == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } 
  else {
    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
  }
  
  //list->current = list->tail;
  //pushCurrent(list,data);
}


void pushCurrent(List * list, void * data) {
  if (list->current == NULL) {
    return;
  }
  Node * new_node = createNode(data);
  Node * next_node = list->current->next;
  
  list->current->next = new_node;
  new_node->prev = list->current;
  new_node->next = next_node;
  
  if (next_node != NULL) {
    next_node->prev = new_node;
  } 
  else {
    list->tail = new_node;
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
    return NULL;
}


void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}