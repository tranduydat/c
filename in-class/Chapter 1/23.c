/*
 * Description: Count the sum of odd digits and even digits in a given number.
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */
#include <stdio.h>

int main()
{
  unsigned long long int n, sumEvenNums = 0, sumOddNums = 0;
  short int temp;

  printf("Enter n (n is integer, n > 0): ");
  scanf("%llu", &n);

  while (n != 0)
  {
    temp = n % 10;
    if (temp % 2 == 0)
      sumEvenNums += temp;
    else
      sumOddNums += temp;
    n = n / 10;
  }

  printf("---\nSum of even numbers: %llu\nSum of odd numbers: %llu", sumEvenNums, sumOddNums);

  return 0;
}
