#include <stdio.h>
#define SPECCOLUMN 10
#define MAXBUFFERSIZE 1000

/*
 * Exercise 1-22
 * fold long lines into shorter lines breaking at the last non-blank character _before_ the specified column (SPECCOLUMN)
 * BEWARE of very long lines as well as lines that do not have blanks
 * example:
 * Hello world, you crazy thing you.
 * Hello
 *  world,
 *  you crazy
 *  thing
 *  you.
 *
 * How do we handle lines below the specified column?
 * e.g.
 * Hello you!
 * You so crazy you crazy little thing.
 *
 */

void printbuffer(int buffer[], int start, int end);

main()
{
  int prevNb; /* last non-blank character or else -1*/
  int i;      /* current position in line */
  int bs;     /* buffer starting point */
  int buff[MAXBUFFERSIZE];
  int c; /* current char */

  i = bs = 0;
  while ((c = getchar()) != EOF)
  {
    if ((i % SPECCOLUMN) == 0 && (i != 0))
    {
      if (prevNb == -1)
      {
        printbuffer(buff, bs, i);
        bs = i + 1;
      }

      else
      {
        printbuffer(buff, bs, prevNb);
        bs = prevNb + 1;
      }
      prevNb = -1;
    }
    /* this is flawed as prevNb might point to space */
    else if ((c == ' ' || c == '\t'))
      prevNb = i - 1;

    else if (c == '\n')
    {
      printbuffer(buff, bs, i - 1);
      i = 0;
      prevNb = -1;
      bs = 0;
    }

    if (i < (MAXBUFFERSIZE - 1))
      buff[i] = c;
    else if (i == (MAXBUFFERSIZE - 1))
      buff[i] = '\0';

    ++i;
  }
}

/* print buffer starting at start and ending at end (inclusive) */
void printbuffer(int buff[], int start, int end)
{
  int i, c;
  int as;

  as = (end >= MAXBUFFERSIZE) ? MAXBUFFERSIZE : end;

  for (i = start; (c = buff[i]) != '\0' && i <= as; ++i)
    putchar(c);
  putchar('\n');
}