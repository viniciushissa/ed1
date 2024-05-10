#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher(int *vet,int n){
	int i;
	srand(time(0));
		 
		 for(i=0;i<n;i++){
		 	vet[i] = rand()%100;
		 }
	
}


void copiar(int *vetO,int *vetD,int n){
		int i;		
			for(i=0;i<n;i++){
				vetD[i] = vetO[i];
			}	
}



void BubbleSort(int *vet, int n,long long int *comp,long long int *atrib) {
    int i, j, temp;

    for (i=0;i<n;i++){     
        
		for (j=0;j<n-1;j++) {
            (*comp)++;
			if (vet[j] > vet[j+1]) {
                int temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
                (*atrib) += 3; 
            }
        }
    }
}

void SelectionSort(int *vet,int n,long long int *comp,long long int *atrib){
	int i, j, menor,troca;
	
	for(i=0;i<n-1;i++){
		menor = i;
		for(j=i+1;j<n;j++){
			(*comp)++;
			if(vet[j]<vet[menor])
				menor = j;
		}
		if(i != menor){
			troca = vet[i];
			vet[i] = vet[menor];
			vet[menor] = troca;
			(*atrib) +=3;
		}
	}	
}


void InsertionSort(int *vet,int n,long long int *comp,long long int *atrib){
	int i,j,atual;
		for(i=1;i<n;i++){
			
			atual = vet[i];
			(*atrib)++;
			
			for(j=i;(j>0) && (atual < vet[j-1]);j--){
				(*comp)++;
				vet[j] = vet[j-1];
				(*atrib)++;
			}
			vet[j] = atual;
			(*atrib)++;
		}
}



void exibirVetor(int n,int *v){
	int i;
		printf("\n ------------------\n");
		printf("\n       VETOR       \n");
		printf("\n ------------------\n");
		for(i=0;i<n;i++){
			printf(" %d",v[i]);
		}
}


main(){
	int vetB[50000], vetS[50000], vetI[50000] ;
	long long int comp,atrib;
	clock_t start, end;
    double cpu_time_used;

	preencher(vetB,50000);
	copiar(vetB,vetS,50000);
	copiar(vetB,vetI,50000);
	
	comp=0;
	atrib=0;
	start = clock();
	BubbleSort(vetB,50000,&comp,&atrib);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	
	printf("Bubble Sort - Tempo: %f ms, Comparacoes: %lld, Atribuicoes: %d\n",cpu_time_used, comp, atrib);
	
 	comp=0;
	atrib=0;
	start = clock();
	SelectionSort(vetS,50000,&comp,&atrib);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	
	printf("Selection Sort - Tempo: %f ms, Comparacoes: %lld, Atribuicoes: %d\n",cpu_time_used, comp, atrib);
	
	comp=0;
	atrib=0;
	start = clock();
	InsertionSort(vetI,50000,&comp,&atrib);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	
	printf("Insertion Sort - Tempo: %f ms, Comparacoes: %lld, Atribuicoes: %d\n",cpu_time_used, comp, atrib);

	
	
 /* exibirVetor(10,vetB);
	exibirVetor(10,vetS);
	exibirVetor(10,vetI);*/
				
	
}
