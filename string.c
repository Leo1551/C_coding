#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **carregarStrings(char **str, int qtd);
char **lerLinhaStrings(char **str, int tam);
int EncontrarMaiorString(char **str, int tam);
int removerEspacosExtras(char *str,int len);
char **trocarNewLine(char **str,int tam);
void FormatarString(char **str,int qtd,int Mstr);
void Liberar(char ***str, int tam);
int main()
{
    char **str;
    int qtd, Mstr = 0;


    scanf("%d", &qtd);

    while (qtd != 0)
    {
        str = carregarStrings(str, qtd);
        str = lerLinhaStrings(str, qtd);
        for (int i = 0; i < qtd; i++)
            puts(str[i]);
        
        Mstr = EncontrarMaiorString(str, qtd);
        FormatarString(str, qtd, Mstr);
        Liberar(&str, qtd);
         scanf("%d", &qtd);
    }
    return 0;
}

char **carregarStrings(char **str, int qtd){
    str = malloc(sizeof(char*) * qtd);
    for (int i = 0; i < qtd; i++)
        str[i] = malloc(sizeof(char) * 50);
    return str;
}

char **lerLinhaStrings(char **str, int tam){
    getchar();
    for (int i = 0; i < tam; i++)
        gets(str[i]);
     for (int j = 0; j < tam; j++)
        puts(str[j]);
    str = trocarNewLine(str, tam);
   
    
    return str;
}
char **trocarNewLine(char **str,int tam){
    for (int i = 0; i < tam; i++)
        for (int j = 50; str[i][j - 1] != '\n'; j--)
            str[i][j - 1] = '\0';
    return str;
}
int EncontrarMaiorString(char **str, int tam){
        int len, maiorStr = 0;
    for (int i = 0; i < tam; i++){
        len = strlen(str[i]);
        len = removerEspacosExtras(str[i], len);
         if (len > maiorStr)
            maiorStr = len;    
    }
    return maiorStr;
}
int removerEspacosExtras(char *str,int len){
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0'; // Certificar-se de que a string esteja corretamente terminada
    return strlen(str);
}
void Liberar(char ***str, int tam){
    for (int i = 0; i < tam; i++)
        free((*str)[i]);

    free(*str);
}
void FormatarString(char **str,int qtd,int Mstr){
    int len;
    for (int i = 0; i < qtd; i++){
       len = strlen(str[i]);
       for (int j = 0; j < Mstr - len; j++)
        putchar(' ');
       puts(str[i]);
    }
}