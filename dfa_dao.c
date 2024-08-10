#include "dfa_dao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DFA* dfa_crear(const char* nombre_archivo){

    FILE *pf;
    pf =  fopen( nombre_archivo, "r");
    if (pf == NULL)
    {
        printf("Error el archivo no existe");
        return NULL;
    }
    

    // Obtener los estados
    char estado[2000];
    fgets(estado,2000,pf);
    DFA* dfa = malloc(sizeof(DFA));
    dfa -> estados = malloc(sizeof(char*) * 20);
    dfa -> num_estados = 0;
    char* separador = strtok(estado, ",");
    while (separador)
    {
        dfa -> estados[dfa -> num_estados] = malloc(strlen(separador) + 1);
        strcpy(dfa -> estados[dfa -> num_estados], separador);
        dfa -> num_estados++;
        separador = strtok(NULL, ",");
    }

    // Leer alfabeto
    char alfabeto[2000];
    fgets(alfabeto,2000,pf);
    dfa->alfabeto = malloc(sizeof(char*) * 20);
    dfa->num_simbolos = 0;
    separador = strtok(alfabeto, ",");
    while (separador)
    {
        dfa->alfabeto[dfa->num_simbolos] = malloc(strlen(separador) + 1);
        strcpy(dfa->alfabeto[dfa->num_simbolos], separador);
        dfa->num_simbolos++;
        separador = strtok(NULL, ",");
    }
    
    //Leer estado inicial
    fgets(estado,2000,pf);
    dfa ->estado_inicial = malloc(strlen(estado)+1);
    strcpy(dfa -> estado_inicial, estado);

    //estados finalizacion
    fgets(estado,2000,pf);
    dfa -> estados_aceptacion = malloc(sizeof(char*) * 10);
    dfa ->num_estados_aceptacion = 0;
    separador = strtok(estado, ",");
    while (separador)
    {
        dfa -> estados_aceptacion[dfa-> num_estados_aceptacion] =  malloc(strlen(separador) +1);
        strcpy(dfa -> estados_aceptacion[dfa -> num_estados_aceptacion], separador);
        dfa -> num_estados_aceptacion++;
        separador = strtok(NULL, ",");

    }

    // Leer transiciones
    dfa->transiciones = malloc(sizeof(Transicion) * 100);
    dfa->num_transiciones = 0;
    char transicion[2000];
    while (fgets(transicion, 2000, pf)) {
        Transicion t;
        char* estado = strtok(transicion, ",");
        t.estado = malloc(strlen(estado) + 1);
        strcpy(t.estado, estado);
        char* simbolo = strtok(NULL, ",");
        t.simbolo = malloc(strlen(simbolo) + 1);
        strcpy(t.simbolo, simbolo);
        char* siguiente_estado = strtok(NULL, ",");
        t.siguiente_estado = malloc(strlen(siguiente_estado) + 1);
        strcpy(t.siguiente_estado, siguiente_estado);
        dfa->transiciones[dfa->num_transiciones] = t;
        dfa->num_transiciones++;
    }

    fclose(pf);
    return dfa;
}

void dfa_destruir(DFA* dfa) {
    // Liberar memoria de los estados
    for (int i = 0; i < dfa->num_estados; i++) {
        free(dfa->estados[i]);
    }
    free(dfa->estados);

    // Liberar memoria del alfabeto
    for (int i = 0; i < dfa->num_simbolos; i++) {
        free(dfa->alfabeto[i]);
    }
    free(dfa->alfabeto);

    // Liberar memoria del estado inicial
    free(dfa->estado_inicial);

    // Liberar memoria de los estados de aceptación
    for (int i = 0; i < dfa->num_estados_aceptacion; i++) {
        free(dfa->estados_aceptacion[i]);
    }
    free(dfa->estados_aceptacion);

    // Liberar memoria de las transiciones
    for (int i = 0; i < dfa->num_transiciones; i++) {
        free(dfa->transiciones[i].estado);
        free(dfa->transiciones[i].simbolo);
        free(dfa->transiciones[i].siguiente_estado);
    }
    free(dfa->transiciones);

    // Liberar memoria del DFA
    free(dfa);
}


int dfa_procesar_cadena(DFA* dfa, const char* cadena){
    char* estado_actual = dfa->estado_inicial;
    for (size_t i = 0; i < strlen(cadena); i++) {
        char simbolo = cadena[i];
        int encontrado = 0;
        for (int j = 0; j < dfa->num_transiciones; j++) {
            if (strcmp(dfa->transiciones[j].estado, estado_actual) == 0 &&
                dfa->transiciones[j].simbolo[0] == simbolo) {
                estado_actual = dfa->transiciones[j].siguiente_estado;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Error: transición no definida\n");
            return 0;
        }
    }
    // Verificar si el estado actual es de aceptación
    for (int i = 0; i < dfa->num_estados_aceptacion; i++) {
        if (strcmp(estado_actual, dfa->estados_aceptacion[i]) == 0) {
            printf("La cadena fue aceptada\n");
            return 1;
        }
    }
    printf("La cadena fue rechazada\n");
    return 0;
}
