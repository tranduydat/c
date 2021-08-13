/*
* Description: Enter two numbers and find sum, sub, div and mul of these. Print the result in irreducible fraction form.
* Author: Dat Tran
* Last modified: April 13th, 2020
*/

#include <stdio.h>

int findGCD(int a, int b)
{
  int temp;

  while (b != 0)
  {
    temp = a % b;
    a = b;
    b = temp;
  }

  return a;
}

int main()
{
  float a, b, gcdVal, lcmVal;

  printf("Enter a: ");
  scanf("%f", &a);
  printf("Enter b: ");
  scanf("%f", &b);

  gcdVal = findGCD(a,b);
  lcmVal = (a * b)/gcdVal;

  printf("GCD(%0.2f, %0.2f)=%0.2f\n", a, b, gcdVal);
  printf("LCM(%0.2f, %0.2f) = %0.2f\n", a, b, lcmVal);

  float sum = a + b;
  float sub = a - b;
  float mul = (float)(a * b);

  printf("Tong hai so: %0.2f", sum);
  printf("\nHieu hai so: %0.2f", sub);
  printf("\nTich hai so: %0.2f", mul);
  printf("\nThuong hai so: %0.2f/%0.2f", a/gcdVal, b/lcmVal);

  return 0;
}
