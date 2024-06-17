#include <stdint.h>
#include "fsqrt.h"

/*Improved version of the quake III fast inverse square root function
 * This will help preventing undifiend behaviour, according to wikipedia...*/
float f_isqrt(float number) {
  const unsigned int magicNum = 0x5f3759df;
  union {
    float f;
    uint32_t i;
  } conv = { .f = number };

  conv.i  = magicNum - (conv.i >> 1);
  conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
  return conv.f;
}

float f_sqrt(float number) {
  const unsigned int magicNum = 0x5f3759df;
  union {
    float f;
    uint32_t i;
  } conv = { .f = number };

  conv.i = magicNum - (conv.i >> 1);
  conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
  return number * conv.f;
}
