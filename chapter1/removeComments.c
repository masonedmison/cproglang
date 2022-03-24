#include <stdio.h>
#define IGNOREC 1
#define CONSIDERC 0

/*
 * Remove comments from a C program
 * Note: comments do not nest
 */

// double forward slash comment
/* multi line comment ending with asterik and */
/* // what about this */

main()
{
  int prevc; /* previous character */
  int c;     /* current character */
  int state; /* to ignore or not printing of prevc */

  state = CONSIDERC;
  prevc = '\0';

  while ((c = getchar()) != EOF)
  {
    if (c == '*' && prevc == '/')
      state = IGNOREC;

    else if (c == '/' && prevc == '*')
      state = CONSIDERC;

    else if (c == '/' && prevc == '/')
      state = IGNOREC;

    else if (c == '\n' && state != IGNOREC)
      state = CONSIDERC;

    else if (state == CONSIDERC && prevc != '\0')
      putchar(prevc);

    prevc = c;
  }

  return 0;
}