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
	int i, j, counter = 0, stdin_size = 0;
	
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

	for (i = 0 ; i<nLines ; i++){
		puts(lines[i]); 
		free(lines[i]); 
	}
	free(lines); 

	return 0 ; 
}



int longlines (int nLines) {

	char **lines = (char **)malloc(nLines*sizeof(char *));
	int *lengths = (int *)malloc(nLines * sizeof(int));
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
	for(i = 0; i<nLines; i++){
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
		if (count < nLines){
			strcpy(lines[count], buffer);
			lengths[count] = strlen(buffer);
			count++;
		}
	}


	return 0;
}


int main() {
    int N;
    printf("Introduce el número N de líneas más largas a mostrar: ");
    scanf("%d", &N);
    getchar();

    longlines(N);

    return 0;
}