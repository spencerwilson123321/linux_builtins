#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

  char path_buffer[BUFFER_SIZE];
  DIR *directory;
  struct dirent *entry;

  /*
    CLI Argument Handling:
      case 1: If no arguments passed, then use the working directory.
      case 2: Use the directory that was passed on the command line.
      default: Too many arguments if it isn't 1 or 2.
  */
  switch (argc) {
  case 1:
    getcwd(path_buffer, BUFFER_SIZE);
    break;
  case 2:
    strcpy(path_buffer, argv[1]);
    break;
  default:
    fprintf(stderr, "Too many arguments.\n");
  }

  /*
    Open the directory stream.
  */
  directory = opendir(path_buffer);

  /*
    1. Check if the directory is not NULL (indicating an error)
    2. Read an entry, if it isn't NULL, then print the name.
       Else there are no more entries.
    3. Close the directory stream.
    4. Exit.

  */
  if (directory) {
    while ((entry = readdir(directory)) != NULL) {
      printf("%s   ", entry->d_name);
    }
    printf("\n");
    closedir(directory);
  } else {
    perror("Bad Directory");
    exit(EXIT_FAILURE);
  }
  return 0;
}
