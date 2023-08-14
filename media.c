#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int notaParaAno(int notas);
void mediaAno(int notas, int bimestre);
void linhas();
int main()
{

    int notas[15], bimestre, quantidadeALer;
    char **materia = malloc(sizeof(char*) * 15);

    puts("insira quantas materrias e qual seu bimestre atual");
    scanf("%d %d", &quantidadeALer, &bimestre);
    
    for (int i = 0; i < quantidadeALer; i++){
        puts("Insira materia");
           scanf("%s", materia[i]);
        puts("Insira notas");
            scanf("%d", &notas[i]);
        
    }
    for (int j = 0; j < quantidadeALer; j++){
        linhas();
        printf("           ");
        puts(materia[j]);
        linhas();
        printf("Media de notas para passar de ano em %s:\n", materia[j]);
            mediaAno(notaParaAno(notas[j]), bimestre - 1);
        puts("nota total para passar de ano:");
            printf("%d\n", notaParaAno(notas[j]));
       
        free(materia[j]);
        }

        free(materia);
    return 0;
}
void mediaAno(int notas, int bimestre){
    double media;
    media = notas/(4 - bimestre);

    printf("%.1lf p/bimestre\n", media);
}
int notaParaAno(int notas){
    return 60 - notas;
}
void linhas(){
    printf("========================\n");
}