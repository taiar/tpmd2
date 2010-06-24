#include <stdlib.h>

#include "relacoes.h"

int avaliaReflexiva(grafo *g, lista *l) {
	int i, okFlag = 1;
	for (i = 0; i < g->nNos; i += 1)
		if (g->matriz[i][i] != 1) {
			listaInsereRegistro(l, i, i);
			okFlag = 0;
		}
	return okFlag;
}

int avaliaIrreflexiva(grafo *g, lista *l) {
	int i, okFlag = 1;
	for (i = 0; i < g->nNos; i += 1)
		if (g->matriz[i][i] != 0) {
			listaInsereRegistro(l, i, i);
			okFlag = 0;
		}
	return okFlag;
}

int avaliaSimetrica(grafo *g, lista *l) {
	int i, j, okFlag = 1;
	for (i = 0; i < g->nNos; i += 1) {
		for (j = 0; j < g->nNos; j += 1) {
			if (g->matriz[i][j])
				if (!g->matriz[j][i]) {
					listaInsereRegistro(l, i, j);
					okFlag = 0;
				}
		}
	}
	return okFlag;
}

int avaliaAntiSimetrica(grafo *g, lista *l) {
	int i, j, okFlag = 1;
	par *a = malloc(sizeof(par));
	for (i = 0; i < g->nNos; i += 1) {
		for (j = 0; j < g->nNos; j += 1) {
			if (g->matriz[i][j] && g->matriz[j][i]) {
				if (i != j) {
					a->a = i;
					a->b = j;
					if (!listaRetornaBusca(l, compareSimetrico, (void *) a)) {
						listaInsereRegistro(l, i, j);
						okFlag = 0;
					}
				}
			}
		}
	}
	free(a);
	return okFlag;
}

int avaliaAssimetrica(grafo *g, lista *l) {
	int i, j, okFlag = 1;
	for (i = 0; i < g->nNos; i += 1) {
		for (j = 0; j < g->nNos; j += 1) {
			if (g->matriz[i][j] == 1) {
				if (g->matriz[j][i] == 1)
					okFlag = 0;
			}
		}
	}
	return okFlag;
}

int avaliaTransitiva(grafo *g, lista *l, lista *s) {
	int i, j, k, okFlag = 1;
	par *a = malloc(sizeof(par));
	for (i = 0; i < g->nNos; i += 1) {
		for (j = 0; j < g->nNos; j += 1) {
			for (k = 0; k < g->nNos; k += 1) {
				if (g->matriz[i][j] == 1) {
					if (g->matriz[j][k] == 1) {
						if (g->matriz[i][k] != 1) {
							okFlag = 0;
							a->a = i;
							a->b = k;
							if (!listaRetornaBusca(s, compare, (void *) a)) {
								listaInsereRegistro(l, i, k);
								listaInsereRegistro(s, i, k);
							}
						}
					}
				}
			}
		}
	}
	free(a);
	return okFlag;
}

void pegaParesIntransitivos(grafo *g, lista *l, lista *s)
{
  int i, j, k, okFlag = 1;
	par *a = malloc(sizeof(par));
	for (i = 0; i < g->nNos; i += 1) {
		for (j = 0; j < g->nNos; j += 1) {
			for (k = 0; k < g->nNos; k += 1) {
				if (g->matriz[i][j] == 1) {
					if (g->matriz[j][k] == 1) {
						if (g->matriz[i][k] != 1) {
							okFlag = 0;
							a->a = i;
							a->b = k;
							if (!listaRetornaBusca(s, compare, (void *) a)) {
								listaInsereRegistro(l, i, k);
								listaInsereRegistro(s, i, k);
							}
						}
					}
				}
			}
		}
	}
	free(a);
}

void avaliaFechoTransitivo(grafo g, lista *guardaFecho)
{
  lista bufferFecho;
  par p;

  listaCria(&bufferFecho);
  pegaParesIntransitivos(&g, guardaFecho, &bufferFecho);
  
  while(bufferFecho.tam > 1)
  {
    printf("rerere\n");
    listaPegaPar(&bufferFecho, &p);
    g.matriz[p.a][p.b] = 1;
    pegaParesIntransitivos(&g, guardaFecho, &bufferFecho);
  }
}

char avaliaEquivalencia(int ref, int sim, int trans) {
	if (ref && sim && trans)
		return 'V';
	return 'F';
}
char avaliaOrdemParcial(int ref, int antiSim, int trans) {
	if (ref && antiSim && trans)
		return 'V';
	return 'F';
}

