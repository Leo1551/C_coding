#include<stdio.h>
#include<string.h>
void umOuDois(char *str);
int encontraDois(char **str);
int main(){

    int numeroPalavras;
    char str[6];

    scanf("%d", &numeroPalavras);
    getchar();

    for (int i = 0; i < numeroPalavras; i++){
        gets(str);

        if (strlen(str) == 5)
            printf("3\n");
        else
            umOuDois(str);
    }
    return 0;
}
int encontraDois(char **str){
    char compara[] = "two";
    int retorno = 0;
    for (int i = 0; i < 3; i++)
        if ((*str)[i] == compara[i])
            retorno++;

    return retorno;
    
}
void umOuDois(char *str){
    if (encontraDois(&str) >= 2)
        printf("2\n");
    else
        printf("1\n");

}
