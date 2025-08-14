#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char *buffer;
    size_t bufsize = 10;
    size_t args;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("$ ");
    args = getline(&buffer, &bufsize, stdin);
    printf("%s", buffer);
}
