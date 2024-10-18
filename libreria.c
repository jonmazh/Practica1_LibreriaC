#include <stdio.h> 
#include <libreria.h> 
#include <errno.h> 
#include <string.h> 
#include <stdlib.h> 




int main(int argc, char *argv[])
{
  //TODO
  return 0; 
}

// Función que muestra las N primeras líneas de la entrada estándar.
// Devueve 0 en caso de éxito y -1 en caso de error.
int head(char buf[1024]) 
{
	char *MSGERR = "Use ./libreria.c head [DIRECTORIO].";
	if (argc==1){
           printf("%s", MSGERR);
	  return -1 ; 
	}
	else{
		if (argc>2)
		{
		  printf("%s", MSGERR); 
		  return -1 ;
		}
		else{
		     if(!access(buf, X_OK) 
		     {
		     //TODO FUNCIONALIDAD
		     	return 0 ; 
		     }
                     else
		     {
		      	return -1 ; 
		     }
		}
	}

	return 0; 
}


