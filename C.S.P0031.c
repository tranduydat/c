#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define INIT_SIZE_ARRAY 64
#define INIT_LENGTH_STRING 100

/*
 * Function 1
 * Display a screen to prompt user to input a positive decimal number
 */
int isNumber(char *userInput)
{
  int strLength = strlen(userInput);
  int i;

  for (i = 0; i < strLength; i++)
    if (isdigit(userInput[i]) == 0)
      return 0;
  return 1;
}

void getUserInput(char **userInput)
{
  do
  {
    printf("Convert Decimal to Binary program\n");
    printf("\tEnter a positive number: ");
    gets(*userInput);
    // scanf("%d", &(*inputDecimalNum));
    printf("%s", userInput);

    if (isNumber(userInput) == 0)
      printf("\n Please enter a number (eg. 12).\n");
  }
  while (isNumber(userInput) == 0);

  int userInputLength = strlen(userInput);

  *userInput = (char *)realloc(*userInput, userInputLength * sizeof(char));
}

/*
 * Function 2
 * Convert decimal to binary
 */
long convertDecBinary(char *userInput)
{
  char *binaryArr;
  int remainder, i = 0, numberOfDigit = 0;
  int decimalNum = atoi(userInput);
  // dynamic allocation for binaryArr
  binaryArr = (char *)malloc(INIT_SIZE_ARRAY * sizeof(char));

  while (decimalNum != 0)
  {
    remainder = decimalNum % 2;

    binaryArr[i] = remainder;

    decimalNum = decimalNum / 2;
  }

  int binaryArrLength = strlen(binaryArr);

  binaryArr = (char *)realloc(binaryArr, binaryArrLength * sizeof(char));

  // to reverse string
  strrev(binaryArr);

  free(binaryArr);

  // to convert char to int
  long binaryNum = atoi(binaryArr);

  return binaryNum;
}

/*
 * Function 3
 * Output bits stored in the array to the screen.
 */
void showOutput(long binaryNum)
{
  printf("\tBinary number: %ld\n", binaryNum);
}

int main()
{
  int decimalNum, isContinue = 1;
  char *userInput;
  long binaryNum;

  userInput = (char *)malloc(INIT_LENGTH_STRING * sizeof(char));

  getUserInput(&userInput);
  printf("%d", userInput);
  binaryNum = convertDecBinary(userInput);
  showOutput(binaryNum);

  free(userInput);

  return 0;
}
