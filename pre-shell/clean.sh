#!/bin/bash

echo "🧹 Limpiando archivos ejecutables..."

find . -type f -executable \( -name "*.out" -o -name "a.out" -o -name "prompt" -o -name "mypid" -o -name "pid" -o -name "print_args" \) -delete

find . -type f -executable ! -name "*.sh" ! -name "*.py" ! -name "*.pl" ! -name "*.rb" ! -name "*.js" ! -name "*.php" ! -name "*.c" ! -name "*.h" ! -name "*.md" ! -name "*.txt" ! -name "*.git*" -delete

echo "Limpieza completada!"
echo "Archivos ejecutables eliminados:"
find . -type f -executable 2>/dev/null | wc -l
