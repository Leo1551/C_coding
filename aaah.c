#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int lajotaA;
    int lajotaB;
    int comprimentoSala;
    int larguraSala;
    int **desenho;
}sala;

void inicializarSala(sala *a);
void contarLajotas(sala *a);
void desenharSala(sala *a);
void liberarDesenho(sala *a);
int main(){

    sala  b, *a = &b;

    inicializarSala(a);
    contarLajotas(a);
    desenharSala(a);

    for (int i = 0; i < a->larguraSala; i++)
     for (int j = 0; j < a->comprimentoSala; j++)
     {
        printf("%d ", a->desenho[i][j]);
        if (j == (a->comprimentoSala) -1)
        putchar('\n');
        
     }
     
    
    printf("%d\n%d\n", a->lajotaA, a->lajotaB);

    liberarDesenho(a);

    return 0;
}

void liberarDesenho(sala *a){
    for (int i = 0; i < a->larguraSala; i++)
        free(a->desenho[i]);
    
    free(a->desenho);
}

void inicializarSala(sala *a){
    scanf("%d %d", &a->larguraSala, &a->comprimentoSala);
    
    a->desenho = calloc(a->larguraSala, sizeof(int));

    for (int i = 0; i < a->comprimentoSala; i++)
        a->desenho[i] = calloc(a->comprimentoSala, sizeof(int));
}

void contarLajotas(sala *a){

    a->lajotaA = (a->larguraSala * a->comprimentoSala) + ((a->larguraSala)-1) * ((a->comprimentoSala) - 1);

    a->lajotaB = (((a->larguraSala)-1) * 2) + (((a->comprimentoSala)- 1) * 2);
}

void desenharSala(sala *a){
    for (int i = 0; i < a->larguraSala; i++)
        for (int j = 0; j < a->comprimentoSala; j++)
        {
           
            if((j == 0 && i == 0))
             break;
            if(i == 0 && j == (a->larguraSala) -1)
             break;
            if(j == 0 && i == (a->comprimentoSala) -1)
             break;
           else if (j == 0 || j == (a->comprimentoSala) -1 || i == 0 || i == (a->larguraSala) -1)
                a->desenho[i][j] = 1;
           else
                a->desenho[i][j] = 2;
        }
}