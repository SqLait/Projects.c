#include "random.h"

#define RAND_A 1103515245
#define RAND_C 12345
#define RAND_M 2147483648  // 2^31

static unsigned int randSeed = 1;

void srand(unsigned int seed) {
  randSeed = seed;
}

int random(int min, int max) {
  randSeed = (RAND_A * randSeed + RAND_C) % RAND_M;
  return min + randSeed % (max - min);
}
