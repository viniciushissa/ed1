#include <stdio.h>
#include <string.h>

void encontrarSubstring(char* str, char* sub, int index, int* count) {
    char* ocorrencia = strstr(str, sub);
    if (ocorrencia != NULL) {
        (*count)++;
        int posicao = index + (ocorrencia - str);
        printf("Substring encontrada na posicao: %d\n", posicao);
        encontrarSubstring(ocorrencia + strlen(sub), sub, posicao + strlen(sub), count);
    }
}

int main() {
    char str[] = "Eu amo estrutura de dados :)";
    char sub[50];
    printf("Digite a substring que voce deseja encontrar: ");
    fgets(sub, 50, stdin);
    sub[strlen(sub) - 1] = '\0';  // Remove o '\n' do final
    printf("Encontrando todas as ocorrencias da substring \"%s\" na string \"%s\":\n", sub, str);
    int count = 0;
    encontrarSubstring(str, sub, 0, &count);
    printf("A substring \"%s\" foi encontrada %d vezes.\n", sub, count);
    return 0;
}


