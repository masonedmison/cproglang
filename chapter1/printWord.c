#include <stdio.h>

/* ex 1.12 */
main()
{
  int c;

  c = 0;

  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t')
      putchar('\n');
    else
      putchar(c);
}