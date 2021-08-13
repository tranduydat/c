/*
 * Description: Count the number of digits and the sum of the digits in a number. (easy way)
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */

#include <stdio.h>

int main()
{
  unsigned long long int n, count = 0, sum = 0;

  printf("Enter n (n is integer, n > 0): ");
  scanf("%llu", &n);

  while (n != 0)
  {
    sum = sum + (n % 10);
    n = n / 10;
    ++count;
  }

  printf("---\nSum: %llu\nNumber of digits: %llu", sum, count);

  return 0;
}
