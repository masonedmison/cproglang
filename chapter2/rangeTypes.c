#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
  printf("Range of char is %d to %d\n", CHAR_MIN, CHAR_MAX);

  printf("Range of signed char is %d to %d\n", SCHAR_MIN, SCHAR_MAX);

  printf("Range of short is %hd to %hd\n", SHRT_MIN, SHRT_MAX);

  printf("Size of short is %lu bytes\n", sizeof(short));

  printf("Range of int is %d to %d\n", INT_MIN, INT_MAX);
  printf("Size of int is %lu bytes\n", sizeof(int));

  printf("Range of long is %lli to %lli \n", LONG_MIN, LONG_MAX);
  printf("Size of long is %lu bytes\n", sizeof(long));

  printf("Unsigned int max is %u\n", UINT_MAX);
  printf("Size of unsigned int is %lu bytes\n", sizeof(unsigned int));
}