<h2>Changelog</h2>

### [V1.3] - 2025-01-27
### Añadido
- Función `_getenv()` para obtener variables de entorno del sistema.
- Implementación de búsqueda de variables de entorno usando `environ`.
- Comparación de strings con `strncmp()` para encontrar variables específicas.
- Manejo de casos edge: verificación de `name` y `environ` NULL.
- Retorno del valor de la variable de entorno (sin el nombre y el '=').

### [V1.2] - 2025-08-15
### Añadido
- Nueva función `exec()` que implementa `fork()` y `execve()` para ejecutar programas externos.
- Ejecución de comandos con rutas absolutas.
- Tokenización mejorada: `strtok()` elimina el salto de línea antes de ejecutar.
- Múltiples palabras clave para salir: `EOF`, `exit`, `end of file`.
- Uso de `pid_t` para manejo de procesos hijo/padre.
- Espera de procesos hijos con `wait(NULL)` para evitar procesos zombies.

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