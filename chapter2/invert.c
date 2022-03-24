#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

unsigned invert(unsigned x, int p, int n)
{
  unsigned t; /* temp to hold mask */
  unsigned z; /* hold inverted bits of interested */

  t = (~(~0 << n)) << (p + 1 - n);

  z = (~x & t);

  return (x & ~t) | z;
}

/* ex 2.7 */
main()
{
  unsigned r;
  int i; /* input */
  i = 157U;
  printf("Computing invert of %u\n", i);
  r = invert(i, 4, 3);
  printf("Result = %u", r);
}