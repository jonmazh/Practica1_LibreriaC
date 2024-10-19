#include <stdio.h> 
#include <libreria.h> 
#include <errno.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 




int main(int argc, char *argv[])
{
  char *MSGERR = "Use ./libreria.c head [DIRECTORIO].";
  char *funct;
  int nLinesM; 
  if (argc == 1){
	printf("%s", MSGERR); 
	return -1; 
  }
  else if(argc>3){
	printf("%s", MSGERR); 
	return -1; 
  }
  else if(argc=3){
	*funct = argv[2];
	nLinesM = atoi(argv[3]); 
	return callFunct(funct, nLinesM);
  }
  else{ //2 ARGUMENTOS
	nLinesM = 10; 
	*funct = argv[2];
	return callFunct(funct, nLinesM);
  }
}

/**
 *  Función que elige la funcion a la que se ha de llamar.
 * 	@param funct Es la función introducida por el usuario.
 *  @param nLines Líneas a mostrar.
 *  @return -1 en caso de error, 0 en caso de encontrar la función.
 */
int callFunct(char *funct, int nLines){
	if (funct == "head"){
		return head(nLines);
	}
	else if (funct == "tail"){
		//TODO
	}
	else if (funct == "longlines"){
		//TODO
	}
	else{
		return -1;
	}

}


/**
 * Función que muestra las N primeras líneas de la entrada estándar.
 * @param buffer Memoria estática para guardar una línea de la entrada estándar
 * @param size Tamaño máximo para una línea
 * @param counter Contador para saber las líneas que se han leído 
 * @param lines Líneas que se van a devolver.
 * @return lines.
 */
int head(int nLines) 
{
	const char *MSGERR = "Use ./libreria.c head [DIRECTORIO].";
	char buffer[1024];
	int size = 100, counter = 0;
	int i = 0, j = 0; 
	char **lines; 

	lines = (char **)malloc(size * sizeof(char *)); 
	if (lines == NULL){
		printf("%s",MSGERR); 
		return -1; 
	}

	//Asignación de memoria dinámica a lines
	for (i ; i < nLines ; i++){
		lines[i] = (char *)malloc(sizeof(char)); 
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
		if (fgets(lines[counter], size, stdin)){
			counter++; 
		}
		else if (feof(stdin)){
			return -1 ; 
		}
		else{
			for (j = 0 ; j < nLines ; j++){
				free(lines[j]);
			}
			free(lines);
			return -1; 
		}
	}

	//Imprimir líneas por salida estándar
	for (i = 0 ; i < nLines ; i++){
		put(lines[i]); 
		free(lines[i]);
	}

	free(lines); 
	return 0; 

	//EOF HEAD
}



