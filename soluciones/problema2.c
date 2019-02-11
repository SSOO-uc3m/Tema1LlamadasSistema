#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


#define BUFSIZE		512			/*tamaño de las tiras a leer*/
#define PERM 		0644		/*permisos para creación de archivo*/

int fileExists(const char* file);
int copyfile (char *name1, char *name2);

/**
 * Check if a file exists
 * @return 1 if and only if the file exists, 0 else
 */
int fileExists(const char* file) {
    struct stat buf;
    return (stat(file, &buf) == 0);
}

/**
 * copy file1 to file2
 * @return 1 if the file was copied
          -1 if it cant be opened
          -2 if it cant be created
          -3 if an error ocurred during the copy
          -4 if the file cannot be readed
 */
int copyfile (char *name1, char *name2)	
{
	int infile, outfile, nread;
	char buffer [BUFSIZE];
	if ( (infile = open(name1, O_RDONLY) ) < 0 )
		return(-1); /* no puede abrirse */
	if ( (outfile = creat (name2, PERM) ) < 0 ) {
		close (infile);
		return (-2); /* no puede crearse */
		}
	/*lectura de name1 BUFSIZE caracteres de una vez*/
	while( (nread = read(infile, buffer, BUFSIZE) ) > 0 )
	{
		/*escribir el buffer al archivo de salida*/
		if (write (outfile, buffer, nread) < nread)
		{
			close(infile);
			close(outfile);
			return (-3); 			/* error al escribir */
		}
	}
	if (nread==-1)
		return (-4); 	/* error al leer */
	close(infile);
	close(outfile);
	return(0);
}

int main (int argc, char* argv[]){
   int copiado;

   if(argc < 3){
   	fprintf(stderr,"Número insuficiente de argumentos\n");
   	exit(-1);
   }

   if(!fileExists(argv[1])){
   	fprintf(stderr,"El fichero %s no existe\n",argv[1]);
   	exit(-1);
   }
  
   copiado = copyfile(argv[1],argv[2]);

   switch (copiado){
   	case 0: 	printf("El fichero %s se ha copiado correctamente en %s\n",argv[1],argv[2]);  
   	break;
	case -1: fprintf(stderr,"El fichero %s no se puede abrir\n",argv[1]);
   	break;
	case -2: fprintf(stderr,"El fichero %s no se puede crear\n",argv[2]);
   	break;
 	case -3: fprintf(stderr,"Error al copiar el fichero %s en %s\n",argv[1],argv[2]);
   	break;
 	case -4: fprintf(stderr,"Error al leer el fichero %s\n",argv[1]);
   	break;  	
   	}

   exit(copiado);

}