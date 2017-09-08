/*
INSTRUCTIONS

You must use this file as a starter file, failure to use this file and not adhere to the requirements will Severely affect your grade

RESTRICTIONS
1. you may not use global variables
2. you may not use GOTO statements
3. you may not use strings
4. you may NOT read user input using strings

REQUIREMENTS
1. you must use the following function EXACTLY as it is:
void validateUserInput(char *UserInputCharArray, int &strLength);
strLength is an int whose value is the number of characters in the user input

2. you must use the following pointer:
char *UserInputCharArray = nullptr;

3. You MUST read the user input using *UserInputCharArray 

4.  You must use the following global constant to declare the size of your pointer:
int const ARRAY_SIZE = 100;

OPTIONS
1. you have the option to declare your own variables, just DON"T violate the restrictions above

*/
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//required function prototype
void validateUserInput(char *UserInputCharArray, int &strLength);

//other function prototypes
void getUserInput(char *UserInputCharArray, int &strLength);
void displayResults(char *UserInputCharArray);

//required global constant
int const ARRAY_SIZE = 100;

int main()
{
	//required char pointer
	char *UserInputCharArray = nullptr;
	//define local variables
	char inputBuffer[ARRAY_SIZE];
	int strLength;
	char continu[ARRAY_SIZE] = { 'Y' };
	//assign pointer
	UserInputCharArray = inputBuffer;

	do {
		system("CLS");
		//call modules for functionality.
		getUserInput(UserInputCharArray, strLength);
		validateUserInput(UserInputCharArray, strLength);
		displayResults(UserInputCharArray);
		//display message to user
		cout << "Enter anything starting with a y/Y to continue, anything else to exit" << endl;
		//get users continue char
		cin.get(continu, ARRAY_SIZE);
		//blow out cin
		cin.ignore();
	} while (toupper(continu[0]) == 'Y');
	//if user entered something other than 'y' or 'Y':
	cout << "Good-Bye!" << endl;
	system("pause");
    return 0;
}

//required function implementation
void validateUserInput(char *UserInputCharArray, int &strLength){
	int counter = 0;
	//conditions
	while (counter < strLength || strLength == 0) {
		//if the char at the counter isnt a digit, dispaly msg, reset counter, call getUserInput again.
		if (!isdigit(*(UserInputCharArray + counter))) {
			cout << "Not a valid integer" << endl;
			counter = 0;
			getUserInput(UserInputCharArray, strLength);
		//otherwise, continue testing chars.
		} else {
			counter++;
		}
	}
}

void getUserInput(char *UserInputCharArray, int &strLength) {
	//local variables
	char buffer[ARRAY_SIZE];
	int counter = 0;
	//msg to user
	cout << "Enter an integer >= 0, and press <ENTER>" << endl;
	//get user input
	cin.get(buffer, ARRAY_SIZE);
	//blow out cin
	cin.clear();
	cin.ignore();
	//loop through chars in buffer and add to array
	for (counter = 0; counter < ARRAY_SIZE; counter++) {
		*(UserInputCharArray + counter) = buffer[counter];
	}
	//length of chars entered stored in strLength reference
	strLength = strlen(UserInputCharArray);
}

void displayResults(char *UserInputCharArray) {
	//local variables
	bool hasEvens = false;
	int count = 0;
	system("CLS");
	//display users number
	cout << "you entered: ";
	while (*(UserInputCharArray + count) != '\0') {
		cout << *(UserInputCharArray + count);
		count++;
	}
	//reset counter, add a line
	count = 0;
	cout << endl << "The even digits are: " << endl;
	//check buffer pointer for evens
	while (*(UserInputCharArray + count) != '\0') {
                if (*(UserInputCharArray + count) % 2 == 0) {
                        cout << *(UserInputCharArray + count) << " ";
                        hasEvens = true;
                }
                count++;
        }
	//if there are no evens
        if (hasEvens == false){
                cout << "There were no even numbers!";
        }
	cout << endl << endl;
}
