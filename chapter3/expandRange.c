#include <stdio.h>

#define BUFFERMAX 200

int expandRange(int start, int end, char buff[], int buffI);

void expand(char s1[], char s2[]);

void printString(char s[]);

/* ex 3.3 */
int main()
{
  char inp1[] = "a-z";
  char inp2[] = "a-z0-9";

  int lastI;
  char buff[BUFFERMAX];

  expand(inp2, buff);

  printString(buff);

  return 0;
}

void expand(char s1[], char s2[])
{
  int start, end, c, i, buffI;
  int hyphStart;

  hyphStart = 0;
  start = 0;
  end = -1;

  for (i = 0; (c = s1[i]) != '\0'; i++)
  {
    printf("c in expand = %c\n", c);
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
      if (hyphStart == 0)
      {
        start = c;
      }
      else
      {
        end = c;
        buffI = expandRange(start, end, s2, buffI);
        hyphStart = 0;
      }
    }
    else if (c == '-')
    {
      hyphStart = 1;
    }
    else
      printf("Unexpected character %c", c);
  }

  s2[buffI] = '\0';
}

int expandRange(int start, int end, char buff[], int buffI)
{
  int c, i;
  i = buffI;
  for (c = start; c <= end && i < BUFFERMAX; ++i, ++c)
  {
    buff[i] = c;
  }

  return i;
}

void printString(char s[])
{
  int i, c;
  for (i = 0; (c = s[i]) != '\0' && c != '\n'; i++)
  {
    putchar(c);
  }
}
