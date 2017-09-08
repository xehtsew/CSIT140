I#include "Game.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <string> 
#include <iostream> 
#include <fstream>
#include <iomanip>
using namespace std;

Game::Game() {
	userName = "";the
	totalWages = 0;
	totalCorrect = 0;
	totalWrong = 0;
}
//default constructor
//Postcondition: 
/*
userName = "";//variable to store the user name
totalWages = 0;//variable to store the total earning
totalCorrect = 0;//variable to store the total of correct responses
totalWrong = 0;//variable to store the total of incorrect responses
*/
void Game::splashScreen() {	//Function to display credits and developer information. 
	//choice variable, display credits
	string choice;
	cout << "***************************" << endl;
	cout << "****    theMathGame    ****" << endl;
	cout << "****        by         ****" << endl;
	cout << "**** Matthew Belluardo ****" << endl;
	cout << "***************************" << endl << endl;
	cout << "   Enter y/Y to continue   " << endl;
	cout << "Enter any other key to exit" << endl << endl;
	//if statement for choice
	getline(cin, choice);
	if (choice != "y" && choice != "Y") {
		exit(0);
	}
	else {
		//if not y or Y, call requestName()
		requestName();
	}
}

void Game::menu() {
//user choice variable
	string choice;
	system("cls");
	cout << "****************************" << endl;
	cout << "****  Choose A Problem  ****" << endl;
	cout << "****************************" << endl;
	cout << "****  1. Addition       ****" << endl;
	cout << "****  2. Subtraction    ****" << endl;
	cout << "****  3. Multiplication ****" << endl;
	cout << "****  4. Division       ****" << endl;
	cout << "****  5. Player Stats   ****" << endl;
	cout << "****************************" << endl;
	cout << "****    n/N to Quit     ****" << endl;
	cout << "****************************" << endl << endl;
	getline(cin, choice);
	//create addition object, check the answer, save stats, call menu.
	if (choice == "1") {
		Addition a;
		updateStats(a.checkAnswer());
		saveStats();
		menu();
	//create subtraction object, check the answer, save stats, call menu.
	} else if (choice == "2") {
		Subtraction s;
		updateStats(s.checkAnswer());
		saveStats();
		menu();
	//create multiplication object, check the answer, save stats, call menu.
	} else if (choice == "3") {
		Multiplication m;
		updateStats(m.checkAnswer());
		saveStats();
		menu();
	//create division object, check the answer, save stats, call menu.
	} else if (choice == "4") {
		Division d;
		updateStats(d.checkAnswer());
		saveStats();
		menu();
	//call displaystats
	} else if (choice == "5") {
		displayStats();
	//if exit, save stats and exit.
	} else if (choice == "n" || choice == "N") {
		saveStats();
		exit(0);
	} else {
	//otherwise, message to user.
		cout << "That is not a valid entry!" << endl;
		system("pause");
		menu();
	}
}
//Function to display the menu options and validate them.
//Postcondition: continu is equal to: 1 or 2 or 3 or or 5 or n or N; 

void Game::updateStats(bool correct) {
	//if the guess was correct, add one to totalcorrect, and add relevant money
	if (correct == true) {
		totalCorrect++;
		totalWages = totalWages + 0.05;
	}
	else {
		//if guess was incorrect, add one to total wrong, and detract relevant money
		totalWrong++;
		totalWages = totalWages - 0.03;
	}
}
//Function to update game statistics
//Postcondition: updates totalWages and totalCorrect and totalWrong; 

void Game::displayStats() {
	//load all data previously pulled from input file.
	system("cls");
	cout << left;
	cout << "****************************" << endl;
	cout << "****    Player Stats    ****" << endl;
	cout << "****************************" << endl;
	cout << "****     User Name:     ****" << endl;
	cout << "****    " << setw(13) << userName << "   ****" << endl;
	cout << "****   Total Earnings:  ****" << endl;
	cout << "****   $" << fixed << setprecision(2) << setw(12) << totalWages << "    ****" << endl;
	cout << "****   Total Correct:   ****" << endl;
	cout << "****    " << setw(13) << totalCorrect << "   ****" << endl;
	cout << "****   Total Incorrect: ****" << endl;
	cout << "****    " << setw(13) << totalWrong << "   ****" << endl;
	cout << "****************************" << endl;
	cout << "**** <ENTER> to return  ****" << endl;
	cout << "****   to Main Menu     ****" << endl;
	cout << "****************************" << endl;
	system("pause");
	//call menu after pause
	menu();
}
//Function to display player statistics

void Game::requestName() {
	//temporary player Name
	string playerName;
	int counter = 0;
	//message to user, get input and validate.
	cout << "Enter your name and press <ENTER>" << endl;
	getline(cin, userName);
	validate(userName);

	//check if user exists
	ifstream inputFile;
	inputFile.open(userName + ".txt");
	//define output file
	ofstream outputFile;
	//if no input file, create one.
	if (!inputFile) {
		totalWages = 0.00;
		totalCorrect = 0;
		totalWrong = 0;
		outputFile.open(userName + ".txt");
		saveStats();
	} else {
		//if user exists, welcome them back, and load data.
		cout << "Welcome Back, " << userName << endl;
		inputFile >> userName;
		inputFile >> totalCorrect;
		inputFile >> totalWrong;
		inputFile >> totalWages;
		system("pause");
		//close files
		outputFile.close();
		inputFile.close();
	}
}
	//Function to get userName
	//This function also invokes the validate method which ensures that the userName is valid; that is, it is not numbers, blanks, non-alpha chars or a combination thereof
	//Postcondition: creates a new text file if user is a first-time player or reads statistics from text file if user is a returniong player
	//if the player is a "returning player", the statistics are read into: userName, totalWages, totalCorrect, and totalWrong

void Game::saveStats() {
	//define in and out files based on username.
	ifstream inputFile;
	inputFile.open(userName + ".txt");
	ofstream outputFile;
	outputFile.open(userName + ".txt");
	//iterate each line of data
	outputFile << userName << endl;
	outputFile << totalCorrect << endl;
	outputFile << totalWrong << endl;
	outputFile << totalWages << endl;
	//close files
	outputFile.close();
	inputFile.close();
	}
	//Function to save statistics into text file
	//Postcondition:statistics saved are: userName, totalWages, totalCorrect, and totalWrong

void Game::validate(string& str1) {
	int counter = 0;
	while (counter < str1.length() || str1.length() == 0) {
		if (!isalpha(str1[counter])) {
			cout << "Invalid player name. One word, no special characters." << endl;
			cout << "Enter your name and press <ENTER>" << endl;
			getline(cin, str1);
			counter = 0;
		}
		else {	
			counter++;
		}
	}
	//assign str1 to userName.
	userName = str1;
}
	//Function to validate userName
	//userName is not allowed to be more than one word or numbers, blanks, non-alpha chars or a combination thereof
	//Postcondition: userName is a single word made of alpha chars only