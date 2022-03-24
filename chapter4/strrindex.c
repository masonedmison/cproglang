#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int ourgetline(char s[], int lim);
int strrindex(char s[], char t[]);

char pattern[] = "ould";

/* ex 4.1 */
int main()
{
  int found;
  char buff[MAXLINE];
  int i;
  found = 0;

  while (ourgetline(buff, MAXLINE) > 0)
  {
    if ((i = strrindex(buff, pattern)))
    {
      printf("found at %d", i);
      found++;
    }
  }
  return found;
}

int strrindex(char s[], char t[])
{
  int i, j, k;

  for (i = strlen(s) - 1; i >= 0; i--)
  {
    for (j = i, k = strlen(t) - 1; k >= 0 && j >= 0 && s[j] == t[k]; j--, k--)
      ;
    if (k == -1)
      return i - strlen(t);
  }

  return -1;
}

int ourgetline(char s[], int lim)
{
  int c, i;

  i = 0;

  while (--lim > 0 && ((c = getchar()) != EOF && c != '\n'))
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}