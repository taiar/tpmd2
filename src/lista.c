#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void listaCria(lista *l) {
	l->inicio = (celula *) malloc(sizeof(celula));
	l->fim = l->inicio;
	l->fim->prox = NULL;
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
}

// atenção para a passagem de função como parâmetro!!
void* listaRetornaBusca(lista *l, int(*func)(void *, void *), void *param) {
	celula *p;

	p = l->inicio->prox;
	while (p != NULL) {
		if (func(p->data, param))
			return p->data;
		p = p->prox;
	}
	return NULL;
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

	p = l->inicio->prox;
	while (p != NULL) {
		l->inicio->prox = p->prox;
		aux = p;
		listaMostraRegistro(aux->data, v);
		free(aux);
		p = p->prox;
	}
	free(l->inicio);
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

