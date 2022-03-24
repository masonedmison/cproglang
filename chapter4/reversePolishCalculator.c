#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that negative operand was found */

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
int peekNum(void);

/*
reverse Polish calculator
ex 4.3 - 4-10
*/

int main()
{
  int type;
  double op2;
  char s[MAXOP];
  int r;

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0)
        push(pop() / op2);
      else
        printf("error: zero divisor");
      break;
    case '%':
      op2 = pop();
      push(((int)pop()) % (int)op2);
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int peekNum(void)
{
  int c, r;

  c = getch();

  if (isdigit(c))
    r = 1;
  else
    r = 0;

  ungetch(c); /* push back c regardless */

  return r;
}

int getop(char s[])
{
  int i, c, sign;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
  {
    if (c == '-' && peekNum())
      ;
    else
      return c;
  }

  i = 0;
  if (isdigit(c) || c == '-')
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free buffer position */

int getch(void)
{ /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
  {
    printf("adding char to ungetch %c\n", c);
    buf[bufp++] = c;
  }
}