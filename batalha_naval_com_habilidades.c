#include <stdio.h>
#include <stdlib.h>


#define TAM 10       // Tamanho do tabuleiro
#define NAVIO_TAM 3  // Tamanho dos navios
#define VAZIO 0
#define NAVIO 3
#define HABILIDADE 5

void inicializar_tabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = VAZIO;
}

int verificar_sobreposicao(int tabuleiro[TAM][TAM], int l, int c, int dl, int dc) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int nl = l + i * dl;
        int nc = c + i * dc;
        if (tabuleiro[nl][nc] == NAVIO) return 1;
    }
    return 0;
}

int posicionar_navio(int tabuleiro[TAM][TAM], int l, int c, int dl, int dc) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int nl = l + i * dl;
        int nc = c + i * dc;
        if (nl < 0 || nl >= TAM || nc < 0 || nc >= TAM) return 0;
    }
    if (verificar_sobreposicao(tabuleiro, l, c, dl, dc)) return 0;

    for (int i = 0; i < NAVIO_TAM; i++) {
        int nl = l + i * dl;
        int nc = c + i * dc;
        tabuleiro[nl][nc] = NAVIO;
    }
    return 1;
}

void imprimir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO FINAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == VAZIO) printf("~ ");       // Água
            else if (tabuleiro[i][j] == NAVIO) printf("# ");  // Navio
            else if (tabuleiro[i][j] == HABILIDADE) printf("* "); // Habilidade
        }
        printf("\n");
    }
}

void aplicar_habilidade(int tabuleiro[TAM][TAM], int origem_linha, int origem_coluna, int forma) {
    int matriz[5][5];

    // Inicializa matriz com 0
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = 0;

    // Gera padrão da habilidade
    if (forma == 1) { // Cone para baixo
        for (int i = 0; i < 3; i++)
            for (int j = 2 - i; j <= 2 + i; j++)
                matriz[i][j] = 1;
    } else if (forma == 2) { // Cruz
        for (int i = 0; i < 5; i++) {
            matriz[2][i] = 1;
            matriz[i][2] = 1;
        }
    } else if (forma == 3) { // Octaedro (losango)
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (abs(i - 2) + abs(j - 2) <= 2)
                    matriz[i][j] = 1;
    }

    // Sobrepor no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tab_l = origem_linha + i - 2;
            int tab_c = origem_coluna + j - 2;
            if (matriz[i][j] == 1 && tab_l >= 0 && tab_l < TAM && tab_c >= 0 && tab_c < TAM) {
                if (tabuleiro[tab_l][tab_c] == VAZIO) {
                    tabuleiro[tab_l][tab_c] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializar_tabuleiro(tabuleiro);

    // Posiciona 4 navios
    posicionar_navio(tabuleiro, 1, 1, 0, 1); // horizontal
    posicionar_navio(tabuleiro, 4, 6, 1, 0); // vertical
    posicionar_navio(tabuleiro, 0, 0, 1, 1); // diagonal \
    posicionar_navio(tabuleiro, 0, 9, 1, -1); // diagonal /

    // Aplica habilidades
    aplicar_habilidade(tabuleiro, 7, 2, 1); // Cone
    aplicar_habilidade(tabuleiro, 2, 7, 2); // Cruz
    aplicar_habilidade(tabuleiro, 7, 7, 3); // Octaedro

    imprimir_tabuleiro(tabuleiro);

    return 0;
}
