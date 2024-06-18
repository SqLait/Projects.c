#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s_io/s_io.h"

#define MAXBUFSIZE 50

float celsius(char *pTarget, float pTemp) {
  if (strcmp(pTarget, "fahrenheit") == 0) {
    pTemp = pTemp * (9.0f / 5.0f) + 32.0f;
  } else if (strcmp(pTarget, "kelvin") == 0) {
    pTemp = pTemp + 273.15;
  }
  return pTemp;
}

float Fahrenheit(char *pTarget, float pTemp) {
  if (strcmp(pTarget, "celsius") == 0) {
    pTemp = (pTemp - 32.0f) * (5.0f / 9.0f);
  } else if (strcmp(pTarget, "kelvin") == 0) {
    pTemp = (pTemp - 32.0f) * (5.0f / 9.0f) + 273.15f;
  }
  return pTemp;
}

float Kelvin(char *pTarget, float pTemp) {
  if (strcmp(pTarget, "celsius") == 0) {
    pTemp = pTemp - 273.15f;
  } else if (strcmp(pTarget, "fahrenheit") == 0) {
    pTemp = (pTemp - 273.15f) * (9.0f / 5.0f) + 32.0f;
  }
  return pTemp;
}

float CheckMethod(char *pMethod, char *pTarget, float pTemp) {
  if (strcmp(pMethod, "celsius") == 0) {
    return celsius(pTarget, pTemp);
  } else if (strcmp(pMethod, "fahrenheit") == 0) {
    return Fahrenheit(pTarget, pTemp);    
  } else if (strcmp(pMethod, "kelvin") == 0) {
    return Kelvin(pTarget, pTemp);    
  }
  return 1;
}

int main() {
  printf("celsius | fahrenheit | kelvin |\nEnter a measuring method: ");
  char *measureMethod = s_scanf(MAXBUFSIZE);

  printf("celsius | fahrenheit | kelvin |\nEnter a desired outcome: ");
  char *measureTarget = s_scanf(MAXBUFSIZE);
  
  printf("\nEnter the temperature you want: ");
  char *temp = s_scanf(MAXBUFSIZE);
  float temperature = atof(temp);
  free(temp);

  printf("result of %s -> %s: %f", measureMethod, measureTarget, CheckMethod(measureMethod, measureTarget, temperature));

  free(measureTarget);
  free(measureMethod);

  return 0;
}
