#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int *e;
  int *d;
}L_Bota;

typedef struct 
{
  L_Bota *tipo_Bota;
  int somatorio;
  char lado_Bota;
}Inventario;

void carregarInventario(int qtdBotas, Inventario *i);
void carregarBotas(int qtd_Total,Inventario *i);
void somarPares(Inventario *i);
int menor(int numero_Bota, Inventario *i);
void liberar(Inventario *i);

int main(){

  Inventario i;
  int Qtd_Botas;

  while (scanf("%d", &Qtd_Botas) != EOF)
  {
    carregarInventario(Qtd_Botas, &i);

    carregarBotas(Qtd_Botas,&i);
 
    somarPares(&i);
    printf("%d\n", i.somatorio);
    liberar(&i);
  }
  
  return 0;
}

int menor(int numero_Bota, Inventario *i){
  if(*(i->tipo_Bota->d + numero_Bota) < *(i->tipo_Bota->e + numero_Bota))
    return *(i->tipo_Bota->d + numero_Bota);
  else
    return *(i->tipo_Bota->e + numero_Bota);

}

void somarPares(Inventario *i){

 
  i->somatorio = 0;

    for (int j = 30; j < 61; j++){
      if (*(i->tipo_Bota->e + j) != 0 && *(i->tipo_Bota->d + j) != 0){
        i->somatorio += menor(j,i);
      }
    }
    
}

void carregarBotas(int qtd_Total,Inventario *i){

    int tamanho_Bota;

    while(qtd_Total > 0){
      scanf("%d %c", &tamanho_Bota, &(i->lado_Bota));
  
      if (i->lado_Bota == 'E')
        *(i->tipo_Bota->e + tamanho_Bota)+= 1;
      else
        *(i->tipo_Bota->d + tamanho_Bota)+= 1;
      
     qtd_Total--; 
    }
}

void carregarInventario(int qtdBotas, Inventario *i){
    
    i->tipo_Bota->d = (int*) malloc(qtdBotas * 1000);
    i->tipo_Bota->e = (int*) malloc(qtdBotas * 1000);
    
    for (int j = 30; j < 61; j++)
    {
      *(i->tipo_Bota->d + j) = *(i->tipo_Bota->e + j) = 0;
    }
    
}
void liberar(Inventario *i){
  if (i->tipo_Bota->d != NULL && i->tipo_Bota->e != NULL)
  {
   free(i->tipo_Bota->d);
   free(i->tipo_Bota->e);
  }
}