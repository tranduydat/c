/*
 * File:   main.c
 * Author: Tran Duy Dat (HE140517)
 * Description: Remove unnecessary blank in string
 * Status: DONE!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INIT_LENGTH_STRING 500 // character unit

void getUserInput(char *str);
char *removeBlankStr(char *str);
void displayStr(char *str);
void askContinue(bool *isContinue);

int main()
{
    // create bool isContinue to get user choice either to rerun program or not
    bool isContinue = false;

    char *str;

    do
    {
        str = (char *)malloc(INIT_LENGTH_STRING * sizeof(char));

        if (str == NULL)
        {
            printf("Memory allocation for string str failed!");
            return -1;
        }

        getUserInput(str);
        displayStr(str);
        askContinue(&isContinue);

        free(str);
    }
    while (isContinue == true);

    return 0;
}

/**
 * Step 1
 * ------
 *  Enter an string, do not allow entering special characters
 *  such those @, #, !, [, ], {, }, (, )
 * @param str
 */

void getUserInput(char *str)
{
    int i, j;
    bool checkValidInput;

    // checkStr
    char checkStr[] = {'@', '#', '!', '[', ']', '{', '}', '(', ')'};

    do
    {
        // reset checkValidInput = true when rerun this block code
        checkValidInput = true;

        printf("Please enter a string: ");
        fgets(str, INIT_LENGTH_STRING, stdin);

        // get the length of string str
        int strLength = strlen(str);

        str = (char *)realloc(str, strLength * sizeof(int));

        // checking user input, expect 8 special characters
        // in checkStr[]
        for (i = 0; i < strLength - 1; i++)
            for (j = 0; j <= 8; j++)
                if (str[i] == checkStr[j])
                    checkValidInput = false;

        if (checkValidInput == false)
            printf("We don't allow enter special characters such as @, #, !, [, ], {, }, (, )\nPlease try again!\n");
    }
    while (checkValidInput == false);
}

/**
 * Step 2
 * ------
 *  Removing all unnecessary blank in the string
 */

char *removeBlankStr(char *str)
{
    // i for str
    // j for newStr
    int i = 0, j = 0;

    // get the length of the string str
    int strLength = strlen(str);

    // dynamic allocation for newStr to store removed blank space string
    char *newStr = (char *)malloc(strLength * sizeof(char));

    while (str[i] != 0)
    {
        if (str[i] == ' ')
        {
            // just keep one blank space, then pass it to newStr
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

    // NULL terminate newStr
    newStr[j] = '\0';

    return newStr;
}

/**
 * Step 3
 * ------
 *  Display the string on the screen
 * @param str
 */
void displayStr(char *str)
{
    printf("The string after removing: %s\n", removeBlankStr(str));
}

/**
 * Step 4
 * ------
 *  Ask user either to rerun program or not
 * @param isContinue
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
