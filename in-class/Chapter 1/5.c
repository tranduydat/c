/*
 * Description: The program to calculate electricity bill
 * Author: Dat Tran (HE140517)
 * Subject: PRF192
 * Last modified: Jan 7th, 2020 - 10:57PM
 */
 
#include <stdio.h>

int main()
{
	float electricCost100, electricCost101, consumptionPower, consumptionPower100, consumptionPower101;

	printf("Monthly consumption power (in Mega Watt): ");
	scanf("%f", &consumptionPower);
	printf("---\nElectricity cost for the first 100 numbers (in VND): m1 = ");
	scanf("%f", &electricCost100);
	printf("---\nEletricity cost for the upper 100 numbers (in VND): m2 = ");
	scanf("%f", &electricCost101);

	consumptionPower100 = (consumptionPower * electricCost100);

	if (consumptionPower == 0)
		puts("------\n-> Invalid input! The amount of consumption power should be larger than zero.");
	else if (consumptionPower <= 100)
		printf("------\n-> The amount of money you should pay: %0.2f VND", consumptionPower100);
	else
		consumptionPower101 = ((100 * electricCost100) + ((consumptionPower - 100) * electricCost101));
		printf("------\n-> The amount of money you should pay: %0.2f VND", consumptionPower101);
		
	return 0;		
}
