#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {

    char *buffer;
    size_t bufsize = 10;
    ssize_t args;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable buffer");
        exit(1);
    }

    while (1) {
        printf("$ ");
        char* token = strtok(buffer, "\n");
        args = getline(&buffer, &bufsize, stdin);

        if (args == -1 || strcmp(buffer, "end of file\n") == 0 || strcmp(buffer, "EOF\n") == 0) {
            printf("🏃\n");
            break;
        }
        if (token != NULL)
        {
        printf("%s", token);
        }
        else
        {
            continue;
        }
    }
    free(buffer);
    return (0);
}
