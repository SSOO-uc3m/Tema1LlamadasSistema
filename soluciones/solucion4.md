**PROBLEMA 4**

Ejemplo sencillo del uso de fork, donde un proceso crea una copia y a continuación se hace un execl para hacer un comando &quot;ls&quot;.   Ejecútelo y vea la salida. ¿Qué ocurre?

SOLUCIÓN

main()

{

 int valor\_regr=0;

 printf(&quot;Bifurcando el proceso\n&quot;);

 valor\_regr=fork();

 printf(&quot;El id del proceso es %d y el valor devuelto es %d\n&quot;,

                getpid(), valor\_regr);

 execl(&quot;/bin/ls&quot;,&quot;ls&quot;,&quot;-l&quot;,0);

        printf(&quot;Esta linea no es impresa\n&quot;);

}