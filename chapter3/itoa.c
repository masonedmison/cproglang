#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[])
{
  int i, j, temp;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    // printf("reversing charcter %s", s[i]);
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

/* ex 3.4 */
void itoa(int n, char s[])
{
  int i, sign;
  int isMax;

  isMax = 0;

  if (n == INT_MIN)
    isMax = 1;

  // get sign - mk number positive if negative
  if ((sign = n) < 0)
  {
    if (isMax)
      n = -(n + 1);
    else
      n = -n;
  }

  i = 0;
  do
  {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  /* add one back to 0th pos if isMaxNeg */
  if (isMax)
    s[0]++;
  reverse(s);
}

void printString(char s[])
{
  int i, c;
  for (i = 0; (c = s[i]) != '\0' && c != '\n'; i++)
  {
    putchar(c);
  }
}

int main()
{
  // largest negative num is -2147483648
  int i = -2147483648;
  int ii;

  char buff[10000];

  itoa(i, buff);

  printString(buff);
}
