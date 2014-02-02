/* Arquivo: utils.h
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Define os protótipos de funções auxiliares úteis, indicando o que cada faz,
 * quais são seus argumentos e fornecendo um exemplo de uso. A implementação 
 * destas é um bom exercício de fixação de comandos, portanto não faz parte do 
 * código aqui exposto. */

#ifndef UNB_CB_UTILS_H /* Garante definição única de variáveis/funções/etc. */
#define UNB_CB_UTILS_H

#include <stdio.h> /* Definição do tipo FILE */

 #define VERDADEIRO 1 /* Booleanos para auxiliar o entendimento. */
 #define FALSO 0

/* Abre o arquivo (via função "open") com as opções dadas e retorna o ponteiro 
 * para este (NULL caso não seja possível abrir). Argumentos:
 *     - arquivo -> endereço completo do arquivo.
 *     - opcoes -> opções de como abrir o arquivo. 
 * 
 * Exemplo de uso:
 *     FILE *fp = abre_arquivo("nomes.txt", "r");
 */
FILE * abre_arquivo(const char *arquivo, const char *opcoes);

/* Apresenta uma mensagem ao usuário requisitando uma string (via função "printf")
 * e a lê da entrada padrão (via função "scanf"), armazenando no endereço dado 
 * (assume-se que o espaço é suficiente). Argumentos:
 *     - descricao -> descrição da string a ser lida.
 *     - str -> endereço onde armazenar a string .
 * 
 * Exemplo de uso:
 *     leia_string("nome do usuário", nome_do_usuario);
 */
void leia_string(const char *descricao, char *str);

/* Apresenta uma mensagem ao usuário requisitando um valor real (via função 
 * "printf") e o lê da entrada padrão (via função "scanf"), armazenando no 
 * endereço dado. Argumentos:
 *     - descricao -> descrição do número a ser lido.
 *     - ptr_f -> endereço onde armazenar o número.
 * 
 * Exemplo de uso:
 *     leia_float("lado do triângulo", &lado_do_triangulo);
 */
void leia_float(const char *descricao, float *ptr_f);

/* Apresenta uma mensagem ao usuário requisitando um valor inteiro (via função 
 * "printf") e o lê da entrada padrão (via função "scanf"), armazenando no 
 * endereço dado. Argumentos:
 *     - descricao -> descrição do número a ser lido.
 *     - ptr_i -> endereço onde armazenar o número.
 * 
 * Exemplo de uso:
 *     leia_int("idade", &idade);
 */
void leia_int(const char *descricao, int *ptr_i);

/* Apresenta uma mensagem ao usuário requisitando um vetor de n inteiros (via 
 * função "printf")  e o lê da entrada padrão (via função "scanf"), armazenando
 * no endereço dado. Argumentos:
 *     - descricao -> descrição do vetor a ser lido.
 *     - ptr_v -> endereço do vetor que armazenará os números.
 *     - n -> número de elementos a serem lidos.
 * 
 * Exemplo de uso:
 *     leia_vetor_int("Vetor de quantidades", vetor, tamanho_do_vetor);
 */
void leia_vetor_int(const char *descricao, int *ptr_v, int n);

/* Apresenta uma mensagem ao usuário requisitando um vetor de n reais (via 
 * função "printf")  e o lê da entrada padrão (via função "scanf"), armazenando
 * no endereço dado. Argumentos:
 *     - descricao -> descrição do vetor a ser lido.
 *     - ptr_v -> endereço do vetor que armazenará os números.
 *     - n -> número de elementos a serem lidos.
 * 
 * Exemplo de uso:
 *     leia_vetor_float("Vetor de quantidades", vetor, tamanho_do_vetor);
 */
void leia_vetor_float(const char *descricao, float *ptr_v, int n);

/* Mostra os n elementos do vetor de inteiros dado em uma linha (via função 
 * "printf"), cada elemento separado de seu vizinho pela string dada. Argumentos:
 *     - ptr_v -> endereço do vetor que armazena os números.
 *     - n -> número de elementos a serem mostrados.
 *     - sep -> string que separa elementos.
 * 
 * Exemplo de uso:
 *     mostra_vetor_int(vetor, tamanho_do_vetor, ", ");
 */
void mostra_vetor_int(int *ptr_v, int n, const char *sep);

/* Mostra os n elementos do vetor de reais dado em uma linha (via função 
 * "printf"), cada elemento separado de seu vizinho pela string dada. Argumentos:
 *     - ptr_v -> endereço do vetor que armazena os números.
 *     - n -> número de elementos a serem mostrados.
 *     - sep -> string que separa elementos.
 * 
 * Exemplo de uso:
 *     mostra_vetor_float(vetor, tamanho_do_vetor, "-");
 */
void mostra_vetor_float(float *v, int n, const char *sep);

#endif

/* Arquivo que contém a implementação das funções. */
#include "utils_impl.h"