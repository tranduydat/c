/*
 * Description: Write a program in C to generate mersenne primes within a range of numbers.
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void genAllPrime(int n1, bool prarr1[])
{
  for (int i = 0; i <= n1; i++)
    prarr1[i] = true;

  for (int p = 2; p * p <= n1; p++)
    if (prarr1[p] == true)
      for (int i = p * 2; i <= n1; i += p)
        prarr1[i] = false;
}

void checkMerPrime(int limit)
{
  bool prarr1[limit + 1];
  genAllPrime(limit, prarr1);
  for (int j = 2; ((1 << j) - 1) <= limit; j++)
  {
    long long num = (1 << j) - 1;
    if (prarr1[num])
      printf(" %lli ", num);
  }
}

int main()
{
  int limit;
  printf("Generate Mersenne primes within a range of numbers:\n--------------------------------------------------------\n");
  printf("Input a upper limit [range from 1 to upper limit]:");
  scanf("%d", &limit);
  printf("\nMersenne prime numbers are:\n");
  checkMerPrime(limit);
  printf("\n");
}
