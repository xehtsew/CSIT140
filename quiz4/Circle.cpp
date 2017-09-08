#include "Circle.h"
#include <iostream>

Circle::Circle(){
	radius = 1;
}
//contructors
Circle::Circle(double r) {
	radius = r;
}
//mutator
void Circle::setRadius(double r) { //used to set the value of the radius
	radius = r;
}
//Accessors
double Circle::getRadius() const {
	return radius;
}
double Circle::getArea() const {
	return 3.1416 * (radius * radius);
}
double Circle::getCirumference() const {
	return radius * 3.1416 * 2;

}

// Overloaded operators
Circle Circle::operator ++() {				// Prefix ++    increase the size of the radius by 1
	++radius;
	return *this;
}
Circle Circle::operator ++(int) {			// Postfix ++   increase the size of the radius by 1
	Circle temp(radius);
	radius++;
	return temp;
}
Circle Circle::operator --() {				// Prefix --    decrease the size of the raious by 1
	--radius;
	return *this;
}
Circle Circle::operator --(int) {			// Postfix --       decrease the size of the raious by 1
	Circle temp(radius);
	radius--;
	return temp;
}

ostream &operator <<(ostream & strm, const Circle & obj) { // Overloaded << operator
	strm << obj.radius << " radius";
	return strm;
}
//Use this operator to display on the screen the value of the radius, 
//the area and the circumference of the circle

