#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "conjunto.h"
#include <stdbool.h>
int main() {
    int i,num;
    conj *c1, *c2, *uniaoConj, *interConj, *difConj;	
    
    // Criar dois conjuntos
    c1 = conj_cria();
    c2 = conj_cria();

    // Inserir elementos nos conjuntos
    printf("Digite os elementos para o conjunto 1 (digite -1024 para parar):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1024 )
            break;
        conj_insere(c1, num);
    }

    printf("Digite os elementos para o conjunto 2 (digite -1024 para parar):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1024)
            break;
        conj_insere(c2, num);
    }
    conj_bubble_sort(c1);
    conj_bubble_sort(c2);
    printf("Conjunto 1: ");
	conj_mostra(c1);
	printf("Conjunto 2: ");
	conj_mostra(c2);

    

    // Remover um elemento do conjunto1
    conj_remove(c1, 5);
    printf("Conjunto 1: ");
	conj_mostra(c1);
    printf("\n");
    
    
    // Verificar se um número pertence ao conjunto
    printf("O numero 3 pertence ao conjunto 1 ? %s\n", conj_pertence(c1, 3) ? "Sim" : "Nao");
	printf("\n");
    // Encontrar o menor e o maior valor do conjunto
    printf("Menor valor do conjunto 1: {%d}\n", conj_menor(c1));
    printf("\n");
    printf("Maior valor do conjunto 1: {%d}\n", conj_maior(c1));
    printf("\n");

    // Verificar se dois conjuntos são iguais
    printf("Conjunto 1 e conjunto 2 sao iguais? %s\n", conj_igual(c1, c2) ? "Sim" : "Nao");
    printf("\n");

    // Realizar a união de dois conjuntos
    printf("Uniao dos conjuntos: ");
    uniaoConj = conj_uniao(c1, c2);
    printf("{");
    for (i = 0; i <uniaoConj->tam; i++){
        if(i == uniaoConj->tam - 1) {
            printf("%d ", uniaoConj->el[i]);
            break;
        }
        printf("%d, ", uniaoConj->el[i]);
    }
    printf("}\n");


    // Realizar a interseção de dois conjuntos
    interConj = conj_inter(c1, c2);
    printf("Intersecao dos conjuntos: ");
    printf("{");
    for (i=0; i < interConj->tam; i++){
	
        if(i == interConj->tam - 1) {
            printf("%d ", interConj->el[i]);
            break;
        }
        printf("%d, ", interConj->el[i]);}
      printf("}\n");



    // Realizar a diferença de dois conjuntos
    printf("Diferenca dos conjuntos (Conjunto 1 - Conjunto 2): ");
    difConj = conj_dif(c1, c2);
    printf("{");
    for (i=0; i < difConj->tam; i++){
	
        if(i == difConj->tam - 1) {
            printf("%d ", difConj->el[i]);
            break;
        }
        printf("%d, ", difConj->el[i]);}
   printf("}\n");

    // Destruir os conjuntos
    conj_destroi(c1);
    conj_destroi(c2);
    conj_destroi(uniaoConj);
    conj_destroi(interConj);
    conj_destroi(difConj);

    return 0;
}
