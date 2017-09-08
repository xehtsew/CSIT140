#include <iostream>
#include <string>
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"

using namespace std;
//function prototypes
void displayMenu();
void getUserInput(Circle &c, Square &s, Triangle &t);
Circle createCircle(Circle &c);
Square createSquare(Square &s);
Triangle createTriangle(Triangle &t);
void displayCircleProperties(const Circle &c);
void displaySquareProperties(const Square &s);
void displayTriangleProperties(const Triangle &t);
bool validateUserInput(string userInput);

int main() {
	//call default constructors for shapes.
	Circle c;
	Square s;
	Triangle t;

	//start menu
	displayMenu();
	getUserInput(c, s, t);

	return 0;
}

//displays the menu ONLY
void displayMenu() {
	cout << "Classes and Shapes" << endl << endl;
	cout << "1.  Create a Circle" << endl;
	cout << "1a. Increase the length of the radius of the circle by 1 unit" << endl;
	cout << "1b. Decrease the length of the radius of the circle by 1 unit" << endl;
	cout << "1c. Display property values of the circle" << endl;
	cout << "----------------------------------" << endl;
	cout << "2.  Create a Square" << endl;
	cout << "2a. Increase the length of the side of the square by 1 unit" << endl;
	cout << "2b. Decrease the length of the side of the square by 1 unit" << endl;
	cout << "2c. Display property values of the square" << endl;
	cout << "----------------------------------" << endl;
	cout << "3.  Create a Triangle" << endl;
	cout << "3a. Increase length of base and height of the triangle by 1 unit" << endl;
	cout << "3b. Decrease length of base and height of the triangle by 1 unit" << endl;
	cout << "3c. Display property values of the triangle" << endl;
	cout << "----------------------------------" << endl;
	cout << "4.  Quit" << endl;
} 

//Keeps user in this loop until selection 4 is chosen.
void getUserInput(Circle &c, Square &s, Triangle &t) {
	//local variable.
	string userInput;
	//msg to user, getline userInput.
	cout << "Enter a selection: " << endl;
	getline(cin, userInput);
	//if the user selects ANYTHING that is not a menu choice, a message is given.
	while ((userInput != "1") && (userInput != "1a") && (userInput != "1b") && (userInput != "1c") &&
		(userInput != "2") && (userInput != "2a") && (userInput != "2b") && (userInput != "2c") &&
		(userInput != "3") && (userInput != "3a") && (userInput != "3b") && (userInput != "3c") &&
		(userInput != "4")) {
		cout << "That is not a valid response" << endl;
		cout << "Enter a selection: " << endl;
		getline(cin, userInput);
	}
	//---------------menu choice 1 calls createCircle
		if (userInput == "1") { //create circle
			createCircle(c);
			displayCircleProperties(c);
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
	//---------------menu choice 1a calls overridden ++ operator

		else if (userInput == "1a") {//increase circle by 1
			c++;
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
	//---------------menu choice 1b calls overridden -- operator

		else if (userInput == "1b") {//decrease circle by 1
			if (c.getRadius() <= 1) {
				cout << "Cannot decrease size to less than 1!" << endl;
			}
			else {
			c--;
			cout << "Done!" << endl;
			}
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
	//---------------menu choice 1c dislpays circle properties

		else if (userInput == "1c") {//display circle
			displayCircleProperties(c);
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		//---------------menu choice 2 calls createSquare

		else if (userInput == "2") {//square
			createSquare(s);
			displaySquareProperties(s);
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		//---------------menu choice 2a calls overridden ++ operator

		else if (userInput == "2a") {//increase square by 1
			s++;
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		//---------------menu choice 2b calls overridden -- operator

		else if (userInput == "2b") {//decrease square by 1
			if (s.getLength() <= 1) {
				cout << "Cannot decrease size to less than 1!" << endl;
			}
			else {
				s--;
				cout << "Done!" << endl;
			}
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		//---------------menu choice 2c dislpays square properties

		else if (userInput == "2c") {//display square
			displaySquareProperties(s);
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		//---------------menu choice 3 calls createTriangle

		else if (userInput == "3") {//create triangle
			createTriangle(t);
			displayTriangleProperties(t);
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		//---------------menu choice 3a calls overridden ++ operator

		else if (userInput == "3a") {//increase triangle by 1
			t++;
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		//---------------menu choice 3b calls overridden -- operator

		else if (userInput == "3b") {//decrease triangle by 1
			if (t.getHeight() <= 1 || t.getBase() <= 1) {
				cout << "Cannot decrease base or height to less than 1!" << endl;
			}
			else {
				t--;
				cout << "Done!" << endl;
			}
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		//---------------menu choice 3c dislpays triangle properties

		else if (userInput == "3c") {//display triangle properties
			displayTriangleProperties(t);
			system("pause");
			system("cls");
			displayMenu();
			getUserInput(c, s, t);
		}
		else if (userInput == "4") {//quit
			//just quits
		}
	}
	//create circle displays messages to user, and validates input.
Circle createCircle(Circle &c) {
	double radias;
	string userInput;
	cout << "Enter radius size for new circle: " << endl;
	getline(cin, userInput);
	while (validateUserInput(userInput) == false) {
		cout << "That is not a valid size" << endl;
		cout << "Enter radius size for new circle: " << endl;
		getline(cin, userInput);
	}
	radias = stod(userInput);
	c.setRadius(radias);
	return c;
}
//create sqaure displays messages to user, and validates input.

Square createSquare(Square &s) {
	double length;
	string userInput;
	cout << "Enter length of a side for the new square: " << endl;
	getline(cin, userInput);
	while (validateUserInput(userInput) == false) {
		cout << "That is not a valid size" << endl;
		cout << "Enter length of a side for the new square: " << endl;
		getline(cin, userInput);
	}
	length = stod(userInput);
	s.setLength(length);
	return s;
}
//create triangle displays messages to user, and validates input.

Triangle createTriangle(Triangle &t) {
	double base;
	double height;
	string userInput;
	cout << "Enter the base of the new triangle: " << endl;
	getline(cin, userInput);
	while (validateUserInput(userInput) == false) {
		cout << "That is not a valid size" << endl;
		cout << "Enter the base of the new triangle: " << endl;
		getline(cin, userInput);
	}
	base = stod(userInput);
	t.setBase(base);
	userInput = "";
	cout << "Enter height of the new triangle: " << endl;
	getline(cin, userInput);
	while (validateUserInput(userInput) == false) {
		cout << "That is not a valid size" << endl;
		cout << "Enter height of the new triangle: " << endl;
		getline(cin, userInput);
	}
	height = stod(userInput);
	t.setHeigth(height);
	return t;
}
//display circle displays messages to user, and calls additional functions.

void displayCircleProperties(const Circle &c) {
	cout << "The radius is " << c.getRadius() << endl;
	cout << "The area is " << c.getArea() << endl;
	cout << "The circumfrence is " << c.getCirumference() << endl;
}
//display square displays messages to user, and calls additional functions.

void displaySquareProperties(const Square &s) {
	cout << "The length of a side is " << s.getLength() << endl;
	cout << "The area is " << s.getArea() << endl;
	cout << "The perimeter is " << s.getPerimeter() << endl;
}
//display triangle displays messages to user, and calls additional functions.

void displayTriangleProperties(const Triangle &t) {
	cout << "The base is " << t.getBase() << ", the height is " << t.getHeight() << endl;
	cout << "The area is " << t.getArea() << endl;
}

//validate user Input simply validates the users input as a DOUBLE.
bool validateUserInput(string userInput) {
	int decimalNum = 0;
	bool validated = true;
	if (userInput.length() == 0) {
		validated = false;
	}
	for (int i = 0; i < userInput.length(); i++) {
		if (!isdigit(userInput[i]) && userInput[i] != '.') {
			validated = false;
		}
		if (userInput[i] == '.') {
			decimalNum++;
		}
	}
	if (decimalNum > 1) {
		validated = false;
	}
	return validated;
}