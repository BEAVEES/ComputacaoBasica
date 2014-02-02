/* Arquivo: registro.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplos de uso de registros. */

#include <string.h>
#include "utils.h"

/* Registro para armazenar uma data. */
typedef struct {
	int dia, mes, ano;
} data_t;

/* Mostra a data no formato dd/mm/aaaa. Argumento:
 *     - ptr_d -> endereço do registro que armazena a data.
 * 
 * Exemplo de uso:
 *     mostra_data(&nasc);
 */
void mostra_data(data_t *ptr_d) {
	if(!ptr_d) return;

	printf("%02d/%02d/%04d", ptr_d->dia, ptr_d->mes, ptr_d->ano);
}

/* Exemplo do uso tradicional de registro. */
void uso_padrao() {
	data_t nascimento;

	/* Acessar uma variável do registro é simples: 
	 *     nome_do_registro.nome_da_variável     */
	nascimento.dia = 1;
	nascimento.mes = 1;
	nascimento.ano = 2000;
	printf("\n");
	mostra_data(&nascimento);

	/* "mes" é um inteiro. */
	nascimento.mes = 2;
	printf("\n");
	mostra_data(&nascimento);

	/* "dia" também é inteiro. */
	nascimento.dia += 10; /* Qual o valor máximo que pode ser atribuído? */
	printf("\n");
	mostra_data(&nascimento);

	nascimento.ano--; /* Ano pode ser negativo? */
	printf("\n");
	mostra_data(&nascimento);
}

/* Exemplo do uso de ponteiro para registro. */
void ponteiro_para_registro() {
	data_t nascimento, *ptr = &nascimento;

	/* Acessar uma variável pelo endereço do registro é simples: 
	 *     ponteiro->nome_da_variável     */
	ptr->dia = 1;
	ptr->mes = 1;
	ptr->ano = 2000;
	printf("\n");
	mostra_data(ptr);

	ptr->mes = 2;
	printf("\n");
	mostra_data(ptr);

	ptr->dia += 10;
	printf("\n");
	mostra_data(ptr);

	nascimento.ano--;
	printf("\n");	
	mostra_data(ptr);

}

/* Exemplo de como usar um registro dentro de um registro. */
void composicao_de_registros() {
	/* Registro para armazenar endereços. */
	struct endereco_t {
		char CEP[30], cidade[30], bairro[30], rua[30];
		int numero;
	};

	/* Registro para armazenar departamentos. */
	struct departamento_t {
		char nome[50];
		data_t fundacao;
		struct endereco_t endereco;
	};

	struct departamento_t cic, *ptr = &cic;

	strcpy(cic.endereco.CEP, "70910-900");
	/* Que é a mesma coisa que: */
	strcpy(ptr->endereco.cidade, "Brasília");
	/* Que funciona igual a : */
	strcpy((*ptr).endereco.bairro, "Asa Norte");	
	strcpy((*ptr).endereco.rua, "Edifício CIC/EST");
	
	strcpy(cic.nome, "Depto. de Ciência da Computação");

	ptr->fundacao.dia = 28;
	(*ptr).fundacao.mes = 5;
	cic.fundacao.ano = 1987;

	printf("\n%s", cic.nome);
	printf(", fundado em "), mostra_data(&(ptr->fundacao));
	printf(", situado em %s.", cic.endereco.cidade);

	/* Que tal criar um registro "universidade_t", contendo um vetor de 
	departamentos? */
}

/* Função principal. A recomendação é verificar o comportamento de uma função de
   cada vez, analisando o código e o resultado mostrado para garantir a 
   coompreensão dos procedimentos apresentados. */
int main () {
	uso_padrao();
	ponteiro_para_registro();
	composicao_de_registros();

	printf("\n");
	return EXIT_SUCCESS; /* Indica que não houve erro. */
}