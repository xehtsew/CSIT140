#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//function prototypes
void readDataToArray(struct studentType (&student)[20], ifstream &inputFile, ofstream &outputFile);
char assignGradeLetter(int testScore);
void findHighestTestScore(const struct studentType (&student)[20], ofstream &outputFile);
void printHighestTestScoreNames(struct studentType student[20], ofstream &outputFile);

//struct definition
struct studentType {
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

int main() {
	//declare variables
	studentType student[20];
	ifstream inputFile;
	ofstream outputFile;
	//open and test files
	inputFile.open("Data.txt");
	outputFile.open("Out.txt");
	if (!inputFile) {
		cout << "Cannot locate Data.txt. Are you sure its in the right place?" << endl;
	} else {		//call functions
		readDataToArray(student, inputFile, outputFile);
		findHighestTestScore(student, outputFile);
		printHighestTestScoreNames(student, outputFile);
		cout << "Program completed successfully" << endl << endl;
	}	//close files when finished.
	inputFile.close();
	outputFile.close();
	system("pause");
	return 0;
}

//read the data in to each struct in the array
void readDataToArray(struct studentType (&student)[20], ifstream &inputFile, ofstream &outputFile) {
	//local variable for name length calculation
	string studentName;
	outputFile << "Student Name\t\tTestScore\tGrade" << endl;
	for (int i = 0; i < 20; i++) {
		inputFile >> student[i].studentFName >> student[i].studentLName >> student[i].testScore;
		student[i].grade = assignGradeLetter(student[i].testScore);
		studentName = student[i].studentLName + ", " + student[i].studentFName;
		outputFile << studentName << setw(29 - studentName.length()) << student[i].testScore << "\t\t  " << student[i].grade << endl;
	}// setw(29) just looked nicer than setw(30) in the text file...
}

//find the corresponding letter grade for each students test score.
char assignGradeLetter(int testScore) {
	char letterGrade;
		if (testScore >= 90) {
			letterGrade = 'A';
		} else if (testScore >= 80 && testScore < 90) {
			letterGrade = 'B';
		} else if (testScore >= 70 && testScore < 80) {
			letterGrade = 'C';
		} else if (testScore >= 60 && testScore < 70) {
			letterGrade = 'D';
		} else if (testScore <= 59) {
			letterGrade = 'F';
		}
	return letterGrade;
}

//send array of structs as immutable to find highest score.
void findHighestTestScore(const struct studentType (&student)[20], ofstream &outputFile) {
	int highestScore = 0;
	for (int i = 0; i < 20; i++) {
		if (student[i].testScore > highestScore) {
			highestScore = student[i].testScore;
		}		
	}
	outputFile << endl << "Highest Test Score: " << highestScore << endl;
}

	//array of structs passed by value to sort.. couldve passed by reference.. 
void printHighestTestScoreNames(struct studentType student[20], ofstream &outputFile) {
	//BUBBLE SORT!
	for (int i = 0; i < 20; i++) {
		for (int j = 19; j > i; j--) {
			if (student[j].testScore < student[j - 1].testScore) {
				studentType temp = student[j - 1]; //temporary struct for sorting only
				student[j - 1] = student[j];
				student[j] = temp;
			}
		}
	}
	outputFile << endl << "Students Having the Highest Test Score: " << endl;
	//print students
	for (int i = 19; i > 13; i--) {
		outputFile << student[i].studentLName << ", " << student[i].studentFName << endl;
	}
}