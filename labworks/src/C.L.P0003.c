#include <stdio.h>

/**
 * At the beginning of the program the user is given the following choices
 * Play the slot machine
 * Save game
 * Cash out
 */

void showMenu()
{
  printf("Choose one of the following menu options:\n");
  printf("1) Play the slot machine.\n");
  printf("2) Save game.\n");
  printf("3) Cash out.\n");
}

int main()
{
  showMenu();

  return 0;
}
