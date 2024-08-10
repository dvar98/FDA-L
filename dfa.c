#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"

Transition transitions[MAX_TRANSITIONS];
int num_transitions = 0;

void load_dfa(DFA *dfa, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    char line[256];
    fgets(line, sizeof(line), file);
    char *token = strtok(line, ",\n");
    while (token) {
        dfa->states[dfa->num_states++] = strdup(token);
        token = strtok(NULL, ",\n");
    }

    fgets(line, sizeof(line), file);
    token = strtok(line, ",\n");
    while (token) {
        dfa->alphabet[dfa->num_symbols++] = strdup(token);
        token = strtok(NULL, ",\n");
    }

    fgets(line, sizeof(line), file);
    dfa->initial_state = strdup(line);
    dfa->initial_state[strcspn(dfa->initial_state, "\n")] = '\0';

    fgets(line, sizeof(line), file);
    token = strtok(line, ",\n");
    while (token) {
        dfa->accepting_states[dfa->num_accepting_states++] = strdup(token);
        token = strtok(NULL, ",\n");
    }

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",\n");
        transitions[num_transitions].current_state = strdup(token);

        token = strtok(NULL, ",\n");
        transitions[num_transitions].symbol = token[0];

        token = strtok(NULL, ",\n");
        transitions[num_transitions].next_state = strdup(token);

        num_transitions++;
    }

    fclose(file);
}

char* get_next_state(const char *current_state, char symbol) {
    for (int i = 0; i < num_transitions; i++) {
        if (strcmp(transitions[i].current_state, current_state) == 0 && transitions[i].symbol == symbol) {
            return transitions[i].next_state;
        }
    }
    return NULL;
}

int is_accepting_state(DFA *dfa, const char *state) {
    for (int i = 0; i < dfa->num_accepting_states; i++) {
        if (strcmp(dfa->accepting_states[i], state) == 0) {
            return 1;
        }
    }
    return 0;
}

void process_input(DFA *dfa, const char *input) {
    char *current_state = dfa->initial_state;

    for (int i = 0; input[i] != '\0'; i++) {
        current_state = get_next_state(current_state, input[i]);
        if (current_state == NULL) {
            printf("Cadena rechazada.\n");
            return;
        }
    }

    if (is_accepting_state(dfa, current_state)) {
        printf("La cadena fue aceptada.\n");
    } else {
        printf("La cadena fue rechazada.\n");
    }
}

void free_dfa(DFA *dfa) {
    for (int i = 0; i < dfa->num_states; i++) {
        free(dfa->states[i]);
    }
    for (int i = 0; i < dfa->num_symbols; i++) {
        free(dfa->alphabet[i]);
    }
    for (int i = 0; i < dfa->num_accepting_states; i++) {
        free(dfa->accepting_states[i]);
    }
}

void free_transitions() {
    for (int i = 0; i < num_transitions; i++) {
        free(transitions[i].current_state);
        free(transitions[i].next_state);
    }
}