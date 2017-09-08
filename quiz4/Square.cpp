#include "Square.h"
#include <iostream>

Square::Square() {
	length = 1;
}
Square::Square(double side) {
	//get the length from user
	length = side;
}

//mutator
void Square::setLength(double side) {	//used to set the value of the length
	length = side;
}

//accessor
double Square::getLength() const {
	return length;
}
double Square::getArea() const {
	return length * length;
}
double Square::getPerimeter() const {
	return length * 4;
}

// Overloaded operators
Square Square::operator ++() {		// Prefix ++		increase the size of the length by 1
	++length;
	return *this;
}
Square Square::operator ++(int){	// Postfix ++		increase the size of the length by 1
	Square temp(length);
	length++;
	return temp;
}
Square Square::operator --(){		// Prefix --		decrease the size of the length by 1
	--length;
	return *this;
}
Square Square::operator --(int){	// Postfix --			decrease the size of the length by 1
	Square temp(length);
	length--;
	return temp;
}
ostream &operator <<(ostream & strm, const Square & obj) { // Overloaded << operator
	strm << obj.length << " length";
	return strm;
}
//Use this operator to display on the screen the value of the 
//length, the area and the perimeter of the square