/*
 * Description: Mini-calculator (with +, -, * and / between two numbers)
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */

#include <stdio.h>

int main()
{
    double numX, numY, result = 0;
    char operationC[2] = {0};

    printf("Enter x: ");
    scanf("%lf", &numX);
    printf("---\nEnter y: ");
    scanf("%lf", &numY);
    printf("---\nEnter c (+, -, * or /): ");
    scanf("%s", operationC);

    if (operationC[0] == '+')
        result = numX + numY;
    else if (operationC[0] == '-')
        result = numX - numY;
    else if (operationC[0] == '*')
        result = numX * numY;
    else if (operationC[0] == '/')
        result = numX / numY;
    else
        puts("\nThis is not a operation.");

    printf("-> The result: %0.3lf", result);
    return 0;
}
