#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"

int main() {
    DFA dfa = {0};

    char filename[256];
    printf("Ingrese el nombre del archivo de configuración: ");
    scanf("%s", filename);

    load_dfa(&dfa, filename);

    char input[256];
    printf("Ingrese la cadena de entrada: ");
    scanf("%s", input);

    process_input(&dfa, input);

    free_dfa(&dfa);
    free_transitions();
    return 0;
}