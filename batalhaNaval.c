#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
int tamanhoTabuleiro = 10;

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

int podeColocarNavio(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'H') {
        if (coluna + tamanho > tamanhoTabuleiro) return 0; // Verifica se cabe na horizontal
        for (int j = 0; j < tamanho; j++) {
            if (tabuleiro[linha][coluna + j] != 0) return 0; // Verifica se já está ocupado
        }
    } else if (direcao == 'V') {
        if (linha + tamanho > tamanhoTabuleiro) return 0; // Verifica se cabe na vertical
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Verifica se já está ocupado
        }
    }
    return 1; // Retorna 1 se é possível colocar o navio
}

void colocarNavio(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro], int linha, int coluna, int tamanho, char direcao, int navio) {
    if (direcao == 'H') {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[linha][coluna + j] = navio; // Coloca o navio na horizontal
        }
    } else if (direcao == 'V') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = navio; // Coloca o navio na vertical
        }
    }
}

void posicionarNavios(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro]) {
    int tamanhoNavio[3] = {3, 3, 3}; // Tamanhos dos navios
    
    for (int i = 0; i < 3; i++) {
        int linha, coluna;
        char direcao;

        printf("Posicione o Navio usando H para horizontal e V para vertical:\n");
        scanf(" %c", &direcao);
        printf("Digite a linha (0 - 9) e a coluna (A - J):\n");

        char colunaLetra;
        scanf("%d %c", &linha, &colunaLetra);
        coluna = colunaLetra - 'A'; // Converte letra para índice

        if (podeColocarNavio(tabuleiro, linha, coluna, tamanhoNavio[i], direcao)) {
            colocarNavio(tabuleiro, linha, coluna, tamanhoNavio[i], direcao, i + 1);
        } else {
            printf("Posição Inválida! Tente Novamente. \n");
            i--; // Repete a iteração para tentar novamente
        }
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];
    inicializarTabuleiro(tabuleiro);
    mostrarTabuleiro(tabuleiro);

    printf("Vamos posicionar os navios!\n");
    posicionarNavios(tabuleiro);

    printf("Tabuleiro com os navios posicionados!\n");
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
