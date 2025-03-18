#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
int tamanhoTabuleiro = 10;
int tabuleiro[10][10];

void inicializarTabuleiro(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro]) {
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0; // Inicializa com 0 (água)
        }
    }
}

void mostrarTabuleiro(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro]) {
    printf("  ");
    for (char i = 'A'; i < 'A' + tamanhoTabuleiro; i++) {
        printf("%c ", i); // Exibe as letras de A a J
    }
    printf("\n");
    
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        printf("%d ", i); // Exibe os números das linhas
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe o valor da posição
        }
        printf("\n");
    }
}

void definirHabilidadeCone(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro], int origemLinha, int origemColuna) {
    int tamanho = 5; // Tamanho da matriz de habilidade
    for (int i = 0; i < tamanho; i++) {
        for (int j = -i; j <= i; j++) {
            int linha = origemLinha + i;
            int coluna = origemColuna + j;
            if (linha < tamanhoTabuleiro && coluna >= 0 && coluna < tamanhoTabuleiro) {
                tabuleiro[linha][coluna] = 5; // Marca área afetada pela habilidade
            }
        }
    }
}

void definirHabilidadeCruz(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro], int origemLinha, int origemColuna) {
    int tamanho = 5; // Tamanho da matriz de habilidade
    for (int i = 0; i < tamanho; i++) {
        // Marca a linha e a coluna central
        if (origemLinha < tamanhoTabuleiro && origemColuna + i < tamanhoTabuleiro) {
            tabuleiro[origemLinha][origemColuna + i] = 5; // Horizontal
        }
        if (origemLinha + i < tamanhoTabuleiro && origemColuna < tamanhoTabuleiro) {
            tabuleiro[origemLinha + i][origemColuna] = 5; // Vertical
        }
    }
}

void definirHabilidadeOctaedro(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro], int origemLinha, int origemColuna) {
    int tamanho = 5; // Tamanho da matriz de habilidade
    for (int i = 0; i < tamanho; i++) {
        for (int j = -i; j <= i; j++) {
            int linha = origemLinha + i;
            int coluna = origemColuna + j;
            if (linha < tamanhoTabuleiro && coluna >= 0 && coluna < tamanhoTabuleiro) {
                tabuleiro[linha][coluna] = 5; // Marca área afetada pela habilidade
            }
        }
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    inicializarTabuleiro(tabuleiro);
    
    // Posicionando os navios predefinidos
    // Navio horizontal na linha 0
    tabuleiro[0][0] = 3; // Navio na posição (0, 0)
    tabuleiro[0][1] = 3; // Navio na posição (0, 1)
    tabuleiro[0][2] = 3; // Navio na posição (0, 2)

    // Navio vertical na coluna 5
    tabuleiro[1][5] = 3; // Navio na posição (1, 5)
    tabuleiro[2][5] = 3; // Navio na posição (2, 5)
    tabuleiro[3][5] = 3; // Navio na posição (3, 5)

    // Navio diagonal
    tabuleiro[4][7] = 3; // Navio na posição (4, 7)
    tabuleiro[5][8] = 3; // Navio na posição (5, 8)
    tabuleiro[6][9] = 3; // Navio na posição (6, 9)

    printf("\nTabuleiro inicial\n");
    printf("\n");
    mostrarTabuleiro(tabuleiro);

    // Definindo as habilidades
    definirHabilidadeCone(tabuleiro, 0, 2); // Origem da habilidade Cone
    definirHabilidadeCruz(tabuleiro, 2, 2); // Origem da habilidade Cruz
    definirHabilidadeOctaedro(tabuleiro, 4, 2); // Origem da habilidade Octaedro

    printf("\nTabuleiro pós habilidades\n");
    printf("\n");
    mostrarTabuleiro(tabuleiro);
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
