#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s_io.h"

/*s_scanf creates a char[] that can't be overflown.*/
char* s_scanf(size_t pBufsize) {
  char* buffer = (char*)malloc(pBufsize * sizeof(char));
  if (buffer == NULL) {
    perror("Error: s_scanf failed to allocate memory to input.");
    exit(EXIT_FAILURE);
  }

  if (fgets(buffer, pBufsize, stdin) != NULL) {
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
      len--;
    }

    char* resized_buffer = (char*)realloc(buffer, (len + 1) * sizeof(char));
    if (resized_buffer == NULL) {
      perror("Error: s_scanf failed to reallocate memory to fit input size.");
      free(buffer);
      exit(EXIT_FAILURE);
    }
    buffer = resized_buffer;
  } else {
    free(buffer);
    return NULL;
  }
  return buffer;
}
/*Only to be used with s_scanf or with char[] that had been given heap memory*/
void s_printf(char* pCharArr) {
  if (pCharArr != NULL) {
    printf("You entered: %s\n", pCharArr);
    free(pCharArr);
  } else {
    printf("Error reading input.\n");
  }
}
