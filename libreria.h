#ifndef _LIBRERIA_H
#define _LIBRERIA_H

// Librería.h = INTERFAZ entre comillas. Aquí solo se declaran los métodos

// Función que muestra las N primeras líneas de la entrada estándar.
// Devueve 0 en caso de éxito y -1 en caso de error.
int head(int N);

// Función que muestra las N últimas líneas de la entrada estándar.
// Devuelve 0 en caso de éxito y -1 en caso de error.
int tail(int N);

// Función que muestra las N líneas más largas de la entrada estándar,
// ordenadas de mayor a menor. Si hay menos de N líneas, muestra todas.
// Devuelve 0 en caso de éxito y -1 en caso de error.
int longlines(int N);

#endif // LIBRERIA_H
