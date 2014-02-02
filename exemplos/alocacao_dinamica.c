/* Arquivo: alocacao_dinamica.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplos de alocação dinâmica de memória. */

#include "utils.h" /* funções auxiliares */

/* Mostra a utilização tradicional do comando malloc. */
int exemplo_malloc() {
	int i, N = 5;

	/* Requisição de memória. */
	int *ptr = (int *)malloc(N*sizeof(int)); 

	if(!ptr) { /* Verificar se alocação foi bem sucedida. */
		printf("\nNão foi possível alocar %ld bytes de memória.", N*sizeof(int));
		return EXIT_FAILURE;
	}

	/* Mostrar o que está na memória alocada. */
	printf("\nValores na memória %p: ", ptr);
	mostra_vetor_int(ptr, N, ",");

	/* Definir valores e mostrá-los. */
	for(i = 0; i < N; i++) ptr[i] = i + 1;
	printf("\nValores na memória %p: ", ptr);
	mostra_vetor_int(ptr, N, ",");

	/* Libera a memória. */ 
	free(ptr); 
	/* Deveria haver a instrução "ptr = NULL;", não há para mostrar o que 
	acontece. Mas deveria haver! */

	/* Mostrar o que está na memória alocada após liberar. */
	printf("\n[free(ptr)]\nValores na memória %p:", ptr);
	mostra_vetor_int(ptr, N, ",");

	/* Nova requisição de memória. */
	ptr = (int *)malloc(N*sizeof(int));
	if(!ptr) {
		printf("\nNão foi possível alocar %ld bytes de memória.", N*sizeof(int));
		return EXIT_FAILURE;
	}

	/* E mais outra requisição. */
	int *ptr2 = (int *)malloc(N*sizeof(int)); 

	if(!ptr2) { /* Verificar se alocação foi bem sucedida. */
		printf("\nNão foi possível alocar %ld bytes de memória.", N*sizeof(int));

		/* Importante! */
		/******************/
		/**/ free(ptr); /**/
		/******************/

		return EXIT_FAILURE;
	}

	/* Mostrar o que está na memória alocada. */
	printf("\nValores na memória %p: ", ptr);
	mostra_vetor_int(ptr, N, ",");

	/* Mostrar o que está na memória alocada. */
	printf("\nValores na memória %p:", ptr2);
	mostra_vetor_int(ptr2, N, ",");

	/*Ok, terminado... */
	free(ptr), ptr = NULL;  /* "Tu te tornas eternamente responsável por aquilo que cativas." */
	free(ptr2), ptr2 = NULL;
	printf("\n");

	return EXIT_SUCCESS;
}

/* Mostra a utilização tradicional do comando calloc. */
int exemplo_calloc() {
	int i, N = 5;

	/* Requisição de memória. */
	int *ptr = (int *)calloc(N,sizeof(int));

	if(!ptr) {
		printf("\nNão foi possível alocar %ld bytes de memória.", N*sizeof(int));
		return EXIT_FAILURE;
	}

	/* Mostrar o que está na memória alocada. */
	printf("\nValores na memória %p: ", ptr);
	mostra_vetor_int(ptr, N, ",");

	/* Definir valores e mostrá-los. */
	for(i = 0; i < N; i++) ptr[i] = i + 1;
	printf("\nValores na memória %p: ", ptr);
	mostra_vetor_int(ptr, N, ",");
	
	/* Libera a memória. */
	free(ptr);
	/* Deveria haver a instrução "ptr = NULL;", não há para mostrar o que 
	acontece. Mas deveria haver! */

	/* Mostrar o que está na memória alocada após liberar. */
	printf("\n[free(ptr)]\nValores na memória %p:", ptr);
	mostra_vetor_int(ptr, N, ",");

	/* Nova requisição de memória. */
	ptr = (int *)calloc(N, sizeof(int));
	if(!ptr) {
		printf("\nNão foi possível alocar %ld bytes de memória.", N*sizeof(int));
		return EXIT_FAILURE;
	}

	/* E mais outra requisição. */
	int *ptr2 = (int *)calloc(N, sizeof(int)); 

	if(!ptr2) { /* Verificar se alocação foi bem sucedida. */
		printf("\nNão foi possível alocar %ld bytes de memória.", N*sizeof(int));

		/* Importante! */
		/******************/
		/**/ free(ptr); /**/
		/******************/

		return EXIT_FAILURE;
	}

	/* Mostrar o que está na memória alocada. */
	printf("\nValores na memória %p: ", ptr);
	mostra_vetor_int(ptr, N, ",");

	/* Mostrar o que está na memória alocada. */
	printf("\nValores na memória %p:", ptr2);
	mostra_vetor_int(ptr2, N, ",");

	/*Ok, terminado... */
	free(ptr), ptr = NULL; /* Sempre! */
	free(ptr2), ptr2 = NULL; /* Sempre! */
	printf("\n");

	return EXIT_SUCCESS;
}

int testa_multiplos_malloc() {
	printf("\n Testa múltiplos malloc:");

	static const int M = 10;
	int *ptr[M];
	int i, N = 5,j;
	for(i=0;i<M;++i) {
		ptr[i] = (int *)malloc(N*sizeof(int));
		if(!ptr[i]) {
			printf("\nNão foi possível alocar %ld bytes de memória.", N*sizeof(int));
			while(--i) free(ptr[i]);
			return EXIT_FAILURE;
		}

		printf("\n%d [%p]", i, ptr[i]);
		for(j=0;j<N;++j) {
			*(ptr[i]) = N*i+j;
			printf(" %d", *(ptr[i]));
		}
	}
	for(i=0;i<M;++i) {
		free(ptr[i]);
		ptr[i] = NULL;
	}

	return EXIT_SUCCESS;
}

int main() {
	if(exemplo_malloc() != EXIT_SUCCESS)
		return EXIT_FAILURE;
	
	if(exemplo_calloc() != EXIT_SUCCESS)
		return  EXIT_FAILURE;
	
	if(testa_multiplos_malloc() != EXIT_SUCCESS)
		return  EXIT_FAILURE;

	return EXIT_SUCCESS;
}