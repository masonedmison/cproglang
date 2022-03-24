#include <stdio.h>

/* ex 1.8 */
main()
{
  int c, b;

  b = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      putchar('\\');
      putchar('t');
    }
    else if (c == '\b')
    {
      putchar('\\');
      putchar('b');
    }
    else if (c == '\\')
      putchar('\\');
    else
      putchar(c);
  };
}