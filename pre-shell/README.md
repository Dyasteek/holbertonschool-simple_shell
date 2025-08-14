<h2>Changelog</h2>

### [V1.1] - 2025-08-14
### Añadido
- Bucle principal que muestra un prompt `$` y lee comandos desde la entrada estándar.
- Lectura de entrada con `getline()` y buffer dinámico inicial de 10 bytes.
- Eliminación del salto de línea usando `strtok()`.
- Condiciones de salida:
  - Entrada `end of file`
  - Entrada `EOF`
  - Fin de flujo (`args == -1`)
- Mensaje de salida con emoji 🏃 al cerrar el shell.
- Liberación de memoria asignada antes de salir.

### [V1.0] - 2025-08-14
### Añadido
- shell_start: sScript con prompt interactivo, lectura de entrada y muestra de argumentos recibidos (pruebas de comandos simples).
- pid_script: Imprime el PID actual (`getpid()`) y el PID del proceso padre (`getppid()`) usando `pid_t`.
- trash files: eliminación de archivos basura generados por el compilador.

