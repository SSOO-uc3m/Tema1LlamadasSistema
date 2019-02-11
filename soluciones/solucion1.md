SOLUCIÓN PROBLEMA 1

El sistema operativo es un programa que se encarga de cubrir el hardware para facilitar el uso de la computadura, lo que lleva a cabo mediante la realización de tres funciones principales:

1. Gestión de los recursos del sistema.
2. Ejecución de servicios para programas.
3. Ejecución de programas por parte de los usuarios.

1. Gestión de recursos hardware. Esta función es desempeñada por el núcleo del sistema operativo, que debe ocuparse de asignar los recursos de la computadora a los programas en ejecución, así como de evitar que unos programas accedan a los recursos de los otros y de llevar la contabilidad de los recursos consumidos por cada programa. Tiene como principal tarea **administrar** los diferentes procesos que pueden estar en ejecución en la máquina simultáneamente. Lo más importante es saber,  mediante las estructuras adecuadas, que recursos están libres y cuáles ocupados. Atendiendo a esto deberá asignar a los procesos en ejecución, dependiendo de la prioridad de cada uno, unos recursos determinados y recuperar, para su aprovechamiento, los que han quedado libres porque un proceso ha terminado. El sistema operativo deberá también hacerse cargo de que los procesos no accedan a los recursos asignados a otros, velando así por la **seguridad del sistema**. Por último, el sistema debe **medir** la cantidad de recursos que se están usando en cada momento, lo que se usa frecuentemente para monitorizar.
2. Ejecución de servicios para los programas. Esta función se lleva a cabo en la capa denominada de servicios o llamadas al sistema que permite que la ejecución de los programas sea mas cómoda.  Estas llamadas se encargan de:
  1. Ejecutar y destruir procesos.
  2. Facilitar la entrada / salida y las operaciones sobre los archivos.
  3. Detectar y tratar los errores detectados por el hardware.

El sistema operativo ofrece principalmente cuatro tipos de **servicios** , o **llamadas al sistema** ; servicios para **lanzar programas** y convertirlos en procesos, pararlos y abortarlos. Debido a la complejidad de las operaciones de entrada/salida con los periféricos, el S.O.  provee los servicios necesarios para **facilitar la comunicación entre los procesos y los dispositivos** externos (abrir, cerrar, leer, etc...). Para trabajar con **archivos** el sistema operativo ofrece servicios similares a los de E/S, pero con un nivel de abstracción mayor.  Además el sistema se encarga de t **ratar los posibles errores** que pueda detectar el hardware.

1. Ejecución de los mandatos de los usuarios. El S.O. se encarga también de la   **interacción de la computadora con los usuarios** , esto lo lleva a cabo mediante **shells**. Las shells pueden ser de línea de **mandatos** , como puede ser el bash de UNIX, o **gráficas** como la de Windows. Las shells por línea de mandato obligan al usuario a aprender todos los  mandatos, mientras que las gráficas son mucho más intuitivas. La shell se comporta como un bucle infinito repitiendo la siguiente secuencia:
  1. Espera una orden del usuario.
  2. Una vez recibida  una orden la analiza y en caso de ser correcta la ejecuta.
  3. Una vez concluida la orden vuelve a la espera.