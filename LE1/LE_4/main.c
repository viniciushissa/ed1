#include <stdio.h>
#include <stdlib.h>
// Estrutura para os dados do estudante
typedef struct estudante{
    int id;     // ID do estudante
    float CR;   // Coeficiente de rendimento do estudante
}std;

// Estrutura para um nó da lista
typedef struct Node {
    std *data; // Ponteiro para uma estrutura de estudante
    struct Node *next;    // Ponteiro para o próximo nó na lista
}no;

// Função para criar um novo nó
no* criarNo(std *estudante) {
    no *novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória para o novo nó.\n");
        exit(1);
    }
    novoNo->data = estudante;
    novoNo->next = NULL;
    return novoNo;
}

// Função para inserir um nó no final da lista
void inserirNo(no **bloco, std *estudante) {
    no *novoNo = criarNo(estudante);
    if (*bloco == NULL) {
        *bloco = novoNo;
    } else {
        no *temp = *bloco;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
    }
}

// Função para imprimir a lista de nós
void mostrarLista(no *bloco) {
    no *temp = bloco;
    while (temp != NULL) {
        printf("ID: %d, CR: %.2f\n", temp->data->id, temp->data->CR);
        temp = temp->next;
    }
}

// Função para trocar os dados de dois nós
void trocar(std *a, std *b) {
    int tempId = a->id;
    float tempCR = a->CR;
    a->id = b->id;
    a->CR = b->CR;
    b->id = tempId;
    b->CR = tempCR;
}

// Função para ordenar a lista usando Bubble Sort
void ordenarLista(no *bloco) {
    int trocado, i;
    no *ptr1;
    no *lptr = NULL;

    // Verificando se a lista está vazia
    if (bloco == NULL)
        return;

    do {
        trocado = 0;
        ptr1 = bloco;

        while (ptr1->next != lptr) {
            if (ptr1->data->CR > ptr1->next->data->CR) {
                trocar(ptr1->data, ptr1->next->data);
                trocado = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (trocado);
}


// Função principal
int main() {
    // Leitura do arquivo de dados dos estudantes
    FILE *file = fopen("estudantes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    no *bloco = NULL;
    std *estudante;
    int id;
    float CR;

    // Leitura dos dados dos estudantes do arquivo
    while (fscanf(file, "%d %f", &id, &CR) != EOF) {
        estudante = (std*)malloc(sizeof(std));
        if (estudante == NULL) {
            printf("Erro: Falha na alocação de memória para o estudante.\n");
            exit(1);
        }
        estudante->id = id;
        estudante->CR = CR;
        inserirNo(&bloco, estudante);
    }

    fclose(file);

    // Teste da lista de nós
    printf("Lista de Estudantes:\n");
    mostrarLista(bloco);
    ordenarLista(bloco);
    printf("\n");
    printf("Lista Organizada:");
    printf("\n");
    mostrarLista(bloco);  
    return 0;
}

