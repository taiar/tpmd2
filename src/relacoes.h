#include "grafo.h"
#include "lista.h"

#ifndef _RELACOES_H_
#define _RELACOES_H_

int avaliaReflexiva(grafo*, lista*);
int avaliaIrreflexiva(grafo*, lista*);
int avaliaSimetrica(grafo*, lista*);
int avaliaAssimetrica(grafo*, lista*);
int avaliaAntiSimetrica(grafo*, lista*);
int avaliaTransitiva(grafo*, lista*);
char avaliaEquivalencia(int, int, int);
char avaliaOrdemParcial(int, int, int);

#endif

