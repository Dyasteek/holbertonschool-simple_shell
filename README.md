# Simple Shell 0.2+

A simple shell implementation that handles PATH and command execution with proper error handling.

## Features

- **PATH Handling**: Automatically searches for commands in the PATH environment variable
- **Smart Forking**: Only calls `fork()` when the command actually exists
- **Command Resolution**: Supports both absolute paths and commands found in PATH
- **Built-in Commands**: Includes `env` command to display environment variables
- **Error Handling**: Proper error messages and memory management
- **Betty Style**: Follows Holberton School coding standards

## How It Works

1. **Command Parsing**: Splits input into command and arguments
2. **PATH Resolution**: 
   - If command starts with `/`, `./`, or `../`, treats as absolute/relative path
   - Otherwise, searches through PATH directories
3. **Command Validation**: Uses `access()` to check if command exists and is executable
4. **Execution**: Only calls `fork()` and `execve()` for valid commands

## Files Structure

- `main.c` - Main shell loop and command processing
- `shell.h` - Header file with function declarations and structures
- `_execve.c` - Command execution logic with PATH handling
- `aux.c` - Utility functions (tokenizer, PATH handling, chilito, print_env)
- `_getenv.c` - Environment variable retrieval

## Usage

```bash
# Compile
gcc -Wall -Wextra -Werror -pedantic main.c _execve.c aux.c _getenv.c -o shell

# Run
./shell

# Test commands
ls          # Searches in PATH
/bin/ls     # Uses absolute path
pwd         # Searches in PATH
env         # Built-in command
```

## Requirements Met

✅ **Handle the PATH**: Automatically searches PATH directories for commands  
✅ **No fork() for non-existent commands**: Validates commands before forking  
✅ **Betty Style**: Follows Holberton coding standards  
✅ **Memory Management**: Proper allocation and deallocation  
✅ **Error Handling**: Clear error messages for invalid commands  

## Author

Holberton School Student
