#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct cell {
	void *data;
	struct cell *prox;
} celula;

typedef struct {
	celula *inicio, *fim;
	int tam;
} lista;

/**
 * Registro de um par de pontos
 */
typedef struct {
	int a;
	int b;
} par;

void listaCria(lista*);
int listaVazia(lista*);
void listaInsere(lista*, void*, unsigned int);
int listaRetornaBusca(lista*, int(*func)(void *, void*), void*);
//void* listaRetorna(lista*);
void listaRetorna(lista*, int*);
void listaRetornaSimetrico(lista*, int*);
int listaRemoveBusca(lista*, int(*func)(void*, void*), void*);
int listaBusca(lista*, int, int);
void listaPegaPar(lista*, par*);
int listaRemove(lista*, void*);
void listaFree(lista*);
int compare(void*, void*);
int compareSimetrico(void*, void*);

/**
 * Métodos relativos à inserção de items na lista
 */

void listaInsereRegistro(lista *, int, int);
void listaMostraRegistro(par*, int*);
void listaMostraRegistroSimetrico(par*, int*);
/* int comparaRegistro(void *reg) */

#endif
