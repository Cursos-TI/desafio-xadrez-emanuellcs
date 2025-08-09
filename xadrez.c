/*
  MateCheck — Nível Mestre (ajustado)
  - Bispo: 5 casas na diagonal superior direita (recursivo + loops aninhados)
  - Torre: 5 casas para a Direita (recursivo)
  - Rainha: 8 casas para a Esquerda (recursivo)
  - Cavalo: 1 movimento em L para cima à direita (loops aninhados, múltiplas variáveis/condições, continue/break)

  Observação de saída:
  - Apenas as direções básicas são impressas ("Cima", "Baixo", "Esquerda", "Direita").
  - Para o Bispo (diagonal), imprimimos duas linhas por passo: "Cima" e "Direita".
*/

#include <stdio.h>
#include <stdbool.h>

/* Constantes de configuração (entrada via código) */
#define BISPO_PASSOS   5
#define TORRE_PASSOS   5
#define RAINHA_PASSOS  8
#define CAVALO_UP      2   /* duas casas para cima */
#define CAVALO_RIGHT   1   /* uma casa para a direita */

/* Prototipagem */
void mover_bispo_recursivo(int passos);
void mover_torre_recursiva(int passos);
void mover_rainha_recursiva(int passos);
void mover_cavalo_cima_direita(void);

/* Utilitário: separador em branco usando do-while (para organizar a saída) */
static void separador_em_branco(int linhas) {
    if (linhas <= 0) return;
    do {
        putchar('\n');
        linhas--;
    } while (linhas > 0);
}

/* ------------------------- Movimentações (Recursivas) ------------------------- */

/*
  Bispo: diagonal superior direita.
  - Recursão para percorrer 'passos'.
  - Loops aninhados por passo para combinar direções básicas.
*/
void mover_bispo_recursivo(int passos) {
    if (passos <= 0) return;

    const char *vertical = "Cima";
    const char *horizontal = "Direita";

    for (int i = 0; i < 1; i++) {
        int j = 0;
        while (j < 1) {
            printf("%s\n", vertical);
            printf("%s\n", horizontal);
            j++;
        }
    }

    mover_bispo_recursivo(passos - 1);
}

/*
  Torre: direita 'passos' vezes (recursivo).
*/
void mover_torre_recursiva(int passos) {
    if (passos <= 0) return;
    printf("Direita\n");
    mover_torre_recursiva(passos - 1);
}

/*
  Rainha: esquerda 'passos' vezes (recursivo).
*/
void mover_rainha_recursiva(int passos) {
    if (passos <= 0) return;
    printf("Esquerda\n");
    mover_rainha_recursiva(passos - 1);
}

/* --------------------- Movimentação do Cavalo (Loops Aninhados) --------------------- */

/*
  Cavalo: 1 L para cima à direita (2 para "Cima", 1 para "Direita").
  - Loop externo: percorre os dois segmentos do L (segmento 0 = vertical; segmento 1 = horizontal).
  - Loop interno: executa os passos do segmento corrente.
  - Múltiplas variáveis no cabeçalho do loop externo (seg, up, right).
  - Condições múltiplas, uso de continue e break.
*/
void mover_cavalo_cima_direita(void) {
    const int alvoUp = CAVALO_UP;       /* 2 */
    const int alvoRight = CAVALO_RIGHT; /* 1 */

    for (int seg = 0, up = 0, right = 0; seg < 2; ++seg) {
        /* Define quantos passos executar neste segmento (vertical primeiro, depois horizontal) */
        const int passosAlvo = (seg == 0) ? alvoUp : alvoRight;

        for (int k = 0; k < passosAlvo; ++k) {
            /* Segurança: não permite iniciar o segmento horizontal antes de completar o vertical */
            if (seg == 1 && up < alvoUp) {
                /* Ainda não completou os 2 "Cima": ignora esta iteração do loop interno */
                continue; /* continue no loop interno até que a condição seja satisfeita */
            }

            if (seg == 0) {
                /* Segmento vertical */
                printf("Cima\n");
                up++;

                /* Após o primeiro "Cima" (up == 1) e ainda sem mover à direita, apenas continue. */
                if (up == 1 && right == 0) {
                    continue; /* demonstração explícita do uso didático de continue */
                }

                /* Se por algum motivo passamos do alvo (defesa), encerra este segmento. */
                if (up >= alvoUp) {
                    break; /* break no loop interno quando finaliza o segmento vertical */
                }
            } else {
                /* Segmento horizontal */
                printf("Direita\n");
                right++;

                /* Alcançou o 1 passo à direita? encerra imediatamente o segmento horizontal. */
                if (right >= alvoRight) {
                    break; /* demonstração de break no loop interno */
                }
            }
        }
        /* Próximo segmento do L */
    }
}

/* ----------------------------------- Main ----------------------------------- */

int main(void) {
    /* Bispo: 5 casas na diagonal superior direita */
    mover_bispo_recursivo(BISPO_PASSOS);
    separador_em_branco(1);

    /* Torre: 5 casas para a direita */
    mover_torre_recursiva(TORRE_PASSOS);
    separador_em_branco(1);

    /* Rainha: 8 casas para a esquerda */
    mover_rainha_recursiva(RAINHA_PASSOS);
    separador_em_branco(1);

    /* Cavalo: 1 L para cima à direita (2x "Cima", 1x "Direita") com loops aninhados */
    mover_cavalo_cima_direita();

    return 0;
}
