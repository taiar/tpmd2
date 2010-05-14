#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void listaCria(lista *l)
{
  l->inicio = (celula *) malloc(sizeof(celula));
  l->fim = l->inicio;
  l->fim->prox = NULL;
  }

int listaVazia(lista *l)
{
  return l->inicio == l->fim;
}

void listaInsere(lista *l, void *data, unsigned int size)
{
  l->fim->prox = (celula *) malloc(sizeof(celula));
  l->fim = l->fim->prox;
  l->fim->data = malloc(size);
  memcpy(l->fim->data, data, size);
  l->fim->prox = NULL;
}

void* listaRetorna(lista *l, int (*func)(void *, void *), void *param)
{
  celula *p;
 
  p = l->inicio->prox;
  while(p != NULL){
    if (func(p->data, param))
      return p->data;
    p = p->prox;
  }
  return NULL;
}

int listaRemove(lista *l, int (*func)(void *, void *), void *param)
{
  celula *p, *aux;
 
  p = l->inicio;
  while(p->prox != NULL){
    if (func(p->prox->data, param)){
      aux = p->prox;
      p->prox = aux->prox;
 
      if (aux == l->fim)
        l->fim = p;
 
      free(aux->data);
      free(aux);
      return 1;
    }
    p = p->prox;
  }
  return 0;
}

void listaFree(lista *l)
{
  celula *aux;
  while(l->inicio->prox != NULL){
    aux = l->inicio->prox;
    l->inicio->prox = aux->prox;
    free(aux->data);
    free(aux);
  }
  free(l->inicio);
}
