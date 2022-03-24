#include <stdio.h>

int binsearchorig(int x, int v[], int n);
int binsearch(int x, int v[], int n);

/* ex 3.1 */
main()
{
  int i = 3;
  int iarr[20] = {1, 3, 6, 8, 9, 11, 15};
  int r;

  r = binsearch(i, iarr, 7);
  printf("Searching for %d, idx is %d\n", i, r);
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = -1;
  high = n;
  while (low + 1 < high)
  {
    mid = (low + high) / 2;
    if (v[mid] < x)
      low = mid;
    else
      high = mid;
  }
  if (high == n || v[high] != x)
    return -1;
  else
    return high;
}

int binsearchorig(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;

    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }

  return -1;
}