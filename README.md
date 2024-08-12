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

- Abre una terminal y utiliza el comando `cd` para moverte a la carpeta donde guardaste los archivos del proyecto.

- Una vez en la carpeta del proyecto, compila el programa utilizando el siguiente comando:

```sh
gcc -o dfa_program main.c dfa.c
```

Esto generara un ejecutable llamado `dfa_program`.

## Instrucciones de Uso

1. **Ejecuta el programa**:

 - En la terminal, dentro de la carpeta del proyecto, ejecuta el siguiente comando para iniciar el programa:

```sh
./dfa_program
```

2. **Ingresar el Nombre del Archivo de Configuración**

El programa te pedirá que ingreses el nombre del archivo de configuración que contiene los detalles del DFA. Escribe el nombre del archivo y presiona Enter. Asegúrate de que el archivo esté en la misma carpeta que el programa y siga el formato especificado con la extensión `.txt`.

**Ejemplo**: Si tu archivo de configuración se llama `config.txt`, escribe `config.txt` y presiona Enter.

3. **Introducir una Cadena de Entrada**

Luego de cargar el archivo de configuración, el programa te pedirá que ingreses una cadena de caracteres para procesar con el DFA. Escribe la cadena que deseas analizar y presiona Enter.

**Ejemplo**: Si deseas probar la cadena `abab`, escribe `abab` y presiona Enter.

4. **Interpretar el Resultado**

El programa analizará la cadena de entrada de acuerdo con las reglas definidas en el archivo de configuración. Finalmente, te indicará si la cadena fue aceptada o rechazada por el DFA.

**Ejemplo de salida**: `Resultado: La cadena fue aceptada.`

Si la cadena no cumple con los criterios del DFA, el programa mostrará: `Resultado: La cadena fue rechazada.`

5. **Repetir o Salir**

Puedes repetir el proceso con diferentes cadenas de entrada o utilizar otro archivo de configuración si lo deseas. Simplemente ejecuta de nuevo el programa.

Para salir, simplemente cierra la terminal o presiona `Ctrl+C` para detener el programa en cualquier momento.



## Integrantes

- **Daniel Santiago Varela Guerrero**
- **Miguel Angel Velasco**
- **Sebastian Sabogal Castillo**
