typedef struct conjunto{ 
	int el[100];
	int tam;
}conj;

conj* conj_cria();
void conj_insere(conj* c, int item);
void conj_remove(conj* c, int item);
conj* conj_uniao(conj* conj1, conj* conj2);
conj* conj_inter(conj* conj1, conj* conj2);
conj* conj_dif(conj* conj1, conj* conj2);
int conj_pertence(conj* c, int item);
int conj_menor(conj* c);
int conj_maior(conj* c);
int conj_igual(conj* conj1, conj* conj2);
int conj_destroi(conj* c);
void conj_bubble_sort(conj *c);
void conj_mostra(conj *c);
