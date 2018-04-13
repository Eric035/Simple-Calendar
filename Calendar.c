/*By Eric Leung
A simple program that takes a user input as the size of the calendar, then prints out a full calendar afterwards.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char *months[] = {"January", "February", "March", "April", "May", "June",
                  "July", "August", "September", "October", "November", "December"};
char newString[20];

int separatorLine (int DAYSIZE, int FIRSTDAY) // Function that prints out a headline ("|-----|")
{
    if (DAYSIZE < 2) //Check DAYSIZE 
    {
        printf("Error: DAYSIZE has to be greater than or equals to 2");
        return -1;
    }
    
    printf ("|");
    for (int i = 1; i < (DAYSIZE + 3) * 7; i++) 
    {   
        printf ("-");
    }
    printf ("|\n");
    return 0;
}

int printMonthHeader (int DAYSIZE, int FIRSTDAY, char month[]) // A function that prints out the header of the month.
{
    separatorLine (DAYSIZE, FIRSTDAY);
    printf ("|");
    for (int i = 1; i < (DAYSIZE + 3) * 7; i++)
    {
        printf (" ");
        if (i == (((DAYSIZE + 3) * 7 + 1 - strlen(month)) / 2) - 1)
        {
            printf ("%s", month);
            i += strlen(month);
        }
    }
    printf ("|\n");
    separatorLine (DAYSIZE, FIRSTDAY);
    return 0;
}

char *dayLabel(int DAYSIZE, int dayIndex) // A function that takes a int DAYSIZE and and copy a string's characters to form a new string.
{
    int dayLength = strlen(days[dayIndex]);
    if (DAYSIZE >= 2)  
    {
        strncpy(newString, days[dayIndex], DAYSIZE);
    }
    return newString;
}

int printDayLabel (int DAYSIZE, int dayIndex) // Function that prints out the weekday label.
{ 
    for (int i = 0; i < 7; i++)
    {
        char *day = dayLabel(DAYSIZE, i);
        printf("| %s ", day);
        for (int j = 0; j < DAYSIZE - strlen(day); j++)
        {
            printf(" ");
        }
    }
    printf("|\n");
    separatorLine(DAYSIZE, dayIndex);
    return 0;
}

int printDays (int DAYSIZE, int FIRSTDAY) // a function that prints out all the days in a month.
{
    int maxCharInRow = (DAYSIZE + 3) * 7 + 1 ; // Max number of characters in a row.
    int weekCount = FIRSTDAY;
    int lastDayFlag = 0;
    for (int i = 1; i < FIRSTDAY; i++)
    {
        printf("|");
        for (int j = 1; j < DAYSIZE + 3; j++)
        {
            printf(" ");
        }
    }
    for (int j = 1; j <= 30; j++)
    {
        printf ("| %i", j);
        if (j >= 1 && j <= 9)
        {
            printf(" ");
        }
        for (int k = 0; k < DAYSIZE - 1; k++)
        {
           printf (" ");
        }
        if (weekCount == 7)
        {
            if (j != 30)
            {
                printf ("|\n");
            }
            if ((lastDayFlag = (j == 30) ? 1 : 0) == 0)
            {
                weekCount = 0;
            }
        }
        weekCount++;
    }
    for (int x = weekCount; x <= 7; x++)
    {
        printf("|");
        for (int j = 1; j < DAYSIZE + 3; j++)
        {
            printf(" ");
        }
    }
    if (lastDayFlag != 0)
    {
        weekCount = 1;
    }
    printf("|\n");
    return weekCount;
}

int printMonth (int DAYSIZE, int FIRSTDAY, char month[]) // Function that prints out a full month with days and day-of-the-week labels.
{
    printMonthHeader (DAYSIZE, FIRSTDAY, month);
    printDayLabel (DAYSIZE, FIRSTDAY);
    int lastDay = printDays(DAYSIZE, FIRSTDAY);
    return lastDay;
}

int printCalendar (int DAYSIZE, int FIRSTDAY)  // Prints out a calendar which has input the DAYSIZE and FIRSTDAY
{
    if (FIRSTDAY < 1 || FIRSTDAY > 7)
    {
        return -1;
    }
    if (DAYSIZE < 2)
    {
        return -1;
    }
    int lastDay = FIRSTDAY;
    for (int i = 0; i < 12; i++)
    {
        lastDay = printMonth(DAYSIZE, lastDay, months[i]);
    }
    separatorLine (DAYSIZE, FIRSTDAY);
    return 0;
}

int main(int argc, char *argv[])
{
    printCalendar (atoi(argv[1]), atoi(argv[2])); // Calling the print
    return 0;
}
