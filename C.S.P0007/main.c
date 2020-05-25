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

#define MAX_SIZE_STRING 500

void enterStr(char *str);
char* removeBlankStr(char *str);
void displayStr(char *str);
void askContinue(bool *isContinue);

int main() {
    bool isContinue = false;
    char str[MAX_SIZE_STRING];

    do {
        enterStr(str);
        displayStr(str);
        askContinue(&isContinue);
    } while (isContinue == true);

    return 0;
}

/*
 * Step 1
 * ------
 *  Enter an string, do not allow entering special characters
 *  such that @, #, !, [, ], {, }, (, )
 */

void enterStr(char *str) {
    int i, j, strLength = 0;
    bool checkValidInput = true;

    char checkStr[] = {'@', '#', '!', '[', ']', '{', '}', '(', ')'};

    do {
        printf("Please enter a string: ");
        gets(str);

        strLength = strlen(str);

        // input should not contain any of 8 characters in checkStr string
        for (i = 0; i < strLength - 1; i++)
            for (j = 0; j <= 8; j++)
                if (str[i] == checkStr[j])
                    checkValidInput = false;

        if (checkValidInput == false)
            printf("We don't allow to type in 8 special characters, such as @, #, !, [, ], {, }, ( and )\nPlease try again!");
    } while (checkValidInput == false);
}

/*
 * Step 2
 * ------
 *  Remove all unnecessary blank in the string
 */

char* removeBlankStr(char *str) {
    // i for str
    // j for newStr
    int i = 0, j = 0;

    int strLength = strlen(str);
    char *newStr;

    newStr = (char *) malloc(MAX_SIZE_STRING);

    while (str[i] != '\0') {
        // if a blank space is found
        if (str[i] == ' ') {
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

void displayStr(char *str) {
    printf("The string after removing: %s\n", removeBlankStr(str));
}

/**
 * Step 4
 * ------
 * Ask user either to continue perform this program or not
 */

void askContinue(bool *isContinue) {
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