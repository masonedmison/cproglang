#include <stdio.h>
#include <math.h>

unsigned rotate(unsigned x, int n);

/* ex 2.8 */
int main()
{
  int i, r;
  i = 4238U;
  printf("Computing rotate for %u\n", i);
  r = rotate(i, 4);
  printf("Result = %u", r);
  return 0;
}

unsigned rotate(unsigned x, int n)
{
  int ts; /* to shift x by to the left */
  unsigned t1, t2;

  ts = (int)(ceil(log(x) / log(2))) - n;

  printf("Printing ts %d\n", ts);

  t1 = x >> n;
  t2 = ((~(~0 << n)) & x) << ts;

  printf("Printing t1 = %u\n", t1);
  printf("Printing t2 = %u\n", t2);

  return t1 | t2;
}