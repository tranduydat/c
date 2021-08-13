/*
 * Description: Program to check whether a number is a Amstrong number or not
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool checkArmstrong(int nums)
{
    int countDigit = 0, temp = nums, remainder;
    double sum = 0;

    // count the number of digits
    while (temp != 0)
    {
        ++countDigit;
        temp /= 10;
    }

    // reset temp variable to original value of nums
    temp = nums;

    while (temp != 0)
    {
        remainder = temp % 10;
        sum += pow(remainder, countDigit);
        temp /= 10;
    }

    // compare the result
    if (sum == nums)
        return true;

    return false;
}

int main()
{
    int n;

    printf("Nhap n = ");
    scanf("%d", &n);

    if (checkArmstrong(n))
        printf("\n%d is a Amstrong number.\n", n);
    else
        printf("\n%d is NOT a Amstrong number.\n", n);

    return 0;
}
