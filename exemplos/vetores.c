/* Arquivo: vetores.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplos de uso de vetores. */

#include <stdio.h> /* escrita/leitura padrão */

/* Função principal. */
int main (){
	const int N = 10;
	int i = 0, v[10] = {0,1,2,3,5,7,8,16,32,64};

	for(i = 0; i < N; i++) {
		/* printf("\nDigite o elemento %d do vetor: ", i);
		scanf("%d", &(v[i])); */
		printf("\nv[%d]=%d ", i,v[i]);
	}
	
	for(i = N-1; i >=0 ; i -= 2)
		printf("\nv[%d]=%d ", i,v[i]);


	/* Soma 2 vetores. */
	int v2[10] = {1,1,2,2,3,3,4,4,5,5}, v3[10];
	for(i = 0; i < N; i++)
		v3[i] = v[i] + v2[i]; 

	/* Acha o maior elemento. */
	int maior = -1;
	while(--i) if(maior < v3[i]) maior = v3[i];
	printf("\nO maior elemento é %d.", maior);


	/* Conta tipos de números. */
	int impares = 0, pares = 0;
	for(i = 0; i < N; i++) {
		if(v[i]%2) ++impares;
		else ++pares;
	}
	printf("\nHá %d números pares e %d números ímpares.", pares, impares);


	return 0; /* Não houve erro. */
}