#include "relacoes.h"

int avaliaReflexiva(grafo *g, lista *l) {
	int i;
	for (i = 0; i < g->nNos; i += 1)
		if (g->matriz[i][i] != 1)
			return 0;
	return 1;
}

