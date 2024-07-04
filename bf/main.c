#include <stdio.h>

int p, r, q;
char a[5000] = {0}, f[5000], b, o, *s = f;

void interpreter(char* c) {
  char* d;
  r++;

  while(*c) {
    switch(o = 1, *c++) {
      case '<': p--; break;
      case '>': p++; break;
      case '+': a[p]++; break;
      case '-': a[p]--; break;
      case '.': printf("%c", a[p]); fflush(stdout); break;
      case ',': a[p] = getchar(); fflush(stdout); break;
      case '[':
        for(b = 1, d = c; b && *c; c++) {
          b += *c == '[', b -= *c == ']';
        }
        if(!b) {
          c[-1] = 0;
          while(a[p]) interpreter(d);
          c[-1] = ']';
          break;
        }
        printf("UNBALANCED BRACKETS");
      case ']':
        printf("UNBALANCED BRACKETS");
      case '#':
        if(q > 2) {
          printf("%2d %2d %2d %2d %2d %2d %2d %2d %2d %2d\n%*s\n",
            *a, a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], 3 * p + 2, "^");
        }
        break;
      default: o = 0;
    }
  }
  r--;
}

int main(int argc, char** argv) {
  FILE* z;
  q = argc;

  if((z = fopen(argv[1], "r")) != NULL) {
    while((b = getc(z)) != EOF) {
      *s++ = b;
    }
    *s = '\0'; // Null-terminate the string
    fclose(z); // Close the file after reading
    interpreter(f); // Call the interpreter
  }
  return 0;
}

