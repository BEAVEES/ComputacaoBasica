/* Arquivo: main.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplo de passagem de argumentos a função main.
 * 
 * A função main deve seguir um dos seguintes protótipos:
 *	- int main() {...}
 *	- int main(void) {...}
 *	- int main(int argc, char *argv[]) {...}
 *	- int main(int argc, char **argv) {...}
 *
 * O valor de retorno "int" indica o resultado da execução. O valor zero significa 
 * que não houve erro (o mesmo que retornar EXIT_SUCCESS) durante a execução, um
 * valor diferente indica que houve erro e, preferencialmente, qual o erro 
 * (supondo que cada erro tem um valor específico de retorno).
 *
 * O argumento "argc" (de "argument count") indica quantos argumentos foram 
 * passados ao programa. O argumento "argv" (de "argument vector"), contém um 
 * vetor de strings contendo cada argumento passado, na ordem em que foi passado.
 */

#include <stdio.h> /* Funções de leitura/escrita na saída padrão. */
#include <stdlib.h> /* Definição de EXIT_FAILURE/EXIT_SUCCESS. */
#include <string.h> /* Funções para manipular strings. */

/* O exemplo usa o registro a seguir e assume que os argumentos, quando dados, 
 * são sempre na ordem definida pela estrutura. */
typedef struct {
	char nome[21];
	int idade;
	char CPF[15];
} pessoa_t;

/* Verifica se a quantidade de argumentos é válida, retornando 1 caso seja, 0 
 * caso contrário. */
char ok(int argc) {
	return (argc <= 4 ? 1 : 0); /* 3 para a estrutura, 1 para o executável. */
}

/* Exibe os argumentos na saída padrão, na mesma ordem de entrada. */
void mostra_args(int argc, char const *argv[]){
	int i = 0;
	printf("\nRecebido(s) %d argumento(s).", argc);
	for(; i < argc; i++) printf("\n\t%d = [%s]", i, argv[i]);
	printf("\n");
}

/* Processa os argumentos. Assume-se que a ordem é sempre "nome idade CPF", e que 
 * os valores fornecidos podem ser armazenados. */
void parse(int argc, char const **argv){
	pessoa_t p;

	/* Inicialização. */
	strcpy(p.nome, "SemNome");
	p.idade = -1;
	strcpy(p.CPF, "000.000.000-00");

	switch(argc) {
	/* Aproveitando o funcionamento do comando switch para atualizar os campos 
	 * do registro. */
	case 4:	strcpy(p.CPF, argv[3]);
	case 3: p.idade = atoi(argv[2]);
	case 2: strcpy(p.nome, argv[1]);
	default: break;
	}

	/* Mostra o resultado. */
	printf("\nNome: %s\nidade: %d\nCPF: %s\n",p.nome, p.idade, p.CPF);
}

int main(int argc, char const **argv) {
	if(!ok(argc)) {
		printf("\nNúmero inválido de argumentos.");
		return EXIT_FAILURE;		
	}

	mostra_args(argc, argv);
	if(argc > 1) parse(argc, argv);

	return EXIT_SUCCESS;
}