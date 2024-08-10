#include "dfa_dao.h"
#include <stdio.h>

int main(){

    printf("Ingrese el nombre del archivo de configuracion:");
    char pf[2000];
    scanf("%s", pf);
    DFA* dfa = dfa_crear(pf);
    if (!dfa)
    {
        return 1;
    }
    printf("Ingrese la cadena de entrada: ");
    char cadena[2000];
    scanf("%s", cadena);
    int resultado = dfa_procesar_cadena(dfa, cadena);
    if (resultado)
    {       
        printf("La cadena fue aceptada \n");
    }else{
        printf("La cadena fue rechazada \n");
    }

    dfa_destruir(dfa);
    return 0;
}