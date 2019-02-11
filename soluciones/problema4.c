#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{ 
	int pid=0;
                
	printf("Bifurcando el proceso\n");

	pid=fork(); //crear hijo
	

     if(pid==0){ // proceso hijo
     	printf("El id del proceso %d y el pid devuelto es %d\n", getpid(), pid);
		execl("/bin/ls","ls","-l",NULL);
		printf("Esta linea no es impresa\n");
	  }
	 else{ // proceso padre
	 	printf("El id del proceso %d y el pid devuelto es %d\n", getpid(), pid);
	 	wait (NULL); // espera a que termine su proceso hijo
	 	printf("Termina el proceso padre\n");
	 }
	
	exit(0);
}
