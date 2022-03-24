#include <stdio.h>
#define MAXLINE 1000

void printreverse(char l[], int linesize);
int mygetline(char cont[]);

/* ex 1.19 */
main()
{

  char cont[MAXLINE];
  int l;
  while ((l = mygetline(cont)) > 0)
  {
    printreverse(cont, l);
  }
}

int mygetline(char cont[])
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
  {
    cont[i] = c;
  }

  return i;
}

void printreverse(char l[], int s)
{
  int i;
  for (i = s - 1; i >= 0; --i)
  {
    putchar(l[i]);
  }
  putchar('\n');
}