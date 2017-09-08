// Final exam
#include <iostream>
#include <cstring>
#include "myStringClass.h"
using namespace std;


int main()
{
	//object declaration
	//default constructor
	myStringClass last, first, age;

	cout << "Enter your first name only\n";
	cin >> first;//overloaded cin
	myStringClass::validateUserInput(first);

	cout << "what is your last name?\n";
	cin >> last;//overloaded cin
	myStringClass::validateUserInput(last);

	cout << "enter your age\n";
	cin >> age;
	myStringClass::validateUserInt(age);

	//overloaded cout
	cout << "hello " << first << " " << last << ", age: " << age << endl;
	
	//object declaration
	//overloaded constructor
	//leftside longer and less
	myStringClass string1 = "abx";
	myStringClass string2 = "ax";

	//overloaded logical operators: ==, < and >
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 < string2)
	{
		cout << string1 << " < " << string2;
	}
	else
	{
		cout << string1 << " > " << string2;
	}
	cout << endl;

	string1 = "axb";
	string2 = "aa";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 < string2)
	{
		cout << string1 << " < " << string2;
	}
	else
	{
		cout << string1 << " > " << string2;
	}
	cout << endl;

	string1 = "ab";
	string2 = "axb";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 < string2)
	{
		cout << string1 << " < " << string2;
	}
	else
	{
		cout << string1 << " > " << string2;
	}
	cout << endl;


	string1 = "ax";
	string2 = "aax";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 < string2)
	{
		cout << string1 << " < " << string2;
	}
	else
	{
		cout << string1 << " > " << string2;
	}
	cout << endl;

	string1 = "abcz";
	string2 = "abc";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 < string2)
	{
		cout << string1 << " < " << string2;
	}
	else
	{
		cout << string1 << " > " << string2;
	}
	cout << endl;

	string1 = "abc";
	string2 = "abcz";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 < string2)
	{
		cout << string1 << " < " << string2;
	}
	else
	{
		cout << string1 << " > " << string2;
	}
	cout << endl;

	string1 = "abc";
	string2 = "abc";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 < string2)
	{
		cout << string1 << " < " << string2;
	}
	else
	{
		cout << string1 << " > " << string2;
	}
	cout << endl;
	

	 string1 = "abx";
	 string2 = "ax";

	//overloaded logical operators: ==, < and >
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 <= string2)
	{
		cout << string1 << " <= " << string2;
	}
	else
	{
		cout << string1 << " >= " << string2;
	}
	cout << endl;

	string1 = "axb";
	string2 = "aa";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 <= string2)
	{
		cout << string1 << " <= " << string2;
	}
	else
	{
		cout << string1 << " >= " << string2;
	}
	cout << endl;

	string1 = "ab";
	string2 = "axb";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 <= string2)
	{
		cout << string1 << " <= " << string2;
	}
	else
	{
		cout << string1 << " >= " << string2;
	}
	cout << endl;

	string1 = "ax";
	string2 = "aax";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 <= string2)
	{
		cout << string1 << " <= " << string2;
	}
	else
	{
		cout << string1 << " >= " << string2;
	}
	cout << endl;

	string1 = "abcz";
	string2 = "abc";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 <= string2)
	{
		cout << string1 << " <= " << string2;
	}
	else
	{
		cout << string1 << " >= " << string2;
	}
	cout << endl;

	string1 = "abc";
	string2 = "abcz";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 <= string2)
	{
		cout << string1 << " <= " << string2;
	}
	else
	{
		cout << string1 << " >= " << string2;
	}
	cout << endl;

	string1 = "abc";
	string2 = "abc";
	if (string1 == string2)
	{
		cout << string1 << " = " << string2;
	}
	else if (string1 <= string2)
	{
		cout << string1 << " <= " << string2;
	}
	else
	{
		cout << string1 << " >= " << string2;
	}
	cout << endl;

	//array of myStringClass
	myStringClass arrayOfNames[5];

	for (int x = 0; x < 5; x++)
	{
		cout << "enter name " << x + 1 << endl;
		cin >> arrayOfNames[x];
		myStringClass::validateUserInput(arrayOfNames[x]);
	}
	cout << "The names you entered are:\n";
	for (int x = 0; x < 5; x++)
	{
		cout << arrayOfNames[x] << endl;
	}


	string2 = "Hello ";
	//object declaration
	//copy constructor
	myStringClass string3(string2);
	myStringClass string4 = string3 + "World";
	cout << string4 << endl;

	cout << "Good-bye" << endl;
	system("pause");

	return 0;
}


