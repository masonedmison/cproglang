#include <stdio.h>

#define IN 1
#define OUT 0
#define WORD_LENGTHS 20

main()
{
  int c, wc, state, i;
  int twc[WORD_LENGTHS];

  wc = 0;
  for (i = 0; i < WORD_LENGTHS; ++i)
    twc[i] = 0;

  state = OUT;
  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t' || c == '\n')
    {
      state = OUT;
      ++twc[wc + 1];
      wc = 0;
    }
    else if (state == IN)
      ++wc;

    else
      state = IN;
  }
  printf("hello");

  for (i = 0; i < WORD_LENGTHS; ++i)
  {
    printf("Length = %d ", i);
    while (twc[i] > 0)
    {
      printf("|");
      --twc[i];
    }
    printf("\n");
  }
}