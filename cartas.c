#include<stdio.h>

void carregar;

int main(){


    int matriz[100][100], tamanho, i, j;


    while(scanf("%d", &tamanho) != 0){

        for(i = 0; i< tamanho; i++){
            for(j=0; j < tamanho; j++){
                if(j + 1 <  tamanho - j + 1)
                    matriz[i][j] = tamanho - j + 1; 
                else
                    matriz[i][j] = j + 1;
            }
            if(i + 1 <  tamanho - i + 1)
                    matriz[i][j] = tamanho - i + 1; 
                else
                    matriz[i][j] = i+ 1;
         }


    }
}