/* Arquivo: ponteiros.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Exemplos de uso de ponteiros. */

#include <stdio.h> /* funções de manipulação da entrada/saída padrão */
#include <stdlib.h> /* define EXIT_SUCCESS */

/* Variáveis globais. */
#define TAM_VETOR 5
static int vetor[TAM_VETOR] = {15, 20, 3, 8, 12};
/* Sim, variáveis globais podem ser usadas em determinadas situações, mas saber 
identificar quais são essas situações não é trivial. */

/* Mostra o vetor dado na saída padrão. */
void mostra_vetor(int *v, int tam) {
	printf("{");
	while(--tam) printf("%d,", *(v++));
	printf("%d}", *v);
}

/* Exemplo do uso tradicional de ponteiros. */
void uso_padrao() {
	printf("\n\n\nUso padrão:\n");
	
	int *p, i = 0;
	p = &i; /* aponta para algum lugar */
	printf("\np=%p\t*p=%d\ti=%d",p, *p, i);
	i++; 
	printf("\np=%p\t*p=%d\ti=%d",p, *p, i);
	(*p)++; /* altera o conteúdo armazenado */
	printf("\np=%p\t*p=%d\ti=%d",p, *p, i);
}

/* Soma o inteiro n dado a cada elemento do vetor v (que tem tamanho tam). */
int *soma_int(int *v, int tam, int n) {
	int *p = v;
	while(tam--) 
		*(p+tam) += n; /* desloca o ponteiro e altera o conteúdo armazenado */
	return p; /* retorna o endereço de memória */
}

/* Exemplo de ponteiro como valor devolvido pela função chamada. */
void retorna_em_funcao() {
	printf("\n\n\nRetorno em funções:\n");

	int *p = soma_int(vetor, TAM_VETOR, 2); /* altera o vetor */
	printf("\np=%p\t\t*p=", p);	
	mostra_vetor(p, TAM_VETOR);
	
	p = soma_int(vetor, TAM_VETOR, -2); /* desfaz a alteração */
	printf("}\np=%p\t\t*p=", p);
	mostra_vetor(p, TAM_VETOR);
}

/* Retorna o endereço do elemento n no vetor, se existir. */
int *pesquisa_no_vetor(int n) {
	int *p = vetor + TAM_VETOR;
	while(p > vetor) /* desloca o ponteiro e compara seu conteúdo armazenado */
		if(*(--p) == n)
			return p; 
	return NULL;
}

/* Outro exemplo de ponteiro como valor devolvido pela função chamada. */
void retorna_em_funcao2_a_missao() {
	printf("\n\n\nRetorno em funções 2:\n");

	printf("\nvetor="), mostra_vetor(vetor, TAM_VETOR); /* só para lembrar... */
	int n = -1; /* valor que não existe... */
	int *p = pesquisa_no_vetor(n);
	printf("\nBuscando %d em vetor -> %p", n, p); /* mostra o que a função retornou */
	if(p) printf(" *p = %d", *p); /* se achou, mostra o conteúdo */
	
	n = vetor[TAM_VETOR/2]; /* repete para outro */
	p = pesquisa_no_vetor(n);
	printf("\nBuscando %d em vetor -> %p", n, p);
	if(p) printf(" *p = %d", *p);
}

/* Mostra o nome na saída padrão, com formatação correta. */
void mostra_nome(char *nome) {
	if(nome[0] >= 'a' && nome[0] <= 'z')
		nome[0] -= 'a'-'A'; /* a 1a é maiúscula! */

	printf("%s", nome);
}

/* Mostra a data na saída padrão, com formatação correta. */
void mostra_data(int *data) {
	printf("%02d/%02d/%4d", data[0], data[1], data[2]);
}

/* Exemplo do uso de ponteiro como argumento de funções. */
void indo_em_funcoes() {
	printf("\n\n\nParâmetro  em funções:\n");

	char nome[6] = "pudim";
	int nascimento[3] = {1,1,2000}; /* {dia, mês, ano} */

	printf("\n");
	mostra_nome(nome);
	printf(" nasceu em ");
	mostra_data(nascimento);
}

/* Define o valor de d como o dobro de n, e de q como o quadrado de n. */
void dobro_e_quadrado(int n, int *d, int *q) {
	*d = 2*n; /* altera o conteúdo armazenado */
	*q = n*n;
}

/* Exemplo do uso de ponteiro como argumento de funções que "retornam" mais de 
um valor. */
void vindo_em_funcoes() {
	printf("\n\n\nRetornando valores em funções:\n");

	int *p, i = 1;
	p = &i;
	printf("\np=%p\t*p=%d\ti=%d",p, *p, i);
	int j, k=3;
	dobro_e_quadrado(k, &j, p);
	printf("\nk=%d\tj=%d\t*p=%d", k, j, *p);
	dobro_e_quadrado(k, &i, p);
	printf("\nk=%d\ti=%d\t*p=%d", k, i, *p);  /* opa!  "&i" e "p" ??? */
}

/* Exemplo de manipulação de ponteiro para percorrer um vetor. */
void uso_arrojado() {
	printf("\n\n\nUso \"arrojado\":");

	const int num_letras = 26;
	char c[num_letras]; /* todo o alfabeto */
	int i;
	for(i = 1; i < num_letras; ++i) c[i] = 'A'+i;

	int *pi;
	printf("\n\n");
	for (pi = vetor; pi < vetor + TAM_VETOR; pi++) 
		printf("%c", c[*pi]); /* os elementos do vetor indicam o deslocamento em c */
	
	int y[TAM_VETOR];
	y[0] = vetor[0];
	for(i = 1; i < TAM_VETOR; i++)
		y[i] = vetor[i]-vetor[i-1]; /* deslocamento relativo ao elemento anterior! */
	
	char *pc=c;
	printf("\n");
	for(i = 0; i < TAM_VETOR; i++) {
		pc+=y[i]; /* como é relativo, vai acumulando... */
		printf("%c", *pc);
	}
}

/* Exemplo de aritmética com ponteiros. */
void aritmetica_simples() {
	printf("\n\n\nAritmética simples: (sizeof(int)=%ld)\n",sizeof(int));
	
	int i;
	for (i = 0; i<TAM_VETOR; i++)
		printf("\nvetor+%d=%p\t*(vetor+%d)=%d", i, vetor+i, i, *(vetor+i));
}

/* Exemplo de como ponteiros de tipos diferentes se comportam. */
void tipos() {
	printf("\n\n\nTipos são diferentes, mas ponteiros são iguais:\n");
	
	int vetor = 0x41200000;
	int* p1 = &vetor;
	float* p2 = (float *)p1;
	char*  p3 = (char *)p2;

	printf("\np1=%p\t*p1=%x", p1, *p1);
	printf("\np2=%p\t*p2=%f", p2, *p2);
	printf("\np3=%p\t*p3=%c", p3, p3[sizeof(int)-1]);/* little-endian! */

	/* Isso depende da arquitetura, a minha é little-endian. se a sua for 
	   big-endian, é só trocar "p3[sizeof(int)-1])" por "*p3". O resultado
	   deveria ser a letra 'A'. */
}

/* Exemplo de aritmética com ponteiros para tipos diferentes. */
void aritmetica_de_tipos() {
	printf("\n\n\nAritmética é igual para tipos diferentes.");
	printf("\nsizeof(int)=%ld, sizeof(float)=%ld, sizeof(char)=%ld\n", sizeof(int), sizeof(float), sizeof(char));
	
	/* operações aritméticas em ponteiros para tipos diferentes têm resultados...
	   ...
	   ...
	   ...
	   ... diferentes. */

	char *pc, c[5] = "abcd";
	int *pi = vetor;

	pc = c;
	printf("\npc=%p\t*pc=%s", pc, pc);
	pc++; /* desloca uma unidade de tamanho de char */
	printf("\npc=%p\t*pc=%s", pc, pc);

	pc = (char *)pi; /* apontam para a mesma posição */
	printf("\npi=%p\t*pi=%d", pi, *pi);
	printf("\npc=%p\t*pc=%c", pc, *pc);
	pc++, pi++; /* desloca uma unidade de tamanho de char / int */
	printf("\npi=%p\t*pi=%d", pi, *pi);
	printf("\npc=%p\t*pc=%c", pc, *pc);
}

/* Exemplo de como ponteiros são números que indicam posições de memória. */
void ponteiros_sao_inteiros() {
	printf("\n\n\nPonteiros são inteiros...\n");

	int *p = vetor;
	long int end;

    printf("\np=%p\t*p=%d", p, *p);
    end = (long int)(p + 1); /* "valor" do endereço da 2a posição de memória */
    p = (int *)end;   
    printf("\np=%p\t*p=%d", p, *p);
    end--;
    p = (int *)end; /* endereço "intermediário"... */
    printf("\np=%p\t*p=%d", p, *p);/* ... que é interpretado corretamente! */
}

/* Exemplo de uso de vetor de ponteiros*/
void vetores_de_ponteiros() {
	printf("\n\n\nVetores de ponteiros:\n");

	int *p[TAM_VETOR], i;
	for(i=0; i < TAM_VETOR; i++)
		p[i] = &(vetor[TAM_VETOR-i-1]); /* cada posição armazena um endereço */

	printf("\np=%p", p);
	for(i=0; i < TAM_VETOR; i++)
		printf("\np[%d]=%p\t*p[%d]=%d", i, p[i], i, *p[i]);
}

/* Exemplo de uso de ponteiros em matrizes. */
void matrizes_e_ponteiros() {
	printf("\n\n\nMatrizes são vetores de ponteiros...\n");

	const int tam = 10;
	int mat[tam][tam],i,j;
	for(i=0;i<tam; ++i)
		for(j=0;j<tam; ++j)
			mat[i][j] = 10*i+j; /* cria a matriz */

	int *p;
	for(i=0;i<tam; ++i)
		for(j=0;j<tam; ++j) {         /* Em função de como a memória é alocada, */
			p = &mat[0][0] + i*tam+j; /* é possível saber o deslocamento correto */
			if(mat[i][j] != *p)       /* para chegar a qualquer elemento */
				printf("\n Erro nas coordenadas (%d,%d)",i,j);
		}

	/* Embora seja bem mais fácil usar o mat[i][j] */
}

/* Registro para testes */
struct registro {
	int i;
	float f;
	char c;
	int *ptr;
};

/* Exemplo do uso de ponteiros para registro que mostra o conteúdo na saída padrão. */
void mostra_registro(struct registro *r) {
	printf("\n registro.i = %d", r->i);
	printf("\n registro.f = %.1f", r->f);
	printf("\n registro.c = %c", r->c);
	printf("\n registro.ptr = %p", r->ptr);
}

/* Exemplo de ponteiros como argumentos. */
void ponteiros_para_registros() {
	printf("\n\n\nRegistros têm endereços.\n");

	struct registro r;
	r.i = 1;
	r.f = 0.5;
	r.c = 'a';
	r.ptr = vetor;
	mostra_registro(&r);
}

/* Retorna o valor máximo entre os dados. */
int max(int a, int b) { 
	/* printf("\n[max] "); */ /* esse comando mostra quando a função é chamada */
	return (a > b) ? a: b;
}

/* Retorna o valor mínimo entre os dados. */
int min(int a, int b) {
	/* printf("\n[min] "); */ /* esse comando mostra quando a função é chamada */
	return (a < b) ? a: b;
}

 /* Chama a função dada usando os parâmetros dados (a,b) como argumentos. */
int chama_a_funcao(int (*nome_da_funcao)(int , int ), int a, int b) {
	return nome_da_funcao(a,b);
}

/* Exemplo de uso de ponteiro para função. */
void ponteiro_para_funcao() {
	printf("\n\n\nFunções têm endereços também...\n");

	int a = 1, b = 2;
	printf("\nchama_a_funcao(max,%d,%d) = %d", a,b, chama_a_funcao(&max,a,b));
	printf("\nchama_a_funcao(min,%d,%d) = %d", a,b, chama_a_funcao(&min,a,b));
	a = 7;
	printf("\nchama_a_funcao(max,%d,%d) = %d", a,b, chama_a_funcao(&max,b,a));
	printf("\nchama_a_funcao(min,%d,%d) = %d", a,b, chama_a_funcao(&min,b,a));
}

/* Aplica a função de comparação dada em todos os elementos do vetor e retorna o
   o resultado para todos eles. */
int compara_todos_no_vetor(int (*nome_da_funcao)(int , int )) {
	int i = TAM_VETOR-1;
	int resultado = vetor[i];

	while(--i) resultado = nome_da_funcao(resultado, vetor[i]);
	return resultado;
}

/* Exemplo de como funções diferentes podem ser usadas em um mesmo contexto. */
void ooooOOOHH() {
	printf("\n\n\nooooOOOHH!\n");

	printf("\n O menor elemento de vetor é %d", compara_todos_no_vetor(&min));
	printf("\n O maior elemento de vetor é %d", compara_todos_no_vetor(&max));
}

/* Função principal. A recomendação é verificar o comportamento de uma função de
   cada vez, analisando o código e o resultado mostrado para garantir a 
   coompreensão dos procedimentos apresentados. */
int main () {
	printf("\nEis o vetor a ser utilizado: ");
	mostra_vetor(vetor, TAM_VETOR);

	uso_padrao();
	retorna_em_funcao();
	retorna_em_funcao2_a_missao();
	indo_em_funcoes();
	vindo_em_funcoes();
	aritmetica_simples();
	uso_arrojado();
	tipos();
	aritmetica_de_tipos();
	ponteiros_sao_inteiros();
	vetores_de_ponteiros();
	matrizes_e_ponteiros();
	ponteiros_para_registros();
	ponteiro_para_funcao();
	ooooOOOHH();

 	printf("\n");
 	return EXIT_SUCCESS; /* Indica que não houve erro. */
}	