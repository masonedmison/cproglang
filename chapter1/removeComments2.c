#include <stdio.h>

#define MAXINPUT 10000
#define CONSIDERC 1
#define IGNOREC 0
#define MULTIC 2

/*
 * Remove comments v2
 */

main()
{
  int prevc;             /* previous character */
  int c;                 /* current character */
  int state;             /* to ignore or not printing of prevc */
  char cleans[MAXINPUT]; /* a buffer holding "cleaned" string input */
  int i;                 /* current idx */

  state = CONSIDERC;
  prevc = '\0';

  i = 0;
  while ((i < MAXINPUT - 1) && (c = getchar()) != EOF)
  {

    if (c == '*' && prevc == '/')
      state = MULTIC;

    else if (c == '/' && prevc == '*')
      state = CONSIDERC;

    else if (c == '/' && prevc == '/')
      state = IGNOREC;

    else if (c == '\n' && state != MULTIC)
      state = CONSIDERC;

    if (state == CONSIDERC && prevc != '\0')
      cleans[i] = c;
    prevc = c;
    ++i;
  }

  cleans[i] = '\0';

  for (i = 0; i < MAXINPUT && (c = cleans[i]) != '\0'; ++i)
    putchar(c);

  return 0;
}