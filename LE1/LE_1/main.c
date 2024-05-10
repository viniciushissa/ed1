/* agenda.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h"
/* função getch */
#ifdef DOS
#include <conio.h>
#else
//#include <curses.h>
#endif

int main(void){
AGENDA  *pAgenda;

int iEntradas, op;
iEntradas=0;


pAgenda = (AGENDA*)malloc(sizeof(AGENDA)); /* alocando espaço para a posição 0
do vetor */
if( pAgenda == NULL )
{
printf("\nErro de alocacao de memoria.");
exit(1);
}

do
{
fflush(stdin);
printf("\n1 - Inclusao");
printf("\n2 - Alteracao");
printf("\n3 - Consulta");
printf("\n4 - Excluir");
printf("\n5 - Pesquisar");
printf("\n9 - Sair");
printf("\nEntre com uma opcao -> ");
scanf("%d", &op);
if( op == 1 )
{
/* farei aqui para ilustrar algumas formas de manipular ponteiros */
fflush(stdin);
/* alocação de ponteiros em funções requer trabalhar com ponteiros
para ponteiros */
aloca(&pAgenda, &iEntradas);
printf("*** Inclusao ***");
printf("\nEntre com o Nome:");
/* forma 1 - endereço ponteiro inicial + x posições na memória
quando se trabalhar com o endereço, deve-se usar -> */
gets((pAgenda+iEntradas)->nome);
fflush(stdin);


printf("Entre com o email:");
/* forma 2 - endereço ponteiro inicial + x posições na memória
quando se trabalhar com ponteiro (conteúdo do endereço ou *),
deve-se usar o . (ponto) */
gets((*(pAgenda+iEntradas)).email);
fflush(stdin);
printf("Entre com o telefone:");
/* forma 3 - trabalhando como vetor */
scanf("%d", &pAgenda[iEntradas].telefone);
fflush(stdin);

iEntradas++;
}
else if( op == 2)
{
alterar(pAgenda, iEntradas);
}
else if( op == 3)
{
/* se o vetor de estruturas vai ser somente lido
não é preciso passar ponteiro para ponteiro */
ordena(pAgenda, iEntradas);
consulta(pAgenda, iEntradas);
}
else if( op == 4)
{
ordena(pAgenda, iEntradas);
excluir(&pAgenda, &iEntradas);
}
else if( op == 5)
{
ordena(pAgenda, iEntradas);
pesquisar(pAgenda,iEntradas);
}
} while(op!=9);
}
