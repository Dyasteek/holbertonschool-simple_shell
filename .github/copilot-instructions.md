# Copilot Instructions for holbertonschool-simple_shell

## Project Overview
This repository implements a basic shell in C, with supporting scripts for process management and testing. The main components are:
- `pre-shell/`: Contains experimental scripts and C files for prompt handling, PID display, and cleanup.
- `simple_shell/`: Intended for the main shell implementation (currently a placeholder).

## Key Files & Directories
- `pre-shell/prompt.c`: Minimal interactive shell prompt. Reads user input, prints it back, and exits on EOF or specific keywords.
- `pre-shell/pid.c`, `pidmax.sh`: Scripts for displaying process IDs and limits.
- `pre-shell/clean.sh`: Cleans up build artifacts.
- `simple_shell/README.md`: Placeholder for main shell documentation.

## Build & Run
- Compile C files manually (no Makefile yet):
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 pre-shell/prompt.c -o prompt
  ./prompt
  ```
- Use `clean.sh` to remove compiler-generated trash files.

## Developer Workflows
- Test shell features in `pre-shell/prompt.c` before integrating into `simple_shell/`.
- Use scripts in `pre-shell/` for process management and debugging.
- No automated tests or CI/CD yet; manual testing is standard.

## Project Conventions
- C code follows Holberton-style: explicit error handling, minimal use of libraries, simple main loop.
- Input is read with `getline`, output is echoed, and shell exits on EOF or specific keywords (`end of file`, `EOF`).
- Scripts are used for quick prototyping and cleanup.

## Integration Points
- No external dependencies beyond standard C library and shell utilities.
- All communication is via standard input/output.

## Examples
- To test the shell prompt:
  ```bash
  gcc pre-shell/prompt.c -o prompt
  ./prompt
  ```
- To view current PID:
  ```bash
  gcc pre-shell/pid.c -o pid
  ./pid
  ```

## Next Steps
- Expand `simple_shell/` with full shell features (parsing, execution, environment handling).
- Add Makefile and automated tests as the project matures.

---
_If any section is unclear or missing, please provide feedback for improvement._
