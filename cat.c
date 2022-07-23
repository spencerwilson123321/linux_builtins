#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

  /*
    1. Handle command line arguments.
    2. Open file in read mode (file from command line argument)
    3. For each line in the file, store it in a buffer and print it.
    4. End.
  */

  char line_buffer[BUFFER_SIZE];
  char path_buffer[BUFFER_SIZE];
  FILE *file_pointer;
  char *MODE = "r";

  switch (argc) {
  case 2:
    strcpy(path_buffer, argv[1]);
    printf("%s\n", path_buffer);
    break;
  default:
    fprintf(stderr, "Expected a file_path\n");
    exit(EXIT_FAILURE);
  }

  if ((file_pointer = fopen(path_buffer, MODE)) == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  while (fgets(line_buffer, BUFFER_SIZE, file_pointer) != NULL) {
    printf("%s", line_buffer);
  }

  fclose(file_pointer);
  return 0;
}
