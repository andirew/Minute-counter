/**************************************************************\
*                                                              *
* Name: Assign2.1.c                                            *
* Purpose:                                                     *
* This program will prompt a user to enter the hour, minute,   *
* either A (for AM) or P (for PM), and a number that represents*
* how many consecutive minutes are to be displayed             *
*                                                              *
*                                                              *
****************************************************************
* MODIFICATION HISTORY:                                        *
* 5/25/2017: Andrew Barsoom - created                           *
\**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//set of definition for MIN/MAX's for validation of inputs.
#define MAX_DISPLAY_MINUTE 60
#define MIN_DISPLAY_MINUTE 0
#define MIN_HOUR 1
#define MAX_HOUR 12
#define MIN_MINUTE 0
#define MAX_MINUTE 59
#define AM 'A'
#define PM 'P'
//----------------------------------
//Function prototypes
void flushKeyBoard();
int validation(int num, int max, int min);
char AMPMvalid(char ampm);
void print(int hour, int minute, char ampm, int display);
void display();
//----------------------------------

/********************************************************************\
*                                                                    *
* Name       : main()                                                *
* Parameters :                                                       *
* Returns    : int                                                   *
* Description:                                                       *
* Function controller and calls display function.                    *
**********************************************************************
* MODIFICATION HISTORY                                               *
*                                                                    *
* 5/25/2017 - Andrew Barsoom - Created                               *
*                                                                    *
\********************************************************************/
int main() {
	display();
	return 0;
}

/********************************************************************\
*                                                                    *
* Name       : display()                                             *
* Parameters :                                                       *
* Returns    :                                                       *
* Description:                                                       *
* This module prompts the user to enter the hour,minute and AM/PM,   *
* and the consective times to display and calls the validation       *
* function                                                           *
**********************************************************************
* MODIFICATION HISTORY                                               *
*                                                                    *
* 5/25/2017 - Andrew Barsoom - Created                               *
*                                                                    *
\********************************************************************/
void display() {
	int hour, minute, display;//Variables to store hour,minutes and consective displays wanted
	char ampm; //Variable to hold ampm char
	printf("Enter the hour: ");//prompt user for input
	if (scanf("%d", &hour)) {}; // if statment to suppress scanf return warning.
	flushKeyBoard(); //clear input buffer
	hour = validation(hour, MAX_HOUR, MIN_HOUR); //calls validation function and passes user input

	printf("Enter the minute: "); //prompt user for input
	if (scanf("%d", &minute)) {}; // if statment to suppress scanf return warning.
	flushKeyBoard();//clear input buffer
	minute = validation(minute, MAX_MINUTE, MIN_MINUTE); //calls validation function and passes user input


	printf("Enter A (for AM) or P (for PM): "); //prompt user for input
	if (scanf("%c", &ampm)) {}; // if statment to suppress scanf return warning.
	flushKeyBoard();//clear input buffer
	ampm = AMPMvalid(ampm);//calls validation function and passes user input

	printf("Enter how many minutes to display: "); //prompt user for input
	if(scanf("%d", &display)) {}; // if statment to suppress scanf return warning.
	flushKeyBoard();//clear input buffer
	display = validation(display, MAX_DISPLAY_MINUTE, MIN_DISPLAY_MINUTE); //calls validation function and passes user input
	print(hour, minute, ampm, display);//calls display function to print variables

}

/********************************************************************\
*                                                                    *
* Name       : print()                                               *
* Parameters : hour, minute, ampm, display                           *
* Returns    :                                                       *
* Description:                                                       *
* This Module handles the incrementation of time and display it to   *
* the user                                                           *
*                                                                    *
**********************************************************************
* MODIFICATION HISTORY                                               *
*                                                                    *
* 5/25/2017 - Andrew Barsoom - Created                               *
*                                                                    *
\********************************************************************/
void print(int hour, int minute, char ampm, int display) {
	printf("The new time is \n");
	minute += 1;//Start at an incremented time
	int i; //Variable for a for loop
		for (i = 1; i <= display; i++) { //for loop for displaying all the numbers
		
			if (minute == 60) { //Check to increase hour if minute reaches 60
				hour += 1;
				minute = 0;
			}
			if (hour == 13) {//12 Hour clock fix
				hour = 1;
			}
			if (hour == 12 && minute == 0) { //Convert AM to PM if noon, and vice versa after midnight
				if (ampm == 'A') {
					ampm = 'P';
				}
				else if (ampm == 'P') {
					ampm = 'A';
				}
				printf("%d:%02d %cM \n", hour, minute,ampm);
			}
			else {
				printf("%d:%02d %cM \n", hour, minute, ampm);
			}
			minute++;//Increment minutes.
		}
	
	
}
/**************************************************************\
*                                                              *
* Name       : flushKeyBoard()                                 *
* Parameters : none                                            *
* Returns    : none                                            *
* Description:                                                 *
* This module empties the keyboard buffer so that the next     *
* time input is required there is no "old" data still present. *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/25/2017 - Andrew Barsoom - Created                         *
*                                                              *
\**************************************************************/
void flushKeyBoard()
{
	int ch;  // A dummy variable to read data into

	while ((ch = getc(stdin)) != EOF && ch != '\n') //clear input buffer

		;
}
/**************************************************************\
*                                                              *
* Name       : AMPMvalid()                                     *
* Parameters : dn                                              *
* Returns    : Char                                            *
* Description:                                                 *
* Validates user input for characters                          *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/25/2017 - Andrew Barsoom - Created                         *
*                                                              *
\**************************************************************/
char AMPMvalid(char DN) {
	while (DN != AM && DN != PM) { //Check to make sure that they did not input A Or P
		
			printf("Invalid value entered. Must be 'A' or 'P', please re-eneter: ");
			if (scanf("%c", &DN)) {};//Scan for new user input
			flushKeyBoard(); //clear input buffer
		
	}
	return DN; //return input
}
/**************************************************************\
*                                                              *
* Name       : validation()                                    *
* Parameters : num, max, min                                   *
* Returns    : int                                             *
* Description:                                                 *
* Validates user input                                         *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 5/25/2017 - Andrew Barsoom - Created                         *
*                                                              *
\**************************************************************/
int validation(int num,int max, int min) {

	//Input validation function
	while (num < min || num > max) { //Ensures all inputs are within the parameter ranged
		printf("Invalid value entered. Must be %d to %d, please re-enter: ", min, max);
		if (scanf("%d", &num)) {}; //scan user input
		flushKeyBoard(); //clear input buffer
	}
	return num;//return correct value.

}

