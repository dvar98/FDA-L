#ifndef DFA_DAO_H
#define DFA_DAO_H

typedef struct
{
    char* estado;
    char* simbolo;
    char* siguiente_estado;
}Transicion;

typedef struct
{
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

DFA* dfa_crear(const char* nombre_archivo);
void dfa_destruir(DFA* dfa);
int dfa_procesar_cadena(DFA* dfa, const char* cadena);

#endif
