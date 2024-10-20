#include <stdio.h> 
#include "libreria.h"
#include <errno.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 

/**
 * Función que muestra las N primeras líneas de la entrada estándar.
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

	//Imprimir líneas por salida estándar
	for (i = 0 ; i < nLines ; i++){
		puts(lines[i]); 
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
	int i ,j, counter = 0, stdin_size = 0;
	
	//Asignación de memoria a lines y buffer
	lines = (char **)malloc(nLines*sizeof(char *)); 
	if (lines == NULL){
		return -1; 
	}


	while(fgets(lines[counter], 1024, stdin) != NULL){
		if (feof(stdin)){
			break; 
		}
		else{
			for (i = 0; i<nLines; i++){
				free(lines[j]); 
			}
			free(lines); 
			return -1;
		}	
		if(counter==2){
			counter = 0; 
		}
		else{
			counter++;
		}
		stdin_size++; 
	}

	if (nLines>stdin_size){
		return -1; 
	}

	for (i = 0 ; i<counter ; i++){
		puts(lines[i]); 
		free(lines[i]); 
	}
	free(lines); 

	return 0 ; 
}

