#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void listaCria(lista *l) {
	l->inicio = (celula *) malloc(sizeof(celula));
	l->fim = l->inicio;
	l->fim->prox = NULL;
	l->tam = 0;
}

int listaVazia(lista *l) {
	return l->inicio == l->fim;
}

void listaInsere(lista *l, void *data, unsigned int size) {
	l->fim->prox = (celula *) malloc(sizeof(celula));
	l->fim = l->fim->prox;
	l->fim->data = malloc(size);
	memcpy(l->fim->data, data, size);
	l->fim->prox = NULL;
	l->tam += 1;
}

// atenção para a passagem de função como parâmetro!!
int listaRetornaBusca(lista *l, int(*func)(void *, void *), void *param) {
	celula *p;

	p = l->inicio->prox;
	while (p != NULL) {
		if (func(p->data, param))
			return 1;
		p = p->prox;
	}
	return 0;
}

/* void* listaRetorna(lista *l) {
 celula *p, *aux;

 p = l->inicio->prox;
 if (p != NULL) {
 l->inicio->prox = p->prox;
 aux = p;
 return p->data;
 }
 return NULL;
 }*/

void listaRetorna(lista *l, int *v) {
	celula *p, *aux;

	p = l->inicio;
	while (p->prox != NULL) {
		l->inicio->prox = p->prox;
		aux = p->prox;
		p->prox = aux->prox;

		listaMostraRegistro(aux->data, v);

		if (aux == l->fim)
			l->fim = p;
		free(aux->data);
		free(aux);
	}
	l->tam = 0;
}

void listaRetornaSimetrico(lista *l, int *v) {
	celula *p, *aux, *aux2, *aux3;

	p = l->inicio;
	while (p->prox != NULL) {
		l->inicio->prox = p->prox;
		aux = p->prox;
		p->prox = aux->prox;

		listaMostraRegistroSimetrico(aux->data, v);
		//remove registro simetrico da lista
		//TODO: remover registros simetricos

		if (aux == l->fim)
			l->fim = p;
		free(aux->data);
		free(aux);
	}
	l->tam = 0;
}

int listaRemoveBusca(lista *l, int(*func)(void *, void *), void *param) {
	celula *p, *aux;

	p = l->inicio;
	while (p->prox != NULL) {
		if (func(p->prox->data, param)) {
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

void listaFree(lista *l) {
	celula *aux;
	while (l->inicio->prox != NULL) {
		aux = l->inicio->prox;
		l->inicio->prox = aux->prox;
		free(aux->data);
		free(aux);
	}
	free(l->inicio);
}

int compareSimetrico(void *x, void *y) {
   if (((par*)x)->a == ((par*)y)->b && ((par*)x)->b == ((par*)y)->a)
     return 1;
   return 0;
}   


/**
 * Métodos relativos à inserção de items na lista
 */
void listaInsereRegistro(lista *l, int a, int b) {
	par p;

	p.a = a;
	p.b = b;
	listaInsere(l, (void *) &p, sizeof(par));
}

void listaMostraRegistro(par *p, int *v) {
	printf("(%d, %d); ", v[p->a], v[p->b]);
}

void listaMostraRegistroSimetrico(par *p, int *v) {
	printf("(%d, %d) e (%d, %d); ", v[p->a], v[p->b], v[p->b], v[p->a]);
}
