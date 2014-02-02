/* Arquivo: arq_texto.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplos de leitura/escrita de um arquivo texto. */

#include "utils.h" /* funções auxiliares */

/* Variável global. */
const char arquivo[50] = "arq_texto.txt";

/* Mostra como escrever em um arquivo texto. */
void escrita_padrao() {
	FILE *fp = fopen(arquivo, "w+"); /* "w+" ? */
	if(!fp) {
		printf("\nNão foi possível abrir o arquivo \"%s\" para escrita.", arquivo);
		return;
	}

	char cabecalho[15] = "Capítulo 1";
	fprintf(fp, "%s\n", cabecalho);

	char texto[100] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	fprintf(fp, "%s", texto);

	cabecalho[10] = '2';
	fprintf(fp, "\n\n%s\n", cabecalho);
	
	char outro_texto[200] = "Donec a diam lectus. Sed sit amet ipsum mauris. Maecenas congue ligula ac quam viverra nec consectetur ante hendrerit. ";
	fprintf(fp, "%s", outro_texto);

	fclose(fp); /* "Tu te tornas eternamente responsável por aquilo que cativas." */
}

/* Mostra como ler de um arquivo texto. */
void leitura_padrao() {
	FILE *fp = fopen(arquivo, "r");
	if(!fp) {
		printf("\nNão foi possível abrir o arquivo \"%s\" para leitura.", arquivo);
		return;
	}

	char texto[501];

	/* Caracter por caracter: */
	while(fscanf(fp, "%c", texto) != EOF) printf("%c", texto[0]);

	/* Palavra por palavra: */
	while(fscanf(fp, "%s", texto) != EOF) printf("%s", texto);

	/* Linha por linha: */
	while(fscanf(fp, "%500[^\n]\n", texto) != EOF) printf("%s\n", texto);

	fclose(fp); /* Abriu, tem de fechar! */
}

/* Mostra como escrever em um arquivo texto, agora com tipos diferentes. */
void escrita_tipada() {
	FILE *fp = fopen(arquivo, "w+"); /* "w+" ? */
	if(!fp) {
		printf("\nNão foi possível abrir o arquivo \"%s\" para escrita.", arquivo);
		return;
	}

	int i;
	for(i = 1; i <= 10; i++)
		fprintf(fp, "Nome%d %d %.3f\n", i, 2*i, i*0.1);

	fclose(fp); /* Sempre! */
}

/* Mostra como ler de um arquivo texto, agora com tipos diferentes. */
void leitura_tipada() {
	FILE *fp = fopen(arquivo, "r");
	if(!fp) {
		printf("\nNão foi possível abrir o arquivo \"%s\" para leitura.", arquivo);
		return;
	}

	char nome[50];
	int inteiro;
	float real; 

	/* Leitura nas variávies corretas. */
	while(fscanf(fp, "%s %d %f", nome, &inteiro, &real) != EOF)
		printf("\n%s %d %f", nome, inteiro, real);
		/* A conversão de caracter para os tipos numéricos é automática! */

	fclose(fp); /* Sempre! */
}

/* Função principal. */
int main (){
	escrita_padrao();
	leitura_padrao();
	escrita_tipada();
	leitura_tipada();
	
	return EXIT_SUCCESS;
}