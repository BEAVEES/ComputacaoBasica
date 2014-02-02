/* Arquivo: arq_binario.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplos de leitura/escrita de um arquivo texto. */

#include "utils.h" /* funções auxiliares */

/* Variável global. */
const char arquivo[50] = "arq_binario.bin";

/* Mostra como escrever em um arquivo texto. */
void escrita_padrao() {
	FILE *fp = fopen(arquivo, "wb+"); /* "wb+" ? */
	if(!fp) {
		printf("\nNão foi possível abrir o arquivo \"%s\" para escrita.", arquivo);
		return;
	}

	char cabecalho[15] = "Capítulo 1";
	fwrite(cabecalho, sizeof(cabecalho), 1, fp); /* Esta forma é "correta"... */

	char texto[100] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	fwrite(texto, sizeof(char), 100, fp); /* Esta é a forma "mais" correta! */

	int vetor[50], i;
	for(i=0; i < 50; i++) vetor[i] = i*i;
	fwrite(vetor, sizeof(int), 50, fp);

	fclose(fp); /* "Tu te tornas eternamente responsável por aquilo que cativas." */
}

/* Mostra como ler de um arquivo texto. */
void leitura_padrao() {
	FILE *fp = fopen(arquivo, "rb");
	if(!fp) {
		printf("\nNão foi possível abrir o arquivo \"%s\" para leitura.", arquivo);
		return;
	}

	char cabecalho[15];
	fread(cabecalho, sizeof(cabecalho), 1, fp); /* Esta forma é "correta"... */
	printf("\nCabeçalho: %s", cabecalho);

	char texto[100] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	fread(texto, sizeof(char), 100, fp); /* Esta é a forma "mais" correta! */
	printf("\nTexto: %s", texto);

	int vetor[50];
	fread(vetor, sizeof(int), 50, fp);
	printf("\nVetor: ");
	mostra_vetor_int(vetor, 50, ",");

	fclose(fp); /* Abriu, tem de fechar! */
}


/* Função principal. */
int main (){
	escrita_padrao();
	leitura_padrao();
	
	return EXIT_SUCCESS;
}