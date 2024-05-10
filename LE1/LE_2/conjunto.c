#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "conjunto.h"


conj* conj_cria(){
	conj* c;
	c = (conj*)malloc(sizeof(conj));
	c->tam=0;
	return c;
}
int conj_pertence(conj *c, int item){
	int i=0;
	for(i; i<c->tam;i++){
		if(c->el[i]==item)
			return 1;
	}
	return 0;
}

void conj_insere(conj *c, int item){
	int i=0;
	if (c->tam>=100){
		printf("Conjunto cheio");
		return;
	}
	for(i; i<c->tam; i++){
		if(c->el[i]==item){
			return;
		}
	}
	c->el[c->tam] = item;
	c->tam++;
}

void conj_remove(conj *c, int item){
	int i=0, j;
	for(i;i<c->tam;i++){
	if(c->el[i]==item)
		break;	
	}	
	if(i==c->tam){
		printf("numero %d nao encontrado no conjunto 1\n",item);
		return;
	}
	for(j=i;j<c->tam-1;j++)
		c->el[j]=c->el[j+1];
	c->tam--;
}

conj* conj_uniao(conj* conj1, conj* conj2){
	int i;
	conj* uniao = conj_cria();
	for(i=0;i<conj1->tam;i++)
		conj_insere(uniao, conj1->el[i]);
	for(i=0;i<conj1->tam;i++){
		if(!conj_pertence(uniao, conj2->el[i]))
			conj_insere(uniao, conj1->el[i]);
	}
	return uniao;
}

conj* conj_inter(conj* conj1, conj* conj2){
	int i;
	conj* inter = conj_cria();
	for(i=0;i<conj1->tam;i++){
		if(conj_pertence(conj2, conj1->el[i]))
			conj_insere(inter, conj1->el[i]);
	}
	return inter;
}


conj* conj_dif(conj* conj1, conj* conj2){
    int i;
    conj* dif = conj_cria();

    for(i=0;i<conj1->tam;i++){
        if(!conj_pertence(conj2, conj1->el[i]))
            conj_insere(dif, conj1->el[i]);
    }

    // Se o conjunto resultante está vazio, imprime "Vazio"
    if(dif->tam == 0) {
        printf("Vazio\n");
    }

    return dif;
}


void conj_bubble_sort(conj *c) {
    int i, j, temp;
    for(i = 0; i < c->tam-1; i++) {
        for(j = 0; j < c->tam-i-1; j++) {
            if(c->el[j] > c->el[j+1]) {
                temp = c->el[j];
                c->el[j] = c->el[j+1];
                c->el[j+1] = temp;
            }
        }
    }
}
void conj_mostra(conj *c) {
    int i;
    printf("{");
    for (i = 0; i < c->tam; i++){
        if(i == c->tam - 1) {
            printf("%d", c->el[i]);
            break;
        }
        printf("%d, ", c->el[i]);
    }
    printf("}\n");
}



int conj_menor(conj *c){
	
	return c->el[0];
}

int conj_maior(conj *c){
	
	return c->el[c->tam-1];
}


int conj_igual(conj* conj1, conj* conj2){
	int i=0;
	if(conj1->tam!=conj2->tam)
		return 0;
	for(i;i<conj1->tam;i++){
		if(!conj_pertence(conj2, conj1->el[i]))
			return 0;
	}
	return 1;
}

int conj_destroi(conj *c){
	free (c);
}
