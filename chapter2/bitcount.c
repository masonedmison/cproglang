#include <stdio.h>

int bitcountorig(unsigned x);
int bitcount(unsigned x);

int main()
{
  unsigned i = 251;
  int bco, bc;
  printf("Input = %d\n", i);
  bco = bitcountorig(i);
  bc = bitcount(i);
  printf("Orig res = %d\n", bco);
  printf("Quick = %d\n", bc);

  return 0;
}

int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x &= (x - 1))
    ++b;

  return b;
}

int bitcountorig(unsigned x)
{
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      ++b;

  return b;
}