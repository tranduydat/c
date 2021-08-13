/*
 * Description: 
 * Author: Dat Tran
 * Date: 2020-01-09 11:26:25
 */
#include <stdio.h>

int optionOne(double principal, float terms, float interestRate, double total)
{
	system("cls");

	puts("You has chosen option 1: ...\n-------------------------------");
	printf("1. Nhap so tien goc (VND): ");
	scanf("%lf", &principal);
	puts("----------");
	printf("2. Ki han ban muon gui (months): ");
	scanf("%f", &terms);
	puts("----------");
	printf("3. Lai suat ki han (%%): ");
	scanf("%f", &interestRate);
	puts("----------");

	total = (double)principal * (1.0 + (float)terms * (double)interestRate);
	printf("-> So tien ca goc + lai ban nhan duoc sau %d thang la: %lf", terms, total);
}

int optionTwo(double principal, float terms, float interestRate, double total)
{
	system("cls");

	puts("You has chosen option 1: ...\n-------------------------------");
	printf("1. Nhap so tien von (VND): ");
	scanf("%lf", &principal);
	printf("2. Nhap so tien ban muon nhan: ");
	scanf("%lf", &total);
	printf("3. Lai xuat ki han (months): ");
	scanf("%f", &interestRate);
	puts("----------");
	terms = ((double)total - (double)principal) / ((double)principal * (float)interestRate);
	printf("-> So thang can gui de co duoc so tien %0.3lf la: ", total, terms);
}

int optionThree(double principal, float terms, float interestRate, double total)
{
	system("cls");
	
	puts("You has chosen option 3: ...\n--------------------------------");
	printf("1. Nhap so tien goc (VND): ");
	scanf("%lf", &total);
	printf("2. Nhap so thang muon gui: ");
	scanf("%f", &terms);
	printf("3. Nhap lai suat trong ki han %d: ", terms);
	scanf("&f", &interestRate);
	puts("-----------");

	principal = (double)(total)/(1 + terms*interestRate);
	printf("-> So von ban dau ban can gui: %lf", principal);
}

int main()
{
	int userChoice, terms;
	float interestRate;
	double principal, total;

	do
	{
		system("cls");
		puts("BANK SIMPLE INTEREST CALCULATOR\n\t\t   by Dat Tran.");
		puts("-------------------------------");
		puts("1. Enter Principal + Terms. \n   Show the total amount money you can get after that term.\n");
		puts("2. Enter Principal + Terms. \n   Show the total amount money you can get after that term.\n");
		puts("3. Enter Principal + Terms. \n   Show the total amount money you can get after that term.\n");
		puts("4. Exit the program.\n-------------------------------");

		while (userChoice > 5 || userChoice < 1)
		{
			printf("> Enter your choice: ");
			scanf("%d", &userChoice);
			if (userChoice > 5 || userChoice < 1)
				puts("Please try again! We just have 3 options from 1 to 3.");
		}

		switch (userChoice)
		{
		case 1:
			optionOne(principal, terms, interestRate, total);
			break;
		case 2:
			optionTwo(principal, terms, interestRate, total);
			break;
		case 3:
			optionThree(principal, terms, interestRate, total);
			break;
		default:
			puts("Exit thanh cong!");
			break;
		}
	} while (userChoice != 4);
	return 0;
}
