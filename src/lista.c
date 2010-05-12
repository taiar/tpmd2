#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void createList(TList *l)
{
  l->first = (TCell *) malloc(sizeof(TCell));
  l->last = l->first;
  l->last->next = NULL;
  }

int isEmpty(TList *l)
{
  return l->first == l->last;
}

void insertCell(TList *l, void *data, unsigned int size)
{
  l->last->next = (TCell *) malloc(sizeof(TCell));
  l->last = l->last->next;
  l->last->data = malloc(size);
  memcpy(l->last->data, data, size);
  l->last->next = NULL;
}

void* retrieveData(TList *l, int (*func)(void *, void *), void *param)
{
  TCell *p;
 
  p = l->first->next;
  while(p != NULL){
    if (func(p->data, param))
      return p->data;
    p = p->next;
  }
  return NULL;
}

int removeCell(TList *l, int (*func)(void *, void *), void *param)
{
  TCell *p, *aux;
 
  p = l->first;
  while(p->next != NULL){
    if (func(p->next->data, param)){
      aux = p->next;
      p->next = aux->next;
 
      if (aux == l->last)
        l->last = p;
 
      free(aux->data);
      free(aux);
      return 1;
    }
    p = p->next;
  }
  return 0;
}

void freeList(TList *l)
{
  TCell *aux;
  while(l->first->next != NULL){
    aux = l->first->next;
    l->first->next = aux->next;
    free(aux->data);
    free(aux);
  }
  free(l->first);
}
