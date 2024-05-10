#include <stdio.h>
#include <stdlib.h>
// Estrutura para os dados do estudante
typedef struct estudante{
    int id;     // ID do estudante
    float CR;   // Coeficiente de rendimento do estudante
}std;

// Estrutura para um n� da lista
typedef struct Node {
    std *data; // Ponteiro para uma estrutura de estudante
    struct Node *next;    // Ponteiro para o pr�ximo n� na lista
}no;

// Fun��o para criar um novo n�
no* criarNo(std *estudante) {
    no *novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria para o novo n�.\n");
        exit(1);
    }
    novoNo->data = estudante;
    novoNo->next = NULL;
    return novoNo;
}

// Fun��o para inserir um n� no final da lista
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

// Fun��o para imprimir a lista de n�s
void mostrarLista(no *bloco) {
    no *temp = bloco;
    while (temp != NULL) {
        printf("ID: %d, CR: %.2f\n", temp->data->id, temp->data->CR);
        temp = temp->next;
    }
}

// Fun��o para trocar os dados de dois n�s
void trocar(std *a, std *b) {
    int tempId = a->id;
    float tempCR = a->CR;
    a->id = b->id;
    a->CR = b->CR;
    b->id = tempId;
    b->CR = tempCR;
}

// Fun��o para ordenar a lista usando Bubble Sort
void ordenarLista(no *bloco) {
    int trocado, i;
    no *ptr1;
    no *lptr = NULL;

    // Verificando se a lista est� vazia
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


// Fun��o principal
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
            printf("Erro: Falha na aloca��o de mem�ria para o estudante.\n");
            exit(1);
        }
        estudante->id = id;
        estudante->CR = CR;
        inserirNo(&bloco, estudante);
    }

    fclose(file);

    // Teste da lista de n�s
    printf("Lista de Estudantes:\n");
    mostrarLista(bloco);
    ordenarLista(bloco);
    printf("\n");
    printf("Lista Organizada:");
    printf("\n");
    mostrarLista(bloco);  
    return 0;
}

