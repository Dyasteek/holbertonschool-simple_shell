<h2>Changelog</h2>

### [V1.3] - 2025-01-27
### Added
- `_getenv()` function to retrieve system environment variables.
- Environment variable search implementation using `environ`.
- String comparison with `strncmp()` to find specific variables.
- Edge case handling: verification of `name` and `environ` NULL.
- Return of environment variable value (without name and '=').

### [V1.2] - 2025-08-15
### Added
- New `exec()` function that implements `fork()` and `execve()` to execute external programs.
- Command execution with absolute paths.
- Improved tokenization: `strtok()` removes newline before execution.
- Multiple exit keywords: `EOF`, `exit`, `end of file`.
- Use of `pid_t` for child/parent process handling.
- Child process waiting with `wait(NULL)` to avoid zombie processes.

### [V1.1] - 2025-08-14
### Added
- Main loop that displays a `$` prompt and reads commands from standard input.
- Input reading with `getline()` and initial dynamic buffer of 10 bytes.
- Newline removal using `strtok()`.
- Exit conditions:
  - `end of file` input
  - `EOF` input
  - End of stream (`args == -1`)
- Exit message with 🏃 emoji when closing the shell.
- Memory deallocation before exit.

### [V1.0] - 2025-08-14
### Added
- shell_start: Script with interactive prompt, input reading and display of received arguments (simple command tests).
- pid_script: Prints current PID (`getpid()`) and parent process PID (`getppid()`) using `pid_t`.
- trash files: removal of compiler-generated garbage files.