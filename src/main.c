#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"
#include "lista.h"
#include "relacoes.h"

int encontraElemento(int*, int, int);

int main(int argc, char **argv) {
	if (argc < 2) {
		printf(
				"Você deve fornecer o nome do arquivo de entrada como parâmetro de execução do programa");
		return EXIT_FAILURE;
	}

	FILE *entrada;
	char leituras[5], leituras2[5];

	int nElementos, e1, e2;
	int i, j, k;
	int reflexiva, irreflexiva, simetrica, assimetrica, antiSimetrica,
			transitiva, equivalencia, ordemParcial;
	int *elementos;
	grafo relacoes;
	lista pares;

	entrada = fopen(argv[1], "r");

	// lê o número de elementos do conjunto
	fscanf(entrada, "%s", leituras);
	nElementos = atoi(leituras);

	// aloca o vetor de elementos
	elementos = malloc(sizeof(int) * nElementos);

	// adiciona elementos do conjunto no vetor de conjuntos
	for (i = 0; i < nElementos; i += 1) {
		fscanf(entrada, "%s", leituras);
		elementos[i] = atoi(leituras);
	}

	// inicia o grafo das relações
	grafoInicia(nElementos, &relacoes);

	// adiciona relações dos elementos no grafo de relações
	do{
		fscanf(entrada, "%s %s\n", leituras, leituras2);
		e1 = atoi(leituras);
		e2 = atoi(leituras2);
		grafoInsereAresta(encontraElemento(elementos, nElementos, e1),
				encontraElemento(elementos, nElementos, e2), 1, &relacoes);
	} while(!feof(entrada));

	fclose(entrada);

	grafoImprime(&relacoes);

	listaCria(&pares);
	// interpretação e classificação das relações no grafo
	reflexiva = avaliaReflexiva(&relacoes, &pares);
	if (!reflexiva) {
		listaRetorna(&pares, elementos);
	}

	// libera meméria
	free(elementos);

	return EXIT_SUCCESS;
}

int encontraElemento(int *v, int tam, int elem) {
	int i;
	for (i = 0; i < tam; i += 1)
		if (v[i] == elem)
			return i;
	return -1;

}
