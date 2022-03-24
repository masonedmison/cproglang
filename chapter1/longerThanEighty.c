#include <stdio.h>

#define THRESHOLD 80
#define MAXLINELEN 150

int mygetline(char line[]);
void println(char line[]);

/* ex 1.17 */
main()
{
  int c;              /* number of sentences longer than THRESHOLD */
  int len;            /* length of current line */
  char l[MAXLINELEN]; /* current line greater than */

  while ((len = mygetline(l)) > 0)
    if (len > THRESHOLD)
      println(l);
}

void println(char l[])
{
  int i, c;

  i = 0;
  while ((c = l[i]) != '\0')
  {
    putchar(c);
    ++i;
  }
}

int mygetline(char s[])
{
  int c, i;
  for (i = 0; (c = getchar()) && c != '\n' && c != EOF; ++i)
  {
    if (i < MAXLINELEN - 1)
      s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';

  return i;
}