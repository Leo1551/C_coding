#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void filoVertebrado();
void filoInvertebrado();
void grupoAve();
void grupoMamifero();
void grupoInseto();
void grupoAnelideo();

char* inicializador(){

    char *str = malloc(13 * sizeof(char));
    gets(str);
    return str;
}

int comparador(char *compara){
    char *str = inicializador();
    int retorno = strcmp(str, compara);
    free(str);
    return retorno;
}

int main(){

    if (comparador("invertebrado") == 0)
        filoInvertebrado();
    else
        filoVertebrado();
 
    return 0;
}

void filoVertebrado(){

    if (comparador("ave") == 0)
        grupoAve();
    else
        grupoMamifero();
}

void grupoAve(){
   
    if (comparador("carnivoro") == 0)
        printf("aguia\n");
    else
        printf("pomba\n");
}

void grupoMamifero(){
    if (comparador("onivoro") == 0)
        printf("homem\n");
    else
        printf("vaca\n");
}

void filoInvertebrado(){

    if (comparador("inseto") == 0)
        grupoInseto();
    else
        grupoAnelideo();
}

void grupoInseto(){

    if (comparador("hematofago") == 0)
        printf("pulga\n");
    else
        printf("lagarta\n");
}

void grupoAnelideo(){
    
    if (comparador("hematofago") == 0)
        printf("sanguessuga\n");
    else
        printf("minhoca\n");
}