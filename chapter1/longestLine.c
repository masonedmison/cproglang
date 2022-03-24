#include <stdio.h>
#define MAXLINE 100 /* maximum input line size */

int ourgetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest line */
main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = ourgetline(line, MAXLINE)) > 0)
    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  if (max > 0) /* there was a line */
  {
    printf("Longest string captured = %s\n", longest);
    printf("Actual length = %d\n", max);
  }

  return 0;
}

int ourgetline(char s[], int lim)
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
  {
    if (i < lim - 1)
      s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}