/* Arquivo: repeticao.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplos de laços de repetição. */

#include <stdio.h> /* escrita/leitura padrão */

/* Função principal. */
int main (){
	const int N = 10;
	int i = 0;

	printf("\nWhile\n");
	while(i < N) {
		printf("%d ", i);
		++i;
	}
	/* De novo! */
	while(i > 0) printf("%d ", --i);

	i = 0;
	int soma = 0;
	while(i <= N) {
		soma += i;
		i++;
	}
	printf("\nSoma de 0 a %d = %d", N, soma);
	
	/* De novo! */
	i = N;
	soma = 0;
	while(i) soma += i--;
	printf(" %d Soma de %d a %d.", soma, N , i);

	while(i)
		printf("\nTeste da condição no início, não deveria ter entrado nesse laço.");


	printf("\n\ndo-while\n");
	i = 0;
	do {
		printf("%d ", i++);
	} while(i < N);

	i = 0;
	soma = 0;
	do {
		soma += i;
		i++;
	} while(i <= N);
	printf("\nSoma de 0 a %d = %d", N, soma);

	do {
		i++;
		printf("\nTeste da condição ao final, executa os comandos pelo menos uma vez.");
	} while(i <= N);


	printf("\n\nfor\n");
	for(i = 0; i < N; ++i)
		printf("%d ", i);

	for(i = 0, soma = 0; i < N; ++i, soma += i);
	printf("\nSoma de 0 a %d = %d", N, soma);

	for(; i < N;)
		printf("\nTeste da condição no início, não deveria ter entrado nesse laço.");

	/* Outras formas... */
	for(i = 0; i < N; i += 5);
	for(i = N; i > 0; i -= 5);


	/* A condição de parada pode ser modificada dentro do próprio laço. */
	char deve_parar = 0;
	i = 0;
	do {
		++i;
		deve_parar = ((i%31) == 0); /* pára quando for múltiplo de 31 */

		/* Poderia ser a leitura de um dado do usuário... */
	} while (!deve_parar);

	deve_parar = 0;
	while (!deve_parar) {
		deve_parar = (((++i)%31) == 0);
		/* ... */
	}

	for(; !deve_parar; i++) {
		/* ... */
		deve_parar = !(i%31);
	}



	/* É possível indicar o fim do laço dentro do próprio laço. */
	i = 0;
	while(1) { /* Laço infinito!!! */
		/* ... */
		
		if(((++i)%31) == 0) break; /* sai quando for múltiplo de 31 */

		/* ... */		
	}

	do {
		/* ... */
		break;
	} while(1);

	for(;;) {
		/* ... */
		break;
	}
	
	return 0; /* Não houve erro. */
}