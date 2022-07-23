#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   
    const int BUFFER_SIZE = 1024;
    char message_buffer[BUFFER_SIZE]; 
    
    switch (argc) {
    case 1:
        printf("Hello world!\n");
        break;
    case 2:
        strcpy(message_buffer, argv[1]);
        printf("%s\n", message_buffer);
        break;
    default:
        fprintf(stderr, "Too many arguments.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

