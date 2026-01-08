#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int navioHorizontal[TAM_NAVIO];
    int navioVertical[TAM_NAVIO];

    int i, j;

    /* Inicializa o tabuleiro com 0 (água) */
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    /* Inicializa os vetores dos navios */
    for (i = 0; i < TAM_NAVIO; i++) {
        navioHorizontal[i] = NAVIO;
        navioVertical[i] = NAVIO;
    }

    /* Coordenadas iniciais (podem ser alteradas) */
    int linhaH = 2, colunaH = 1; // Navio horizontal
    int linhaV = 5, colunaV = 6; // Navio vertical

    /* Validação de limites e posicionamento do navio horizontal */
    if (colunaH + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro ao posicionar o navio horizontal.\n");
        return 1;
    }

    /* Validação de limites e posicionamento do navio vertical */
    if (linhaV + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                printf("Erro: sobreposição de navios.\n");
                return 1;
            }
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    } else {
        printf("Erro ao posicionar o navio vertical.\n");
        return 1;
    }

    /* Exibe o tabuleiro */
    printf("Tabuleiro Batalha Naval:\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}