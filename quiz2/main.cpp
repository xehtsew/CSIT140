
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

char getVowelAtIndex(int index, bool isUpperCase);
int getIndexOfMostCommonVowel(int vowels[]);

int main()
{
	//local variable for user continue
	char continu[1] = { 'Y' };
	do {
		//initalize vowel arrays.
		int lowerVowel[5] = { 0 };
		int upperVowel[5] = { 0 };

		system("CLS");


		//msg to user
		cout << "Enter a string:" << endl;



		//redefine input parameters for dynamic input
		int inputCharCount = 0;
		char c;
		char *temp = nullptr;
		char *UserInputCharArray = nullptr;
		UserInputCharArray = new char[inputCharCount];

		//----------------------------------------------------------
		//          start dynamic memory allocation
		//----------------------------------------------------------

		while ((cin.get(c)) && (c != '\n')) {
			//make new pointer array dynamically
			temp = new char[inputCharCount + 1];
			//count holds count + 1, so count gets the cin char.
			temp[inputCharCount] = c;
			//now temp holds ONLY the cin char at its last index.
			//copy data from words array
			for (int i = 0; i < inputCharCount; i++) {
				temp[i] = UserInputCharArray[i];
			}
			//free up memory, ready to copy.
			delete[] UserInputCharArray;
			//copy temp to words
			UserInputCharArray = temp;
			//increment counter
			inputCharCount++;
		}

		//----------------------------------------------------------
		//  start looping through collected input and count vowels
		//----------------------------------------------------------

		int vowelCounter = 0;
		//while the char isnt the terminator, loop.
		while (*(UserInputCharArray + vowelCounter) != '\0') {

			//I would have used a switch statement here instead for sexier code,
			// but wasnt sure if the break statments would violate rules
			if (*(UserInputCharArray + vowelCounter) == 'a') {
				lowerVowel[0]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'e') {
				lowerVowel[1]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'i') {
				lowerVowel[2]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'o') {
				lowerVowel[3]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'u') {
				lowerVowel[4]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'A') {
				upperVowel[0]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'E') {
				upperVowel[1]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'I') {
				upperVowel[2]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'O') {
				upperVowel[3]++;
			}
			else if (*(UserInputCharArray + vowelCounter) == 'U') {
				upperVowel[4]++;
			}
			//increment vowelCounter
			vowelCounter++;
		}

		//----------------------------------------------------------
		//print the vowels contained in the string. 
		//----------------------------------------------------------

		cout << "\nThe vowels present in the string are: ";
		for (int i = 0; i < 5; i++) {
			if (lowerVowel[i] != 0) {
				cout << getVowelAtIndex(i, false) << " ";
			}
			if (upperVowel[i] != 0) {
				cout << getVowelAtIndex(i, true) << " ";
			}
		} cout << endl << endl;


		//**********************************************************
		//              2 cases: lower, and upper.
		//**********************************************************

		//----------------------------------------------------------
		//                         lower case
		//----------------------------------------------------------
		//if there are no vowels
		if (lowerVowel[0] == 0 && lowerVowel[1] == 0 && lowerVowel[2] == 0 && lowerVowel[3] == 0 && lowerVowel[4] == 0) {
			cout << "There are no lower case vowels" << endl;
			//if there is no single most common vowel
		}
		else if (getIndexOfMostCommonVowel(lowerVowel) == 9) { //9 is a signal that there is no highest number. 
															   //there is no index associated with 9.
			cout << "There is no most frequently occuring lower case vowel" << endl;
			//display results
		}
		else {
			cout << "The highest, most frequently occuring lower case vowel is " << endl;
			cout << getVowelAtIndex(getIndexOfMostCommonVowel(lowerVowel), false);
			cout << " with a frequency of " << lowerVowel[getIndexOfMostCommonVowel(lowerVowel)] << endl;
		}
		cout << endl;

		//----------------------------------------------------------
		//                         upper case
		//----------------------------------------------------------
		//if there are no vowels
		if (upperVowel[0] == 0 && upperVowel[1] == 0 && upperVowel[2] == 0 && upperVowel[3] == 0 && upperVowel[4] == 0) {
			cout << "There are no upper case vowels" << endl;
			//if there is no single most common vowel
		}
		else if (getIndexOfMostCommonVowel(upperVowel) == 9) { //9 is a signal that there is no highest number. 
															   //there is no index associated with 9.
			cout << "There is no most frequently occuring upper case vowel" << endl;
			//display results
		}
		else {
			cout << "The highest, most frequently occuring upper case vowel is " << endl;
			cout << getVowelAtIndex(getIndexOfMostCommonVowel(upperVowel), true);
			cout << " with a frequency of " << upperVowel[getIndexOfMostCommonVowel(upperVowel)] << endl;
		}
		cout << endl;
		system("pause");

		//----------------------------------------------------------
		//               game over, ask for continue
		//----------------------------------------------------------

		//display message to user
		cout << "\nEnter y/Y to continue, anything else to exit" << endl;
		//get users continue char
		cin >> continu;
		//blow out cin
		cin.ignore(100,'\n');
	} while (toupper(continu[0]) == 'Y');
	//if user entered something other than 'y' or 'Y':
	return 0;
}


//custom methods

char getVowelAtIndex(int index, bool isUpperCase) {
	//the index of the vowel arrays correspond to
	//a:0 e:1 i:2 o:3 u:4
	//this function returns the correct upper
	//or lower case based on the bool.
	if (index == 0) {
		return isUpperCase == true ? 'A' : 'a';
	}
	else if (index == 1) {
		return isUpperCase == true ? 'E' : 'e';
	}
	else if (index == 2) {
		return isUpperCase == true ? 'I' : 'i';
	}
	else if (index == 3) {
		return isUpperCase == true ? 'O' : 'o';
	}
	else if (index == 4) {
		return isUpperCase == true ? 'U' : 'u';
	}
}

int getIndexOfMostCommonVowel(int vowels[]) {
	//start with null (could be zero... the program wouldnt reach this point
	//unless there are vowels in the input), and even if there are no vowels
	//at index 0, the null will be changed to the right index by the finish
	int largest = NULL;
	//check if the index counter is greater than the largest, and assign
	//if not, ignore.
	for (int index = largest; index < 5; index++) {
		if (vowels[largest] < vowels[index]) {
			largest = index;
		}
	}

	//reset counter.
	int index = 0;
	while (index < 5) {
		//if the currently running index is the SAME as the largest index, ignore.
		//otherwise, it would break every time it gets to the same number 
		if (index == largest) {
			index++;
			//if the index of the vowels parameter equals the largest found number,
			//there is NO HIGHEST NUMBER, and largest becomes 9 (which we will use to
			//send the message to the program that there is no highest number.
			// even though there is no index associated with 9
		}
		else if (vowels[index] == vowels[largest]) {
			largest = 9;
			index++;
			//if no other situations apply:
		}
		else {
			index++;
		}
	}
	return largest;
}