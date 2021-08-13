/*
 * Description: Program to generate pythagorean triplets smaller than a given limit
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */
#include <stdio.h>

void find_pythagorean_triplets(int limit)
{
  int a, b, c = 0;
  int m = 2;

  while (c < limit)
  {
    for (int n = 1; n < m; ++n)
    {
      a = m * m - n * n;
      b = 2 * m * n;
      c = m * m + n * n;

      if (c > limit)
        break;

      printf("%d %d %d\n", a, b, c);
    }
    m++;
  }
}

int main()
{
  int limit;

  printf("Program to generate pythagorean triplets smaller than a given limit\nEnter limit: ");
  scanf("%d", &limit);

  find_pythagorean_triplets(limit);

  return 0;
}
