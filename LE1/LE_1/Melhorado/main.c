#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h"


int main(void){
  AGENDA *pAgenda;
  int iEntradas = 0,opcao;

  pAgenda = (AGENDA *)malloc(sizeof(AGENDA )); // alocando para a posição 0 do vetor
  if (pAgenda == NULL){
   printf("Erro de alocacao");
   exit(1);  // funcao encerra o programa !!!
  }
  
  do {
    printf("\n1 - Inclusao");
    printf("\n2 - Alteracao");
    printf("\n3 - Consulta");
    printf("\n4 - Excluir");
    printf("\n5 - Pesquisar");
    printf("\n9 - Sair");
    printf("\nEntre com uma opcao -> ");
    scanf("%d", &opcao);
    getchar(); // consume newline character
    

   switch (opcao)
   {
   case 1:
   	aloca(&pAgenda, &iEntradas);
    printf("*** Inclusao ***");
    printf("\nEntre com o Nome:");
    fgets(pAgenda[iEntradas].nome, 50, stdin);
    verificacao_input(pAgenda[iEntradas].nome);
	printf("Entre com o email:");
    fgets(pAgenda[iEntradas].email, 50, stdin);
    verificacao_input(pAgenda[iEntradas].email);
   	printf("Entre com o telefone:");
    scanf("%d", &pAgenda[iEntradas].telefone);
    getchar(); // consume newline character
	iEntradas++;

    break;
   case 2:
    alterar(pAgenda, iEntradas);
    break;
   case 3:
    ordena(pAgenda, iEntradas);
    consulta(pAgenda, iEntradas);
    break;
   case 4:
    ordena(pAgenda, iEntradas);
    excluir(&pAgenda, &iEntradas);
    break;
   case 5:
    ordena(pAgenda, iEntradas);
    pesquisar(pAgenda,iEntradas);
    break;
  
   }

  } while(opcao != 9);

   free(pAgenda);
   return 0;
}
