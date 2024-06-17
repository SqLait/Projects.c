#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s_io.h"

float Calculate(char, float, float);
float SpliceEquation(char*);

int main() {
  printf("Enter equation => ");
  char* input = s_scanf(50);
  float result = SpliceEquation(input);

  printf("\n%f\n", result);
  free(input); // Free the allocated memory for input
  return 0;
}

float SpliceEquation(char* pEquation) {
  char operands[] = {'+', '-', '*', '/'};
  char swapBuffer[50] = ""; // A buffer to hold the current number
  char holdOperand = 0;     // The current operand
  float mainBuffer = 0;
  int swapIndex = 0;        // Index to keep track of position in swapBuffer

  for (int i = 0; i < strlen(pEquation); i++) {
    int isOperand = 0;
    for (int o = 0; o < sizeof(operands) / sizeof(operands[0]); o++) {
      if (pEquation[i] == operands[o]) {
        isOperand = 1;
        holdOperand = operands[o];
        swapBuffer[swapIndex] = '\0'; // Null-terminate the current number string

        if (mainBuffer == 0) {
          mainBuffer = atof(swapBuffer); // Convert swapBuffer to float
        } else {
          mainBuffer = Calculate(holdOperand, mainBuffer, atof(swapBuffer));
        }
        swapIndex = 0; // Reset swapBuffer index
        swapBuffer[0] = '\0'; // Clear swapBuffer
        break;
      }
    }
    if (!isOperand) {
      swapBuffer[swapIndex++] = pEquation[i];
    }
  }

  if (swapIndex > 0) {
    swapBuffer[swapIndex] = '\0';
    mainBuffer = Calculate(holdOperand, mainBuffer, atof(swapBuffer));
  }
  return mainBuffer;
}

float Calculate(char pOperand, float pBuffer, float pHolderBuf) {
  switch (pOperand) {
    case '+':
      return pBuffer + pHolderBuf;
    case '-':
      return pBuffer - pHolderBuf;
    case '*':
      return pBuffer * pHolderBuf;
    case '/':
      return pBuffer / pHolderBuf;
    default:
      return pBuffer;
  }
}
