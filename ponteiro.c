#include<stdio.h>

void lerSudoku(int *ponteiro);
int verifHorizontal(int *ponteiro);
int verifVertical(int *ponteiro);


int main(){

    int vetor[81], qtdSudokus;
    int *ponteiro, saida = 0;

    ponteiro = vetor;

    scanf("%d", &qtdSudokus);

    for(int i = 0; i < qtdSudokus; i++)
    {
        lerSudoku(ponteiro);

        saida += verifHorizontal(ponteiro);
        saida += verifVertical(ponteiro);

        printf("Instancia %d\n", i + 1);


        if(saida == 0)
            printf("SIM\n");
        else 
            printf("NAO\n");

    }
    return 0;
}
void lerSudoku(int *ponteiro)
{
    int i;

    for(i = 0; i < 81; i++)
            scanf("%d", (ponteiro + i));

}

int verifHorizontal(int *ponteiro)
{
    int i, j, num = 0, contador = 1;

    while(contador == 1 && num < 10){

            contador = 0;
            
        for(i = 0; i < 9; i++)
         for(j = 0; j < 9; j++){
            if(*(ponteiro + (i*9) + j) == num)
                contador++;

         }
            
            printf("%d passada numero %d horizontal\n", contador, num+1);
        num++;
    }
        
    if(contador != 1)
        return 1;
    else
        return 0;
}
int verifVertical(int *ponteiro)
{
     int i, j, num = 0, contador = 1;

    while(contador == 1 && num < 10){
            contador = 0;
        for(i = 0; i < 9; i++)
         for(j = 0; j < 9; j++){
            if(*(ponteiro + i + (j*9)) == num)
                contador++;

         }
            
            printf("%d passada numero %d vertical\n", contador, num+1);
        num++;
    }
        
    if(contador != 1)
        return 1;
    else
        return 0;
}