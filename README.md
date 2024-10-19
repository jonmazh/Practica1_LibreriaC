# Práctica 1 - Sistemas Operativos (2024-2025)

### Programación de una Librería en C

| Autor                     | GitHub                                   |
|---------------------------|------------------------------------------|
| **Jon Mazcuñán Hernández** | [jonmazh](https://github.com/jonmazh) |
| **Alejandro Rico González**| //TODO |
---

## Descripción

Este proyecto implementa una librería en C con funcionalidades similares a los comandos `head` y `tail` de Unix, así como una función adicional para mostrar las líneas más largas de la entrada estándar.

### Funcionalidades principales de la librería:

- **`int head(int N)✅`**  
  Muestra las primeras N líneas recibidas por la entrada estándar.

- **`int tail(int N)`**  
  Muestra las últimas N líneas recibidas por la entrada estándar.

- **`int longlines(int N)`**  
  Muestra las N líneas más largas recibidas por la entrada estándar, ordenadas de mayor a menor.

---

## Estructura del proyecto

El repositorio incluye los siguientes archivos:

- **`libreria.c`**  
  Código fuente con las funciones `head`, `tail` y `longlines`.

- **`libreria.h`**  
  Archivo de cabecera con las definiciones de las funciones (no debe modificarse).

- **`test.c`**  
  Programa de prueba que verifica el funcionamiento de la librería. Acepta los siguientes parámetros:
  ```bash
  ./test -<función> [número de líneas]

- **`script.sh`**
  Script para generar la librería estática libreria.h, compilar el programa de prueba (test.c) y enlazarlo con la librería.

---

  ## Objetivos de la Práctica

- **Reconocimiento de argumentos en línea de comandos**  
  El programa principal `test` debe ser capaz de recibir y procesar correctamente los argumentos de la línea de comandos para ejecutar las funciones de la librería. Se debe manejar tanto la especificación de la función a ejecutar (`-head`, `-tail`, `-longlines`) como el número de líneas (opcional).

- **Control adecuado de errores**  
  Se debe implementar una gestión robusta de errores, incluyendo la validación de argumentos de entrada y el manejo adecuado de situaciones excepcionales (por ejemplo, que el número de líneas no sea válido o que no se pueda leer la entrada estándar).

- **Ejecución correcta de las funcionalidades**  
  Las tres funciones principales (`head`, `tail`, `longlines`) deben comportarse conforme a las especificaciones del enunciado. Deben mostrar el número correcto de líneas en la salida estándar según los parámetros indicados por el usuario.

- **Uso de memoria dinámica**  
  Se debe utilizar memoria dinámica para gestionar arrays de tamaño variable de forma eficiente. Las funciones `malloc`, `calloc`, `realloc` y `free` deben emplearse correctamente, asegurándose de liberar la memoria asignada antes de finalizar el programa.

- **Simplicidad y calidad del código**  
  El código debe ser claro, legible y estar debidamente comentado, cumpliendo con las normas de estilo establecidas en el enunciado. Además, se debe evitar el uso de construcciones de C++ y se deben minimizar los avisos o `warnings` durante la compilación.
