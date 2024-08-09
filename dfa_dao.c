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
    

    //Obtener los estados
    char estado[2000];
    fgets(estado,2000,nombre_archivo);
    DFA* dfa = malloc(sizeof(DFA));
    dfa -> estados = malloc(sizeof(char*) * 20);
    dfa -> num_estados = 0;
    char* separador = strtok(estado, ",");
    while (separador)
    {
        dfa -> estados[dfa -> num_estados] = malloc(strlen(separador) + 1);
        strcpy(dfa -> estados[dfa -> num_estados], separador);
        dfa -> num_estados++;
        token

    }
    


    fclose(pf);
    return dfa;
}