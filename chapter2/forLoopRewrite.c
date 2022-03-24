#include <stdio.h>

#define MAXSIZE 1000

int mygetline(char buff[], int lim);
// int mygetline2(char buff[], int lim);

/* ex 2.2 */
main()
{
  int len;
  char buff[MAXSIZE];
  while ((len = mygetline(buff, MAXSIZE)) > 0)
    printf("len = %d", len);
}

int mygetline(char buff[], int lim)
{
  int i, c;

  while (i < lim - 1)
  {
    c = getchar();

    if (c != '\n')
      if (c != EOF)
      {
        buff[i] = c;
        ++i;
      }
      else
        break;

    else
      break;
  }
  return i;
}
