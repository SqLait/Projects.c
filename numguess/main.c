#include <stdio.h>
#include <stdlib.h>
#include "../f_math/random.h"
#include "../s_io/s_io.h"

#define MAXBUFSIZE 5

int CompareNums(int pNum, int pRd) {
  return (pNum == pRd) ? 1 : 0;
}

int main() {
  srand(40);

  int rd = random(1, 100);
  for (;;) {
    printf("Guess the random number: ");
    char* num = s_scanf(5);
    int iNum = atoi(num);
    free(num);

    if(CompareNums(iNum, rd)) {
      printf("\nYou guessed the number!");
      break;
    } else if (!CompareNums(iNum, rd)){
      printf("\nWrong! Try again!");
    }
  }
  return 0;
}
