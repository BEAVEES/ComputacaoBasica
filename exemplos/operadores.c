/* Arquivo: operadores.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplos de utilização dos operadores. */

#include <stdio.h> /* escrita/leitura padrão */

/* Função principal. */
int main () {
	int i = 0;
	printf("Atribuição\n\ti = %d", i);
	i = -1;
	printf("\n\t\"i = -1\" -> i = %d", i);
	i = 2;
	printf("\n\t\"i = 2\" -> i = %d", i);


	printf("\n\nSoma\n\t\"i + 1\" = %d", i + 1);
	printf("\n\t\"i + 2\" = %d", i + 2);
	printf("\n\t\"i + (-1)\" = %d", i + (-1));


	printf("\n\nSubtração\n\t\"i - 1\" = %d", i - 1);
	printf("\n\t\"i - 2\" = %d", i - 2);
	printf("\n\t\"i - (-1)\" = %d", i - (-1));


	float f = 2;
	printf("\n\nMultiplicação\n\tf = %.0f", f);
	printf("\n\t\"f * 2\" = %.0f", f * 2);
	printf("\n\t\"f * 0.25\" = %.1f", f * 0.25);
	printf("\n\t\"f * (-1)\" = %.0f2", f * (-1));


	printf("\n\nDivisão\n\t\"f / 1\" = %.0f", f/1);
	printf("\n\t\"f / 4\" = %.2f", f / 4);
	printf("\n\t\"f / 0.25\" = %.2f", f / 0.25);
	printf("\n\t\"f / (-1)\" = %.02f", f / (-1));


	i = 6;
	printf("\n\nMódulo\n\ti = %d", i);
	printf("\n\t\"i %% 1\" = %d", i % 1);
	printf("\n\t\"i %% 2\" = %d", i % 2);
	printf("\n\t\"i %% 3\" = %d", i % 3);
	printf("\n\t\"i %% 4\" = %d", i % 4);
	printf("\n\t\"i %% 5\" = %d", i % 5);
	printf("\n\t\"i %% 6\" = %d", i % 6);
	printf("\n\t\"i %% 7\" = %d", i % 7);

	i = 0;
	printf("\n\nIncremento\n\ti = %d", i);
	printf("\n\t\"++i\" = %d", ++i);
	printf("\n\ti = %d", i);
	printf("\n\t\"i++\" = %d", i++);
	printf("\n\ti = %d", i);
	printf("\n\t\"++i\" = %d", ++i);
	printf("\n\ti = %d", i);


	printf("\n\nDecremento");
	printf("\n\t\"i--\" = %d", i--);
	printf("\n\ti = %d", i);
	printf("\n\t\"--i\" = %d", --i);
	printf("\n\ti = %d", i);


	/* Operadores lógicos */
	printf("\n\nOperadores Lógicos");
	const char V = 1; /* Poderia ser qualquer valor diferente de 0. E tipo int ou float... */
	const char F = 0;


	if(V) printf("\n(V) é verdadeiro.");
	else printf("\n(V) é falso.");
	if(F) printf("\n(F) é verdadeiro.");
	else printf("\n(F) é falso.");


	printf("\n\nE");
	if(V && V) printf("\n(V && V) é verdadeiro.");
	else printf("\n(V && V) é falso.");
	if(V && F) printf("\n(V && F) é verdadeiro.");
	else printf("\n(V && F) é falso.");
	if(F && V) printf("\n(F && V) é verdadeiro.");
	else printf("\n(F && V) é falso.");
	if(F && F) printf("\n(F && F) é verdadeiro.");
	else printf("\n(F && F) é falso.");


	printf("\n\nOu");
	if(V || V) printf("\n(V || V) é verdadeiro.");
	else printf("\n(V || V) é falso.");
	if(V || F) printf("\n(V || F) é verdadeiro.");
	else printf("\n(V || F) é falso.");
	if(F || V) printf("\n(F || V) é verdadeiro.");
	else printf("\n(F || V) é falso.");
	if(F || F) printf("\n(F || F) é verdadeiro.");
	else printf("\n(F || F) é falso.");


	printf("\n\nNegação");
	if(!V) printf("\n(!V) é verdadeiro.");
	else printf("\n(!V) é falso.");
	if(!F) printf("\n(!F) é verdadeiro.");
	else printf("\n(!F) é falso.");



	printf("\n\nTernário");
	i = ( V ? 1 : 2);
	printf("\nPara V, i = %d.", i);
	i = ( F ? 1 : 2);
	printf("\nPara F, i = %d.", i);
	printf("\n A condição é: %c", (V ? 'V' : 'F'));
	printf("\n A condição é: %c", (!V ? 'V' : 'F'));
	
	
	return 0; /* Não houve erro(s). */
}