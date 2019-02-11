**SOLUCIÓN PROBLEMA 2**

````

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


````


