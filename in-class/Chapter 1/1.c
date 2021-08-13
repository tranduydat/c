/*
 * Description: Check the properties of a triangle (regular, balanced, square, right square).
 * Author: Dat Tran (HE140517)
 * Subject: PRF192
 * Last modified: Feb 18th, 2020 - 3:32PM
 */

#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;

	printf("Enter a = ");
	scanf("%f", &a);
	puts("---");
	printf("Enter b = ");
	scanf("%f", &b);
	puts("---");
	printf("Enter c = ");
	scanf("%f", &c);
	puts("--------------");

	// The condition to form a triangle
	if (a + b > c && a + c > b && b + c > a)
	{
		// display the perimeter and area of that triangle
		float halfPerimeter = (a + b + c) / 2;
		float triangleArea = sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));

		printf("> ABC Triangle Perimeter: %0.2f", halfPerimeter * 2);
		printf("\n> ABC Triangle Area: %0.2f", triangleArea);

		// show the feature of that triangle
		if (a == b || b == c && c == a)
			if (a == b && b == c)
				puts("> ABC is a equilateral triangle.");
			else
				puts("> ABC is a isosceles triangle.");
		else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
			if (a == b || b == c && c == a)
				puts("ABC is a isosceles right triangle.");
			else
				puts("> ABC is a right triangle.");
		else
			puts("> ABC is a normal triangle.");
	}
	else
		puts("> This is not a triangle!");

	return 0;
}
