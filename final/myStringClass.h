#ifndef myStringClass_h
#define myStringClass_h

#include <iostream> 
using namespace std;

class myStringClass
{

	//Overload the stream insertion and extraction operators
	friend ostream& operator<< (ostream&, const myStringClass&);
	friend istream& operator>> (istream&, myStringClass&);
public:
	//default constructor
	myStringClass();
	
	//overloaded constructors
	myStringClass(const char* str);

	//destructor
	~myStringClass();

	//getter
	int stringLength() const;
	
	//overload =
	myStringClass& operator=(const myStringClass&);

	//overload []
	char& operator[](int index);

	//overload +//the concatenation operator
	myStringClass& operator+(const myStringClass&);

	//the following all return a bool

	//overload ==
	bool operator==(const myStringClass&);

	//overload !=
	bool operator!=(const myStringClass&);

	//overload <=
	bool operator<=(const myStringClass&);

	//overload <
	bool operator<(const myStringClass&);

	//overload >=
	bool operator>=(const myStringClass&);

	//overload >
	bool operator>(const myStringClass&);

   static void validateUserInput(myStringClass& myStringClassObject);
   static void validateUserInt(myStringClass& myStringClassObject);
private:
	char* userInput;   // Array to hold input
	int userInputLength;
	
	
	
};
#endif