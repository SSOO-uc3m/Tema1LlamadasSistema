**SOLUCIÓN PROBLEMA 3**


Se solicita mediante un mecanismo de interrupciones. Cuando un proceso en ejecución la solicita, éste utiliza una instrucción TRAP que genera una interrupción. Como se muestra en la Figura 1.6, la rutina de tratamiento de la interrupción de TRAP usa una tabla interna del S.O. para determinar qué rutina activar dependiendo de cuál es la llamada solicitada.

Cuando se programa en un lenguaje de alto nivel, la solicitud de servicios al sistema operativo se hace mediante una llamada a una función determinada, que se encarga de generar la llamada al sistema y el trap correspondiente.

![](images/systemCall.PNG)