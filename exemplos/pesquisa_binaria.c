/* Arquivo: pesquisa_binaria.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplo de implementação de busca binária de forma recursiva. */

#include "utils.h"

/* Retorna VERDADEIRO se o número existe no vetor dado, FALSO caso contrário. O 
 * vetor deve, obrigatoriamente, estar ordenado. Argumentos:
 *     - elemento -> número a ser buscado no vetor.
 *     - ptr_v -> endereço do vetor de elementos.
 *     - tamanho_do_vetor -> tamano do vetor. */
char existe(int elemento, int *ptr_v, int tamanho_do_vetor) {
	if(!ptr_v || tamanho_do_vetor < 1) return FALSO;

	int meio = tamanho_do_vetor/2;
	if(ptr_v[meio] > elemento) return existe(elemento, ptr_v, meio);
	if(ptr_v[meio] < elemento) return existe(elemento, &(ptr_v[meio+1]), tamanho_do_vetor-meio);
	return VERDADEIRO;
}

/* Laço principal. */
int main() {
	const int TAM = 9; /* Tamanho do vetor. */
	int n = 1, v[9] = {5,7,8,10,12,16,18,22,25}; 
	
	/* printf("\n{");
	 * mostra_vetor_int(v, TAM, ","); 
	 * printf("}\n"); */

	printf("\nDigite \"0\" para terminar.\n");
	while(n) {
		leia_int("n", &n);

		if(n)
			printf(" O número [%d]%s é parte da sequencia.\n", n, (existe(n, v, TAM) ? "" : " não"));
	} 

	return 0;
}