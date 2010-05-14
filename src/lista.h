
#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct cell {
	void *data;
	struct cell *prox;
} celula;

typedef struct {
	celula *inicio, *fim;
} lista;

void listaCria(lista*);
int listaVazia(lista*);
void listaInsere(lista*, void*, unsigned int);
void* listaRetorna(lista*, int(*func)(void *, void*), void*);
int listaRemove(lista*, int(*func)(void*, void*), void*);
void listaFree(lista*);

#endif
