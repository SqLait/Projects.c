#include <stdio.h>
#include "matrix.h"

#define ROWS 3
#define COLS 3

int (*CreateBoard())[COLS] {
  static int arr[ROWS][COLS] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };
  return arr;
}

void LoopBoard(int (*board)[COLS]) {
  printf("Board: \n\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}
