#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int comparador(int pessoas, char* exemplo);

int main(){
    int quantantidadeConversas, pessoas;
    char exemplificacao[20];

    scanf("%d", &quantantidadeConversas);
    
    while (quantantidadeConversas > 0){

        scanf("%d", &pessoas);
        getchar();

        gets(exemplificacao);
       
        if (comparador(pessoas, exemplificacao) != 0)
            printf("ingles\n");
        else
            printf("%s\n", exemplificacao);

        quantantidadeConversas--;
    }
    
    return 0;
}

int comparador(int pessoas, char* exemplo){
    char str[20];
    int turn = 0;
    for (int i = 1; i < pessoas; i++){
        gets(str);
        if (strcmp(str,exemplo) != 0)
            turn = 1;
    }
    return turn; 
}