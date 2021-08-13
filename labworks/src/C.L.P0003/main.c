/* 
 * File:   main.c
 * Author: Tran Duy Dat (HE140517)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MONEY_STORE_PATH "./money.txt"

#define DEFAULT_SETUP_MONEY 10.0

#define NEW_GAME_COST 0.25

#define WIN_COMBO_2 0.50
#define WIN_COMBO_3 10.0

#define LOSE 0
#define WIN_MODE_COMBO_2 2
#define WIN_MODE_COMBO_3 3

#define NUM_DIGITS 3

/*
 * Group functions 1:
 * -----------------
 * The choice entered by the user for the menu will always be valid
 */
bool isNumber(char *userChoice)
{
    int strLength = strlen(userInput);
    int i;

    // check all the element in string userInput
    for (i = 0; i < strLength; i++)
        // if any non-numeric character was found, return 0
        if (isdigit(userInput[i]) == 0)
            return false;

    return true;
}

unsigned int randNumbersGen();

void showMenu()
{
    printf("Choose one of the following menu options:\n");
    printf("1) Play the slot machine.\n");
    printf("2) Save game.\n");
    printf("3) Cash out.\n");
    
}

/*
 * Group functions 2:
 * -----------------
 * If you choice 2, save your money to file
 * And restore the money in the play next time.
 */

void saveGame();
void restoreGame();

/*
 * Group functions 3:
 * -----------------
 * If you have no money to play any to more, say good bye.
 */

void cashOut();

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

