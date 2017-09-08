#include "Multiplication.h"
#include <string> 
#include <iostream> 
#include <iomanip>
using namespace std;

	//Overload the stream insertion and extraction operators
ostream& operator<< (ostream& strm, const Multiplication& obj) {
	strm << obj.num1 << obj.num2;
	return strm;
}
Multiplication::Multiplication() {
	theAnswer = 0;
	userResponse = 0;
	randomize();
}
	//default constructor
	//Postcondition: theAnswer=0; userResponse=0; 
	//invokes randomize(); 

void Multiplication::randomize() {
	//hold temporary user input
	string userInputBuffer;
	//seed random number generator
	srand(time(0));
	//random numbers
	num1 = (rand() % 10) + 1;
	num2 = (rand() % 10) + 1;
	//correct answer
	theAnswer = num1 * num2;
	system("cls");
	//display problem
	cout << "****************************" << endl;
	cout << "****  Multiplication *******" << endl;
	cout << "****************************" << endl;
	cout << "****     " << setw(2) << num1 << " * " << setw(2) << num2 << "        ****" << endl;
	cout << "****************************" << endl;
	//get user input, send to validation loop
	getline(cin, userInputBuffer);
	validate(userInputBuffer);
	//validation loop completes only when user enters correct format
	//display results of check answer
	if (checkAnswer() == true) {
		cout << "Correct!" << endl;
		system("pause");
	}
	else if (checkAnswer() == false) {
		cout << "Incorrect!" << endl;
		system("pause");
	}
}
	//Function to generate two random numbers between 1 and 10.
	//Postcondition: num1 and num2 are equal to between 1 and 10;
	//and theAnswer = num1 * num2;

	bool Multiplication::checkAnswer() {
		if (userResponse == theAnswer) {
			return true;
		}
		else {
			return false;
		}
	}
	//Function to check userAnswer with problem answer (theAnswer)
	//Postcondition: if theAnswer==userResponse appropriate feedback is displayed
	// returns true if user answer is correct or returns false if user answer is incorrect;

	void Multiplication::validate(string str1) {
		int counter = 0;
		while (counter < str1.length() || str1.length() == 0) {
			if (!isdigit(str1[counter])) {
				cout << "that is not a whole number > 0. Try again." << endl;
				getline(cin, str1);
				counter = 0;
			}
			else {
				counter++;
			}
		}
		//cast str1 as integer and store in Multiplication::userResponse

		userResponse = stoi(str1);
	}
	//Function to validate user response
	//Postcondition: function accepts a string, validates it to be an int;