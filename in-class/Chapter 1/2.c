/*
 * Description: The program to find the quadrant of M(x, y)
 * Author: Dat Tran (HE140517)
 * Subject: PRF192
 * Last modified: Jan 7th, 2020 - 10:57PM
 */

#include <stdio.h>

int main()
{
	float x, y;

	printf("The program to find the quadrant of M(x, y)\n> Enter x = ");
	scanf("%f", &x);
	printf("> Enter y = ");
	scanf("%f", &y);
	puts("---------------");

	if (x > 0)
		if (y > 0)
			printf("M(%0.2f, %0.2f) in the first quadrant.", x, y);
		else if (y < 0)
			printf("M(%0.2f, %0.2f) in the fourth quadrant.", x, y);
	else if (x < 0)
		if (y > 0)
			printf("M(%0.2f, %0.2f) in the second quadrant.", x, y);
		else if (y < 0)
			printf("M(%0.2f, %0.2f) in the third quadrant.", x, y);
	else
		puts("M point is NOT belonged to any quadrant.");

	return 0;
}
