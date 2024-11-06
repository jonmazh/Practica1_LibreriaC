#include <stdio.h> 
#include "libreria.h"
#include <errno.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 

/**
 * Mostrar las N primeras líneas de la entrada estándar
 * @param size Tamaño máximo para una línea
 * @param counter Contador para saber las líneas que se han leído 
 * @param lines Líneas que se van a devolver.
 * @return lines.
 */
int head(int nLines) 
{
	char *MSGERR = "Use ./libreria.c head [DIRECTORIO].";
	int size = 15, counter = 0;
	int i = 0, j = 0; 
	char **lines; 

	lines = (char **)malloc(size * sizeof(char *)); 
	if (lines == NULL){
		printf("%s",MSGERR); 
		return -1; 
	}

	//Asignación de memoria dinámica a lines
	for (i ; i < nLines ; i++){
		lines[i] = (char *)malloc(1024 * sizeof(char)); 
		if (lines[i] == NULL){
			for (j ; j < nLines ; j++){
				free(lines[j]);
			}
			free(lines);
			return -1; 
		}
	}

	//Recorrido de stdin para acumular lineas en lines
	while (counter < nLines){
		if (fgets(lines[counter], 1024, stdin)){
			puts(lines[counter]);
			counter++; 
		}
		else if (feof(stdin)){
			break; 
		}
		else{
			for (j = 0 ; j < i ; j++){
				free(lines[j]);
			}
			free(lines);
			return -1; 
		}
	}

	for (i = 0 ; i < nLines ; i++){ 
		free(lines[i]);
	}

	free(lines); 
	return 0; 

	//EOF HEAD
}



/**
 * Función que muestra las N últimas líneas de la entrada estándar.
 * @param counter Contador para saber las líneas que se han leído 
 * @param lines Líneas que se van a devolver.
 * @param stdin_size Número de líneas que nos introducen, para gestionar errores.
 * @return 0 si ha habido exito, -1 si ha habido algún error.
 */
int tail(int nLines){
	char **lines; 
	int i, j, counter = 0, stdin_size = 0, auxCounter ; 
	
	//Asignación de memoria a lines y buffer
	lines = (char **)malloc(nLines*sizeof(char *)); 
	if (lines == NULL){
		return -1; 
	}

	//Asignación de memoria de cada línea a lines
	for(i = 0; i<nLines; i++){
		lines[i] = (char *)malloc(1024*sizeof(char));
		if (lines[i]==NULL){
			for (j = 0; j < i; j++){
				free(lines[j]);
			}
			free(lines);
			return -1; 
			}
	}

	while(fgets(lines[counter], 1024, stdin) != NULL){
		counter = (counter + 1) % nLines; 
		stdin_size++; 
	}

	if (nLines>stdin_size){
		return -1; 
	}

	auxCounter = counter ;
	for (i = 0 ; i<nLines ; i++){
		puts(lines[auxCounter]); 
		free(lines[auxCounter]); 
		auxCounter = (auxCounter+1)%nLines; 
	}
	free(lines); 

	return 0 ; 
}


/**
 * Función que ordena líneas de mayor a menor longitud.
 * @param aux2 Estructura de datos que almacena la línea a cambiar
 */
void order_lines(char **lines, int *lengths, int count){
	int i, j, aux;
	char aux2[1024];

	// Ordenar las líneas de mayor a menor longitud usando bubble sort
	for (i = 0; i < count; i++){
		for (j = i+1; j < count; j++){
			if (lengths[i] < lengths[j]){
				aux = lengths[i];
				lengths[i] = lengths[j];
				lengths[j] = aux;

				strcpy(aux2, lines[i]);
				strcpy(lines[i], lines[j]);
				strcpy(lines[j], aux2);
			}
		}
	}
}



/**
 * Función que muestra N líneas de la E/S ordenadas de mayor a menor longitud.
 * @param lines Arreglo que se encarga de almacenar las líneas de entrada estándar.
 * @param lengths Arreglo que se encarga de almacenar las longitudes de las líneas.
 * @param count Números de líneas introducidas por E/S. 
 * @param buffer Estructura que almacena cada línea de la E/S. 
 * @return Int, 0 si ejecuta correctamente y -1 si no. 
 */
int longlines (int nLines) {

	int capacity = 100;
	char **lines = (char **)malloc(capacity * sizeof(char *));
	int *lengths = (int *)malloc(capacity * sizeof(int));
	int count = 0;
	int max_length = 1024; 
	int i, j;
	char buffer[max_length];

	// Comprobar si se ha asignado memoria correctamente
	if (lines == NULL || lengths == NULL){
		free(lines);
		free(lengths);
		return -1;
	}

	// Asignar memoria a cada línea de lines y a lengths
	for(i = 0; i < capacity; i++){
		lines[i] = (char *)malloc(max_length*sizeof(char));
		if (lines[i]==NULL){
			for (j = 0; j < i; j++){
				free(lines[j]);
			}

			free(lines);
			free(lengths);
			return -1; 
		}
	}
	
	// Leer las líneas de la entrada estándar y almacenarlas en el array lines y en el array lengths
	while(fgets(buffer, max_length, stdin) != NULL){
		if (count >= capacity){
			capacity *= 2;

			lines = (char **)realloc(lines, capacity * sizeof(char *));
			lengths = (int *)realloc(lengths, capacity * sizeof(int));

			if (lines == NULL || lengths == NULL){
				for (i = 0; i < count; i++){
                	free(lines[i]);
            	}

				free(lines);
				free(lengths);
				return -1;
			}

			
			for(i = count; i < capacity; i++){
				lines[i] = (char *)malloc(max_length*sizeof(char));
				if (lines[i]==NULL){
					for (j = 0; j < i; j++){
						free(lines[j]);
					}

					free(lines);
					free(lengths);
					return -1; 
				}
			}
		}

		strcpy(lines[count], buffer);
		lengths[count] = strlen(buffer);
		count++;
	}

	order_lines(lines, lengths, count);
 
	// Imprimir las líneas ordenadas y liberar la memoria
	for (i = 0 ; i < nLines ; i++){
		puts(lines[i]); 
		free(lines[i]); 
	}
    free(lines);
    free(lengths);


	return 0;
}

