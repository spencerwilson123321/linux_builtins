#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    
    const int BUFFER_SIZE = 1024;
    char file_path[BUFFER_SIZE];
    struct stat st = {0};
    FILE *file_pointer;
    const char *MODE = "w";

    switch (argc) {

        case 1:
            fprintf(stderr, "Usage: touch file_path\n");
            exit(EXIT_FAILURE);
        case 2:
            strcpy(file_path, argv[1]);\
            if (stat(file_path, &st) == -1) {
                file_pointer = fopen(file_path, MODE);
                fclose(file_pointer);
                printf("File created at %s\n", file_path);
            } else {
                fprintf(stderr, "File already exists.\n");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            fprintf(stderr, "Too many arguments.\n");
            exit(EXIT_FAILURE);
    }
    return 0;
}
