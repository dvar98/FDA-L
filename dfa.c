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
    // Imprimir estados del DFA
    printf("Estados del DFA: \n");
    for (int i = 0; i < dfa->num_estados; i++) {
        printf("%s ", dfa->estados[i]);
    }
    printf("\n");

    // Imprimir alfabeto del DFA
    printf("Alfabeto del DFA: \n");
    for (int i = 0; i < dfa->num_simbolos; i++) {
        printf("%s ", dfa->alfabeto[i]);
    }
    printf("\n");

    // Imprimir estado inicial del DFA
    printf("Estado inicial del DFA: %s\n", dfa->estado_inicial);

    // Imprimir estados de aceptación del DFA
    printf("Estados de aceptación del DFA: \n");
    for (int i = 0; i < dfa->num_estados_aceptacion; i++) {
        printf("%s ", dfa->estados_aceptacion[i]);
    }
    printf("\n");
    
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
