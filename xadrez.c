/*
  MateCheck — Nível Mestre
  - Bispo: 5 casas na diagonal superior direita (recursivo + loops aninhados)
  - Torre: 5 casas para a Direita (recursivo)
  - Rainha: 8 casas para a Esquerda (recursivo)
  - Cavalo: 1 movimento em L para cima à direita (loops com variáveis/condições múltiplas; uso de continue/break)

  Observação de saída:
  - Apenas as direções básicas são impressas ("Cima", "Baixo", "Esquerda", "Direita").
  - Para o Bispo (diagonal), imprimimos a combinação como duas linhas por passo: "Cima" seguido de "Direita".
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
    /* Garante pelo menos 1 execução (do-while) */
    do {
        putchar('\n');
        linhas--;
    } while (linhas > 0);
}

/* ------------------------- Movimentações (Recursivas) ------------------------- */

/*
  Bispo: diagonal superior direita.
  Requisitos atendidos:
  - Recursão para percorrer 'passos'.
  - Loops aninhados dentro de cada passo para combinar as direções básicas.
  - Saída apenas com as direções básicas.
*/
void mover_bispo_recursivo(int passos) {
    if (passos <= 0) return;

    /* Loops aninhados: combinando 'Cima' e 'Direita' para cada passo */
    const char *vertical = "Cima";
    const char *horizontal = "Direita";

    for (int i = 0; i < 1; i++) {   /* loop externo (p. ex., eixo vertical) */
        int j = 0;
        while (j < 1) {             /* loop interno (p. ex., eixo horizontal) */
            printf("%s\n", vertical);
            printf("%s\n", horizontal);
            j++;
        }
    }

    /* Chamada recursiva para o próximo passo */
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

/* --------------------- Movimentação do Cavalo (Loops) --------------------- */

/*
  Cavalo: 1 L para cima à direita (2 para cima, 1 para a direita).
  Requisitos atendidos:
  - Loop com múltiplas variáveis e condição composta.
  - Uso de continue (pular para a próxima iteração) e break (encerrar).
*/
void mover_cavalo_cima_direita(void) {
    const int alvoUp = CAVALO_UP;       /* 2 */
    const int alvoRight = CAVALO_RIGHT; /* 1 */

    /* upDone e rightDone controlados no próprio cabeçalho do for; condição composta (OR) */
    for (int upDone = 0, rightDone = 0; (upDone < alvoUp) || (rightDone < alvoRight); ) {

        /* Avança em 'Cima' até atingir 2 passos */
        if (upDone < alvoUp) {
            printf("Cima\n");
            upDone++;

            /* Exemplo de uso de 'continue': após o primeiro "Cima", vamos direto à próxima iteração */
            if (upDone == 1 && rightDone == 0) {
                continue;
            }
        }

        /* Depois completa "Direita" até 1 passo */
        if (rightDone < alvoRight) {
            printf("Direita\n");
            rightDone++;
        }

        /* Exemplo de 'break' quando ambos objetivos foram atingidos */
        if (upDone >= alvoUp && rightDone >= alvoRight) {
            break;
        }
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

    /* Cavalo: 1 L para cima à direita (2x "Cima", 1x "Direita") */
    mover_cavalo_cima_direita();

    return 0;
}