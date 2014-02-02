/* Arquivo: chutes.c
 *
 * Autor: Guilherme N. Ramos (gnramos@unb.br)
 * 
 * Complete o código abaixo, trocando "??_??" pelo termo correto. */

/* Quanto pronto, este programa deve funcionar como um jogo para tentar acertar
 * a escolha de um número aleatório entre 0 e 99. A cada "chute", o programa 
 * diz ao usuário o alguma informação. 
 * 
 * Conhecimentos necessários: 
 *  - condicionais
 *  - laços de repetição
 */

#include <stdlib.h>
#include <??_??>

int main() {
  int numero = rand()??_??100; // 0 < numero < 99
  int chute = -1; 
  int tentativas = 0; 

  while((chute ??_?? numero) ??_?? (tentativas ??_?? 8)) {
    printf("\nDigite o número: ");
    ??_??("%d", ??_??);
    ??_??(numero ??_?? chute)
      ??_??("\nChutou alto demais.");
    ??_?? ??_??(numero ??_?? chute)
      ??_??("\nChutou baixo demais.");
    ??_??
      ??_??("\nCerto!");
  }

  ??_??(numero ??_?? chute)
      printf("\nAaahhh... O número era: %d.", ??_??);
  
  ??_?? EXIT_SUCESS;
??_??