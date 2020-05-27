/*
 * File:   main.c
 * Author: Dat Tran
 * Description: Remove unnecessary blank in string
 *
 * Created on May 21, 2020, 7:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INIT_LENGTH_STRING 500

void getUserInput(char *str);
char* removeBlankStr(char *str); // return string
void displayStr(char *newStr);
void askContinue(bool *isContinue);

int main()
{
  // create bool isContinue to get user choice either to rerun program or not
  bool isContinue = false;

  char *str, *newStr;

  do
  {
    str = (char *)malloc(INIT_LENGTH_STRING * sizeof(char));

    if (str == NULL)
    {
      printf("Memory allocation for string str failed!");
      exit(-1);
    }
    getUserInput(str);
    displayStr(str);
    askContinue(&isContinue);

    free(str);
  }
  while (isContinue == true);

  return 0;
}

/*
 * Step 1
 * ------
 *  Enter an string, do not allow entering special characters
 *  such that @, #, !, [, ], {, }, (, )
 */

void getUserInput(char *str)
{
  int i, j, strLength = 0;
  bool checkValidInput = true;

  char checkStr[] = {'@', '#', '!', '[', ']', '{', '}', '(', ')'};

  do
  {
    printf("Please enter a string: ");
    gets(str);

    // get the length of string str
    strLength = strlen(str);

    str = (char *)realloc(str, strLength * sizeof(char));

    if (str == NULL)
    {
      printf("Memory reallocation for string str failed!");
      exit(-2);
    }
    // input should not contain any of 8 characters in checkStr string
    for (i = 0; i < strLength - 1; i++)
      for (j = 0; j <= 8; j++)
        if (str[i] == checkStr[j])
          checkValidInput = false;

    // show alert when entered input is invalid. Let user try again.
    if (checkValidInput == false)
      printf("We don't allow to type in 8 special characters, such as @, #, !, [, ], {, }, ( and )\nPlease try again!");
  }
  while (checkValidInput == false);
}

/*
 * Step 2
 * ------
 *  Remove all unnecessary blank in the string
 */

char* removeBlankStr(char *str)
{
  // i for str
  // j for newStr
  int i = 0, j = 0;

  // get the length of string str
  int strLength = strlen(str);

  // create newStr to store the removed blank space string
  char *newStr = (char *)malloc((strLength + 1) * sizeof(char));

  if (newStr == NULL)
  {
    printf("Memory allocation for string newStr failed!");
    exit(-3);
  }
  // while loop until reaching to null character (last character of the string)
  while (str[i] != '\0')
  {
    // if a blank space is found
    if (str[i] == ' ')
    {
      // just keep one blank space, and pass it to newStr
      newStr[j] = ' ';
      j++;

      // skip all consecutive space
      while (str[i] == ' ')
        i++;
    }

    // pass the character on str to newStr (except space character)
    newStr[j] = str[i];

    i++;
    j++;
  }

  // NULL terminate the new string
  newStr[j] = '\0';

  return newStr;
}

/*
 * Step 3
 * ------
 *  Display the string on the screen
 */

void displayStr(char *str)
{
  printf("The string after removing: %s\n", removeBlankStr(str));
}

/*
 * Step 4
 * ------
 * Ask user either to continue perform this program or not
 */

void askContinue(bool *isContinue)
{
  char userChoice;

  printf("Do you wish to continue? Y/N ");
  scanf("%c", &userChoice);
  getchar();
  // or %*c

  if (userChoice == 'y' || userChoice == 'Y')
    *isContinue = true;
  else
    *isContinue = false;
}
