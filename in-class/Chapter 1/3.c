/*
 * Description: The program to find the solution for simple equation
 * Author: Dat Tran (HE140517)
 * Subject: PRF192
 * Last modified: Feb 18th, 2020 - 10:56 AM
 */

#include <stdio.h>

int main()
{
    float a, b;

    printf("Enter a: ");
    scanf("%f", &a);
    printf("---\nEnter b: ");
    scanf("%f", &b);
    puts("---------");

    if (a == 0)
        if (b == 0)
            printf("There are countless solutions to the equation.");
        else
            printf("There is no solution for the equation.");
    else
        double x = -(b / a);
        printf("The equation: %0.2fx + %0.2f = 0 has one solution.\n\tX = %f (%f/%f)", a, b, x, a, b);

    return 0;
}
