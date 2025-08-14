#include "prompt.h"

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
        args = getline(&buffer, &bufsize, stdin);

        if (args == -1 || strcmp(buffer, "end of file\n") == 0 || strcmp(buffer, "EOF\n") == 0) {
            printf("🏃\n");
            break;
        }
        
        char* token = strtok(buffer, "\n");
        if (token != NULL) {
            printf("%s\n", token);
        }
    }
    free(buffer);
    return (0);
}
