/*
 * Description: Simple class timetable
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char whatDay[10];

	printf("Enter what day in a week you want to look up (eg: Monday or monday):\n> ");
	scanf("%s", &whatDay);
	puts("---");

	if (strcmp(whatDay, "Monday") == 0 || strcmp(whatDay, "monday") == 0)
		puts("Monday's timetable:\n1. Meeting\n2. Maths\n3. Chemistry\n4. Biology\n5. Civic Education");
	else if (strcmp(whatDay, "Tuesday") == 0 || strcmp(whatDay, "tuesday") == 0)
		puts("Tuesday's timetable:\n1. Maths\n2. Maths\n3. English\n4. History\n5. Literature");
	else if (strcmp(whatDay, "Wednesday") == 0 || strcmp(whatDay, "wednesday") == 0)
		puts("Wednesday's timetable:\n1. English\n2. English\n3. Biology\n4. Chemistry\n5. History");
	else if (strcmp(whatDay, "Thursday") == 0 || strcmp(whatDay, "thursday") == 0)
		puts("Thursday's timetable:\n1. Information Technology\n2. Information Technology\n3. Geography\n4. Geography\n5. Civic Education");
	else if (strcmp(whatDay, "Friday") == 0 || strcmp(whatDay, "friday") == 0)
		puts("Friday's timetable:\n1. Maths\n2. Physical Education\n3. National Defense Education\n4. Technology\n5. Physics");
	else if (strcmp(whatDay, "Saturday") == 0 || strcmp(whatDay, "saturday") == 0 || strcmp(whatDay, "Sunday") == 0 || strcmp(whatDay, "sunday") == 0)
		puts("Weekend :)\nEnjoy it!");
	else
		puts("Error :(\nPlease try again!");

	return 0;
}
