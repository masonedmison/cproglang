#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int atoi(char hex[]);
int mygetline(char buff[]);

int atoi(char hex[])
{
  int i, n, c;

  i = n = 0;
  while ((c = hex[i]) != '\0')
  {
    printf("Current char is %c\n", c);
    if (c > '0' && c <= '9')
      n = 16 * n + (hex[i] - '0');
    else if (c >= 'a' && c <= 'f')
      n = 16 * n + (hex[i] - 'a' + 10);
    else if (c >= 'A' && c <= 'G')
      n = 16 * n + (hex[i] - 'A' + 10);
    else
      break;
    ++i;
  }

  return n;
}

int mygetline(char buff[])
{
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    buff[i] = c;

  if (c == '\n')
  {
    buff[i] = c;
    ++i;
  }
  buff[i] = '\0';
  printf("current i in getline %d\n", i);
  return i;
}

main()
{
  int len;
  char buff[MAXLINE];
  int res;

  while ((len = mygetline(buff)) > 0)
  {
    res = atoi(buff);
    printf("Hex as int = %d\n", res);
  }
  return 0;
}
