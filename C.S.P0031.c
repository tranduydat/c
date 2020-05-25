#include <stdio.h>
#include <math.h>
#include <conio.h>

void convertDecBin(int decimalNum)
{
    // create an array to store binary value
    int binaryArray[64];

    int i = 0, j;
    while (decimalNum != 0)
    {
      // to store remainder in binary array
      binaryArray[i] = decimalNum % 2;
      decimalNum = decimalNum / 2;
      i++;
    }

    // to print binary array in reversed order
    for (j = i - 1; j >= 0; j--)
      printf("%d", binaryArray[j]);
}

long decimalToBinary(int decimalNum)
{
  long binaryNum = 0;
  int remainder, temp = 1;

  while (decimalNum!=0)
  {
    remainder = decimalNum % 2;
    decimalNum = decimalNum / 2;
    binaryNum = binaryNum + remainder * temp;
    temp = temp * 10;
  }

  return binaryNum;
}

int main()
{
  int decimalNum, c;

  do
  {
    printf("Convert Decimal to Binary program");
    printf("\nEnter a positive Number: ");
    scanf("%d", &decimalNum);
    printf("\nBinary Number: %ld", decimalToBinary(decimalNum));
    printf("\nSecond test:\n");
    convertDecBin(decimalNum);

    printf("\nPress any key to do another conversion\n");
    c = getch();
  }
  while (c != 0);

  return 0;
}
