#include <stdio.h> 
#include <libreria.h> 
#include <errno.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 




int main(int argc, char *argv[])
{
  char *MSGERR = "Use ./libreria.c head [DIRECTORIO].";
  head(argc); 
  return 0; 
}

// Función que muestra las N primeras líneas de la entrada estándar.
// Funciones E/es = fscanf
// @param buffer Memoria estática para guardar la entrada estándar
// @param header Memoria dinámica donde almaceno la cabecera
// Devueve 0 en caso de éxito y -1 en caso de error.
int head(int argc) 
{
	char buffer[1024];
	char *header; 
	size_t size = 100; 
	char *MSGERR = "Use ./libreria.c head [DIRECTORIO].";

	header = (char *)malloc(size * sizeof (char)); 
	if (header == NULL){
		printf("%s",MSGERR); 
		return -1; 
	}
	
	if (argc==1) {
        printf("%s", MSGERR);
	  	return -1 ; 
	} else if(argc>2) {
		printf("%s", MSGERR); 
		return -1 ;
	} else {
		if ((fscanf(stdin, "%s", buffer))>0){
			header = strdup(buffer);
			printf("%s", header);
			free(header);
			return 0; 
		}
		else{
			return -1; 
		}
	}
	//EOF HEAD
}



