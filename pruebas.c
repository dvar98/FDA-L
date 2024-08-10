#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de estructuras
typedef struct {
    char* estado;
    char* simbolo;
    char* siguiente_estado;
} Transicion;

typedef struct {
    char** estados;
    int num_estados;
    char** alfabeto;
    int num_simbolos;
    Transicion* transiciones;
    int num_transiciones;
    char* estado_inicial;
    char** estados_aceptacion;
    int num_estados_aceptacion;
} DFA;

// Función para leer el archivo de configuración
DFA* leer_archivo_configuracion(const char* nombre_archivo) {
    // Abrir archivo
    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) {
        printf("Error al abrir el archivo\n");
        return NULL;
    }

    // Leer estados
    char linea[1024];
    fgets(linea, 1024, archivo);
    DFA* dfa = malloc(sizeof(DFA));
    dfa->estados = malloc(sizeof(char*) * 10); // Suponiendo un máximo de 10 estados
    dfa->num_estados = 0;
    char* token = strtok(linea, ",");
    while (token) {
        dfa->estados[dfa->num_estados] = malloc(strlen(token) + 1);
        strcpy(dfa->estados[dfa->num_estados], token);
        dfa->num_estados++;
        token = strtok(NULL, ",");
    }

    // Leer alfabeto
    fgets(linea, 1024, archivo);
    dfa->alfabeto = malloc(sizeof(char*) * 10); // Suponiendo un máximo de 10 símbolos
    dfa->num_simbolos = 0;
    token = strtok(linea, ",");
    while (token) {
        dfa->alfabeto[dfa->num_simbolos] = malloc(strlen(token) + 1);
        strcpy(dfa->alfabeto[dfa->num_simbolos], token);
        dfa->num_simbolos++;
        token = strtok(NULL, ",");
    }

    // Leer estado inicial
    fgets(linea, 1024, archivo);
    dfa->estado_inicial = malloc(strlen(linea) + 1);
    strcpy(dfa->estado_inicial, linea);

    // Leer estados de aceptación
    fgets(linea, 1024, archivo);
    dfa->estados_aceptacion = malloc(sizeof(char*) * 10); // Suponiendo un máximo de 10 estados de aceptación
    dfa->num_estados_aceptacion = 0;
    token = strtok(linea, ",");
    while (token) {
        dfa->estados_aceptacion[dfa->num_estados_aceptacion] = malloc(strlen(token) + 1);
        strcpy(dfa->estados_aceptacion[dfa->num_estados_aceptacion], token);
        dfa->num_estados_aceptacion++;
        token = strtok(NULL, ",");
    }

    // Leer transiciones
    dfa->transiciones = malloc(sizeof(Transicion) * 100); // Suponiendo un máximo de 100 transiciones
    dfa->num_transiciones = 0;
    while (fgets(linea, 1024, archivo)) {
        Transicion transicion;
        token = strtok(linea, ",");
        transicion.estado = malloc(strlen(token) + 1);
        strcpy(transicion.estado, token);
        token = strtok(NULL, ",");
        transicion.simbolo = malloc(strlen(token) + 1);
        strcpy(transicion.simbolo, token);
        token = strtok(NULL, ",");
        transicion.siguiente_estado = malloc(strlen(token) + 1);
        strcpy(transicion.siguiente_estado, token);
        dfa->transiciones[dfa->num_transiciones] = transicion;
        dfa->num_transiciones++;
    }

    // Cerrar archivo
    fclose(archivo);

    return dfa;
}

// Función para procesar la cadena de entrada
int procesar_cadena(DFA* dfa, const char* cadena) {
    char* estado_actual = dfa->estado_inicial;
    for (int i = 0; i < strlen(cadena); i++) {
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

int main() {
    printf("Ingrese el nombre del archivo de configuración: ");
    char nombre_archivo[1024];
    scanf("%s", nombre_archivo);
    DFA* dfa = leer_archivo_configuracion(nombre_archivo);
    if (!dfa) {
        return 1;
    }
    printf("Ingrese la cadena de entrada: ");
    char cadena[1024];
    scanf("%s", cadena);
    procesar_cadena(dfa, cadena);
    return 0;
}
