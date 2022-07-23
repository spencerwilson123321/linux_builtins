#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    
    const int BUFFER_SIZE = 1024;
    char path_buffer[BUFFER_SIZE];
    struct stat st = {0};
    
    switch(argc) {
        case 1:
            fprintf(stderr, "Usage: mkdir directory_path\n");
            exit(EXIT_FAILURE);
        case 2:
            strcpy(path_buffer, argv[1]);
            if (stat(path_buffer, &st) == -1) {
                mkdir(path_buffer, 0775);
            } else {
                fprintf(stderr, "Directory already exists.\n");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            fprintf(stderr, "Too many arguments.\n");
            exit(EXIT_FAILURE); 
    }
    return 0;
}
