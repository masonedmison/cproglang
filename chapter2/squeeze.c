#include <stdio.h>

void squeeze(char s1[], char s2[]);
int charIn(int ch, char s[]);

/* delete each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[])
{
  int i, j, c;

  for (i = j = 0; (c = s1[i]) != '\0'; ++i)
    if (!charIn(c, s2))
      s1[j++] = c;

  s1[j] = '\0';
}

int charIn(int ch, char s[])
{
  int i, c;

  for (i = 0; (c = s[i]) != '\0'; ++i)
    if (c == ch)
      return 1;

  return 0;
}

/* ex 2.4 */
main()
{
  int i, c;
  char s1[] = "Hello, World!!!!";
  char s2[] = ",!,W";

  squeeze(s1, s2);

  for (i = 0; (c = s1[i]) != '\0'; ++i)
    putchar(c);
}