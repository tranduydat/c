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
  int numberator, denominator, factor;

  printf("Enter numberator: ");
  scanf("%d", &numberator);
  printf("Enter denominator: ");
  scanf("%d", &denominator);

  factor = findGCD(numberator, denominator);

  printf("\n> Irreducible fraction = %d/%d\n", numberator/factor, denominator/factor);

  return 0;
}
