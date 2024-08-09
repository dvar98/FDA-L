#include "dfa_dao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DFA* dfa_crear(const char* nombre_archivo){

    FILE *pf;
    pf =  fopen("datos", "r+");
    if (pf == NULL)
    {
        printf("Error el archivo no existe");
        exit(EXIT_FAILURE);
    }
    
    fclose(pf);
    return EXIT_SUCCESS;
}