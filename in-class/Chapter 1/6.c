/*
 * Description: The program to calculating the sum of N numbers
 * Author: Dat Tran (HE140517)
 * Subject: PRF192
 * Last modified: Feb 18th, 2020 - 11:38 AM
 */
 
#include <stdio.h>

int main()
{
    unsigned int num, i;
    unsigned long result = 0;
    
    printf("Program: Calculating the sum of N numbers (from 0 to N).\n-------\nEnter n = ");
    scanf("%d", &num);
	
	for (i = 0; i <= num; i++)
		result += i;

    printf("-------\nResult: %ld\n", result);
    
    return 0;
}
