**SOLUCIÓN PROBLEMA 2**

#include \&lt;fcntl.h\&gt;

#define BUFSIZE  512   /\*tamaño de las tiras a leer\*/

#define PERM   0644  /\*permisos para creación de archivo\*/

**int copyfile (char \*name1, char \*name2)**        /\*copia name1 a name2\*/

{

 int infile, outfile, nread;

 char buffer [BUFSIZE]

 if ( (infile = open(name1, O\_RDONLY) ) \&lt; 0 )

  return(-1); /\* no puede abrirse \*/

 if ( (outfile = creat (name2, PERM) ) \&lt; 0 ) {

                close (infile);

  return (-2); /\* no puede crearse \*/

  }

 /\*lectura de name1 BUFSIZE caracteres de una vez\*/

        while( (nread = read(infile, buffer, BUFSIZE) ) \&gt; 0 )

        {

                /\*escribir el buffer al archivo de salida\*/

                if (write (outfile, buffer, nread) \&lt; nread)

  {

   close(infile);

   close(outfile);

   return (-3);    /\* error al escribir \*/

  }

 }

 if (nread==-1)

  return (-4);  /\* error al leer \*/

 close(infile);

 close(outfile);

        return(0);

}
