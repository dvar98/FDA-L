# DFA en C

Este proyecto implementa un Autómata Finito Determinista (DFA) en lenguaje C. El DFA es configurable a través de un archivo de texto que especifica los estados, el alfabeto, las transiciones, el estado inicial y los estados de aceptación.

## Estructura del Proyecto

El proyecto está dividido en los siguientes archivos:

- *main.c*: Contiene la función principal del programa y maneja la interacción con el usuario.
- *dfa.c*: Implementa las funciones que manejan el DFA, incluyendo la carga de configuración, la evaluación de cadenas y la gestión de memoria.
- *dfa.h*: Declara las estructuras y funciones utilizadas en dfa.c y main.c.

## Archivo de Configuración

El archivo de configuración tiene el siguiente formato:

1. *Primera línea*: Conjunto de estados (Q), separados por comas.
2. *Segunda línea*: Alfabeto (Σ), separado por comas.
3. *Tercera línea*: Estado inicial (q0).
4. *Cuarta línea*: Estados de aceptación (F), separados por comas.
5. *Siguientes líneas*: Transiciones en el formato estado_actual,símbolo,estado_siguiente.

### Ejemplo de archivo de configuración

```
q0,q1,q2
a,b
q0
q2
q0,a,q1
q1,b,q2
q2,a,q0
q2,b,q1

```

## Instrucciones de Compilación

Para compilar el proyecto, usa el siguiente comando:

```sh
gcc -o dfa_program main.c dfa.c
```

Esto generara un ejecutable llamado `dfa_program`.

## Instrucciones de Uso

1. **Ejecuta el programa**:

```sh
./dfa_program
```

2. **Ingrese el nombre del archivo de configuracion**.Asegurarse de que el archivo siga el formato especificado (.txt)

3. **Introduce una cadena de entrada que quieras procesar con el DFA**

4. **El programa indicara si la cadena fue aceptada o rechazada**


##Integrantes 
**Daniel Santiago Varela Guerrero**
**Miguel Angel Velasco**
**Sebastian Sabogal Castillo**
