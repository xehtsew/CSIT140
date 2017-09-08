#include "Triangle.h"
#include <iostream>

Triangle::Triangle() {
	base = 1;
	height = 1;
}
Triangle::Triangle(double base, double height) {
	base = base;
	height = height;
}

//mutators
void Triangle::setBase(double b) {//used to set the value of the base
	base = b;
}
void Triangle::setHeigth(double h) {//used to set the value of the height
	height = h;
}
//Accessors
double Triangle::getBase() const{
	return base;
}

double Triangle::getHeight()const {
	return height;
}

double Triangle::getArea()const {
	return (base * height) / 2;
}

// Overloaded operators
Triangle Triangle::operator ++() {			// Prefix ++		increase the size of the base by 1 abd height by 1
	++base;
	++height;
	return *this;
}
Triangle Triangle::operator ++(int) {		// Postfix ++		increase the size of the base by 1 abd height by 1
	Triangle temp(base, height);
	base++;
	height++;
	return temp;
}
Triangle Triangle::operator --() {			// Prefix --		decrease the size of the base by 1 abd height by 1
	--base;
	--height;
	return *this;
}
Triangle Triangle::operator --(int) {		// Postfix --		decrease the size of the base by 1 abd height by 1
	Triangle temp(base, height);
	base--;
	height--;
	return temp;
}
	
ostream &operator <<(ostream & strm, const Triangle & obj) { // Overloaded << operator
	strm << obj.base << " base and " << obj.height << " height";
	return strm;
}
//Use this operator to display on the screen the value of the base
//the height and the area of the triangle