#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função para remover o \n que fica no final de strings lidas com fgets
void removerQuebraLinha(char texto[]) {
    size_t len = strlen(texto);
    if (len > 0 && texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
    }
}

// Função para cadastrar territórios
void cadastrarTerritorios(struct Territorio territorios[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(territorios[i].nome, 30, stdin);
        removerQuebraLinha(territorios[i].nome);

        printf("Digite a cor do exército: ");
        fgets(territorios[i].cor, 10, stdin);
        removerQuebraLinha(territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa o \n restante no buffer do teclado
    }
}

// Função para exibir territórios cadastrados
void exibirTerritorios(struct Territorio territorios[], int tamanho) {
    printf("\n===== Territórios Cadastrados =====\n");

    for (int i = 0; i < tamanho; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }
}

int main() {
    struct Territorio territorios[5]; // Vetor para 5 territórios

    printf("=== Sistema de Cadastro de Territórios ===\n");

    cadastrarTerritorios(territorios, 5);
    exibirTerritorios(territorios, 5);

    return 0;
}
