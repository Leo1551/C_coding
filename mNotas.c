#include <stdio.h>
#include <stdlib.h>
 
int main() {
 
    int fRicardo, fVicente, testes, *v, resto, aux;
    
    scanf("%d", &testes);

    v = malloc(testes * sizeof(int));
    
    for(int i = 0; i < testes; i++){
        scanf("%d %d", &fRicardo, &fVicente);

        if (fVicente > fRicardo)
        {
            aux = fVicente;
            fVicente = fRicardo;
            fRicardo = aux;
        }
        
        
        while (fVicente != 0){
            resto = fRicardo % fVicente;
            fRicardo = fVicente;
            fVicente = resto;
        }
        
        *(v + i) = fRicardo;
                  
    }
     for(int k = 0; k < testes; k++)
        printf("%d\n", v[k]);

    
    free(v);

 
    return 0;
}