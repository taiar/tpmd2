#include "relacoes.h"

int avaliaReflexiva(grafo *g, lista *l) {
	int i, okFlag = 1;
	for (i = 0; i < g->nNos; i += 1)
		if (g->matriz[i][i] != 1)
		{
			listaInsereRegistro(l, i, i);
			okFlag = 0;
		}
	return okFlag;
}

