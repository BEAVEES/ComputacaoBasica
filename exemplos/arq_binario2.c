/** @file binarios.c
 * Exemplos de leitura/escrita em arquivo binário.
 *
 * @author Guilherme N. Ramos (gnramos@unb.br)
 */

 #include "utils.h"

/** Tamanho do vetor. */
const int N = 5;

int main (){
	int v1[N] = {0,1,2,3,4};
	char arquivo[50] = "arquivo.txt";

	//printf("\n sizeof(int) = %ld, sizeof(v) = %ld", sizeof(int), sizeof(v));

	FILE *fp = abre_arquivo(arquivo, "r+b");
	if (!fp) fp = abre_arquivo(arquivo, "wb");
	if (!fp) return EXIT_FAILURE;

	/* Escrever v1 no arquivo */
	fwrite(v1, sizeof(v1), 1, fp); // Esta forma é "correta"...
	fclose(fp);
	printf("\nv1=");
	mostra_vetor_int(v1, N, ",");

	/* Ler o arquivo e escrever em v2 */
	int v2[10];
	fp = abre_arquivo(arquivo, "rb");
	fread(v2, sizeof(int), N, fp);  // Esta é a forma "mais" correta!
	fclose(fp);
	printf("\nv2=");
	mostra_vetor_int(v2, 2*N, ",");

	/* Ler o arquivo e escrever na segunda metade de v2 */
	fp = abre_arquivo(arquivo, "rb");
	fread(&(v2[N]), N, sizeof(int), fp); // Funciona, mas não serve...
	fclose(fp);
	printf("\nv2=");
	mostra_vetor_int(v2, 2*N, ",");

	/* Ler o arquivo e escrever em posição arbitrária de v2 */
	fp = abre_arquivo(arquivo, "rb");
	fread(&(v2[2]), 1, sizeof(v1), fp);  // Funciona, mas não serve...
	fclose(fp);
	printf("\nv2=");
	mostra_vetor_int(v2, 2*N, ",");

	printf("\n");
	
	return EXIT_SUCCESS;
}