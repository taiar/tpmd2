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
	for (i = 0; i < g->nNos; i += 1) {
		for (j = 0; j < g->nNos; j += 1) {
			if (g->matriz[i][j] && g->matriz[j][i]) {
				if (i != j) {
					listaInsereRegistro(l, i, j);
					okFlag = 0;
				}
			}
		}
	}
	return okFlag;
}

