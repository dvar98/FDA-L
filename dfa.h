#ifndef DFA_H
#define DFA_H

#define MAX_STATES 100
#define MAX_SYMBOLS 100
#define MAX_TRANSITIONS 100

typedef struct {
    char *states[MAX_STATES];
    char *alphabet[MAX_SYMBOLS];
    char *initial_state;
    char *accepting_states[MAX_STATES];
    int num_states;
    int num_symbols;
    int num_accepting_states;
} DFA;

typedef struct {
    char *current_state;
    char symbol;
    char *next_state;
} Transition;

// Funciones para manejar el DFA
void load_dfa(DFA *dfa, const char *filename);
char* get_next_state(const char *current_state, char symbol);
int is_accepting_state(DFA *dfa, const char *state);
void process_input(DFA *dfa, const char *input);
void free_dfa(DFA *dfa);
void free_transitions();

#endif 