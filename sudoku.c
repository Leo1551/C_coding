#include <stdio.h>

void lerSudoku(int *ponteiro);
int verifHorizontal(int *ponteiro);
int verifVertical(int *ponteiro);
int verifQuad(int *ponteiro);

int main()
{

    int vetor[81], qtdSudokus;
    int *ponteiro, saida = 0;

    ponteiro = vetor;

    scanf("%d", &qtdSudokus);

    for (int i = 0; i < qtdSudokus; i++)
    {
        lerSudoku(ponteiro);

        saida += verifHorizontal(ponteiro);
        saida += verifVertical(ponteiro);
        saida += verifQuad(ponteiro);

        printf("Instancia %d\n", i + 1);

        if (saida == 0)
            printf("SIM\n");
        else
            printf("NAO\n");
    }
    return 0;
}
void lerSudoku(int *ponteiro)
{
    int i;

    for (i = 0; i < 81; i++)
        scanf("%d", (ponteiro + i));
}

int verifHorizontal(int *ponteiro)
{
    int i, j, num = 1, contador = 1;

    while (contador == 1 && num < 10)
    {

        contador = 0;

        for (i = 0; i < 9; i++)
        {
            contador = 0;
            for (j = 0; j < 9; j++)
            {
                if (*(ponteiro + i + (j * 9)) == num)
                    contador++;
            }
        }

        num++;
    }

    if (contador != 1)
        return 1;
    else
        return 0;
}

int verifVertical(int *ponteiro)
{
    int i, j, num = 1, contador = 1;

    while (contador == 1 && num < 10)
    {

        contador = 0;

        for (i = 0; i < 9; i++)
        {
            contador = 0;
            for (j = 0; j < 9; j++)
            {
                if (*(ponteiro + i + (j * 9)) == num)
                    contador++;
            }
        }

        num++;
    }

    if (contador != 1)
        return 1;
    else
        return 0;
}

int verifQuad(int *ponteiro) {
    int i, j, barramento = 0, num = 0, contaLinha = 0, contador = 0; 

    while (barramento < 9) {
        contador = 0;
        for (num = 1; num <= 9; num++) {
            for (i = 0 + contaLinha; i < 3 + contaLinha; i++) {
                for (j = 0 + barramento; j < 3 + barramento; j++) {
                    if (*(ponteiro + i * 9 + j) == num)
                        contador++;
                    printf("ponteiro = %d [%d][%d]\n", *(ponteiro + i * 9 + j), i, j);
                    if (contador > 1)
                        return 1;
                }
            }
        }
        barramento += 3;
        if (barramento == 9) {
            barramento = 0;
            contaLinha += 3;
        }
    }

    return 0;
}