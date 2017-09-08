#ifndef Subtraction_h
#define Subtraction_h

#include <string> 
#include <iostream> 
using namespace std;

class Subtraction
{

	//Overload the stream insertion and extraction operators
	friend ostream& operator<< (ostream&, const Subtraction&);
public:
	Subtraction();
	//default constructor
	//Postcondition: theAnswer=0; userResponse=0; 
	//invokes randomize(); 

	void randomize();
	//Function to generate two random numbers between 1 and 10.
	//Postcondition: num1 and num2 are equal to between 1 and 10;
	//and theAnswer = num1 - num2;

	bool checkAnswer();
	//Function to check userAnswer with problem answer (theAnswer)
	//Postcondition: if theAnswer==userResponse appropriate feedback is displayed
	// returns true if user answer is correct or returns false if user answer is incorrect;

	void validate(string str1);
	//Function to validate user response
	//Postcondition: function accepts a string, validates it to be an int;

private:
	int num1;//variable to store one of the operands
	int num2;//variable to store one of the operands
	int theAnswer;//variable to store the answer to the problem
	int userResponse;//variable to store the user response to the problem in int format
};
#endif