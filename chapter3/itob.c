#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int base);
void printString(char s[]);
void reverse(char s[]);

/* ex 3.5 */
int main()
{
  int n;

  n = 28;

  char buff[2000];

  itob(n, buff, 16);

  printString(buff);
}

void itob(int n, char s[], int base)
{
  int i, sign, rem;

  i = 0;
  if ((sign = n) < 0)
  {
    n = -n;
  }

  do
  {
    rem = n % base;
    if (rem > 9)
      rem = rem - 10 + 'a';
    else
      rem = rem + '0';

    s[i++] = rem;
  } while ((n /= base) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
void reverse(char s[])
{
  int i, j, temp;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

void printString(char s[])
{
  int i, c;
  for (i = 0; (c = s[i]) != '\0' && c != '\n'; i++)
  {
    putchar(c);
  }
}