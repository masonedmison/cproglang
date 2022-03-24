#include <stdio.h>

#define LIMIT 500

void escape(char s[], char t[]);
int mgetline(char buff[]);

/* ex 3.2 */
main()
{

  int len, i;
  char buff[LIMIT];
  char out[1000];

  mgetline(buff);

  escape(out, buff);

  printf("with escapes:\n %s", out);
}

int mgetline(char buff[])
{
  int i, c;
  for (i = 0; (c = getchar()) != EOF; ++i)
    buff[i] = c;

  buff[i] = '\0';
  return i;
}

void escape(char s[], char t[])
{
  int c, i, j;
  i = j = 0;

  while (t[i] != '\0')
  {
    switch (t[i])
    {
    case '\n':
      s[j] = '\\';
      ++j;
      s[j] = 'n';
      break;
    case '\t':
      s[j] = '\\';
      ++j;
      s[j] = 't';
      break;
    default:
      s[j] = t[i];
      break;
    }
    ++i;
    ++j;
  }

  s[j] = '\0';
}
