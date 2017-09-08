#ifndef Game_h
#define Game_h


#include <string> 
#include <iostream> 
#include <fstream>
using namespace std;

class Game
{
public:
	
	Game();
	//default constructor
	//Postcondition: 
	/*
	userName = "";//variable to store the user name
	totalWages = 0;//variable to store the total earning
	totalCorrect = 0;//variable to store the total of correct responses
	totalWrong = 0;//variable to store the total of incorrect responses
	*/
	void  splashScreen ();
	//Function to display credits and developer information. 

	void  menu();
	//Function to display the menu options and validate them.
     //Postcondition: continu is equal to: 1 or 2 or 3 or or 5 or n or N; 

	void  updateStats(bool correct);
	//Function to update game statistics
     //Postcondition: updates totalWages and totalCorrect and totalWrong; 

	void  displayStats();
	//Function to display player statistics
    
	void  requestName();
	//Function to get userName
	//This function also invokes the validate method which ensures that the userName is valid; that is, it is not numbers, blanks, non-alpha chars or a combination thereof
     //Postcondition: creates a new text file if user is a first-time player or reads statistics from text file if user is a returniong player
	//if the player is a "returning player", the statistics are read into: userName, totalWages, totalCorrect, and totalWrong

	void  saveStats();
	//Function to save statistics into text file
     //Postcondition:statistics saved are: userName, totalWages, totalCorrect, and totalWrong

	void validate(string& str1);
	//Function to validate userName
	//userName is not allowed to be more than one word or numbers, blanks, non-alpha chars or a combination thereof
     //Postcondition: userName is a single word made of alpha chars only
	
private:
	string userName;//variable to store the user name
	double totalWages;//variable to store the total earning
	int totalCorrect;//variable to store the total of correct responses
	int totalWrong;//variable to store the total of wrong responses
	const double REWARD = 0.05;//constant to store 0.05 as a reward for every correct problem
	const double PENALTY = 0.03;//constant to store 0.03 as a penalty for evry wrong problem
	ofstream outData;//used to open file for saving stats
	ifstream inData;//used to open file for retrieving stats
};
#endif