#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if(argc < 2)
	{
		printf("Você deve fornecer o nome do arquivo de entrada como parâmetro de execução do programa");
		return EXIT_FAILURE;
	}

	FILE *entrada;
	char leituras[5];
	entrada = fopen(argv[1], "r");

	while(!feof(entrada))
	{
		fscanf(entrada, "%s", buff);
		printf("%s\n", buff);
	}

	return EXIT_SUCCESS;
}
