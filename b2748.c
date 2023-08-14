#include <stdio.h>
#include<string.h>
void espacinho();
void posEspacinho();
void traco39();
void espaco();
int main(){

    traco39();
    espacinho();
    printf("Roberto");
    posEspacinho(29 - strlen("Roberto"));
    espaco();
    espacinho();
    printf("5786");
    posEspacinho(29 - strlen("5786"));
    espaco();
    espacinho();
    printf("UNIFEI");
    posEspacinho(29 - strlen("UNIFEI"));
    traco39();
    return 0;
}
void traco39(){
    printf("---------------------------------------\n");
}
void espaco(){
    printf("|                                     |\n");
}
void espacinho(){      
printf("|        ");
}
void posEspacinho(int tamanho){
    for (int i = 0; i < tamanho; i++)
    printf(" ");

    printf("|\n");
}


