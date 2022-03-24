#include <stdio.h>

/* ex 1.3 */
main()
{
  float fahr, celcius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%3s\t%6s\n", "Celcius", "Fahrenheit");
  while (fahr <= upper)
  {
    celcius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f\t%6.1f\n", fahr, celcius);
    fahr = fahr + step;
  }
}
