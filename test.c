#include "libreria.h"
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 

int callFunct(char *funct, int nLines, const char *MSGERR);

int main(int argc, char *argv[])
{
  char *MSGERRM = "Use : ./test -[funct] [nlines]";
  char *EOFERROR = "Expected more lines but got to the end of file";
  char *ASGERROR = "Asignation failed";
  char *funct;
  int nLinesM; 
  if ((argc == 1)||(argc>3)){
	printf("%s", MSGERRM); 
	return -1; 
  }
  else if(argc==3){
	funct = argv[1];
	nLinesM = atoi(argv[2]); 
	return callFunct(funct, nLinesM, MSGERRM);
  }
  else{ //2 ARGUMENTOS
	nLinesM = 10; 
	funct = argv[1];
	return callFunct(funct, nLinesM, MSGERRM);
  }
}

/**
 *  Función que elige la funcion a la que se ha de llamar.
 * 	@param funct Es la función introducida por el usuario.
 *  @param nLines Líneas a mostrar.
 *  @return -1 en caso de error, 0 en caso de encontrar la función.
 */
int callFunct(char *funct, int nLines, const char *MSGERR){
	if (strcmp(funct,"head")==0){
		return head(nLines);
	}
	else if (strcmp(funct,"tail")==0){
		return tail(nLines); 
	}
	else if (strcmp(funct,"longlines")==0){
		//TODO
	}
	else{
		puts(MSGERR);
		return -1;
	}

}

