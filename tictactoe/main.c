#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "matrix.h"

void ChangeBoard(int (*board)[COLS], int row, int col, int player);
void GameLoop(int (*board)[COLS]);
void LoopBoard(int (*board)[COLS]);
void handleTurn(int (*board)[COLS], int player);
int ChangeTurns(int player);
int getInput(const char *prompt);
void TileErrorHandler(int *row, int *col, int player);
int RowCheck(int (*board)[COLS], int player);

void TileErrorHandler(int *row, int *col, int player) {
  *row = getInput("Pick a row: ");
  *col = getInput("Pick a column: ");
}

void ChangeBoard(int (*board)[COLS], int row, int col, int player) {
  if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
    if (board[row][col] == 1 || board[row][col] == 2) {
      printf("Tile already claimed. Pick a new tile %d,\n", player);
      TileErrorHandler(&row, &col, player);
      ChangeBoard(board, row, col, player);
    } else {
      board[row][col] = player;
    }
  } else {
    printf("Invalid position!\n");
    TileErrorHandler(&row, &col, player);
    ChangeBoard(board, row, col, player);
  }
}

int ChangeTurns(int player) {
  return (player == 1) ? 2 : 1;
}

void GameLoop(int (*board)[COLS]) {
  int player = 1;
  while (1) {
    LoopBoard(board);
    printf("Pick a tile to claim player %d,\n", player);
    int row = getInput("Pick a row (0, 1, 2): ");
    int col = getInput("Pick a column (0, 1, 2): ");
    ChangeBoard(board, row, col, player);

    if (RowCheck(board, player)) {
      LoopBoard(board);
      printf("Player %d wins!\n", player);
      break;
    }

    player = ChangeTurns(player);
  }
}

int getInput(const char *prompt) {
  char input[10];
  char *endptr;
  long value;

  while (1) {
    printf("%s", prompt);
    if (fgets(input, sizeof(input), stdin) != NULL) {
      errno = 0;
      value = strtol(input, &endptr, 10);
      if (endptr != input && (*endptr == '\n' || *endptr == '\0') && errno == 0 && value >= INT_MIN && value <= INT_MAX) {
        return (int)value;
      }
    }
    printf("Invalid input. Please enter a valid integer.\n");
  }
}

int RowCheck(int (*board)[COLS], int player) {
  // Check rows
  for (int i = 0; i < ROWS; i++) {
    int rowWin = 1;
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] != player) {
        rowWin = 0;
        break;
      }
    }
    if (rowWin) return 1;
  }

  // Check columns
  for (int i = 0; i < COLS; i++) {
    int colWin = 1;
    for (int j = 0; j < ROWS; j++) {
      if (board[j][i] != player) {
        colWin = 0;
        break;
      }
    }
    if (colWin) return 1;
  }

  // Check diagonal (top-left to bottom-right)
  int diagWin1 = 1;
  for (int i = 0; i < ROWS; i++) {
    if (board[i][i] != player) {
      diagWin1 = 0;
      break;
    }
  }
  if (diagWin1) return 1;

  // Check diagonal (top-right to bottom-left)
  int diagWin2 = 1;
  for (int i = 0; i < ROWS; i++) {
    if (board[i][ROWS - i - 1] != player) {
      diagWin2 = 0;
      break;
    }
  }
  if (diagWin2) return 1;

  return 0;
}

int main() {
  int (*board)[COLS] = CreateBoard();
  GameLoop(board);
  return 0;
}
