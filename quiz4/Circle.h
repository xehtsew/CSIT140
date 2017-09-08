#ifndef Circle_H
#define Circle_H
#include <iostream>
using namespace std;
class Circle;//forward declaration

//some compilers require to prototype the << and >> operator functions
 ostream &operator <<(ostream & someStream, const Circle & someCircle); // Overloaded << operator

class Circle
{
public:
	//contructors
	Circle();//default value of radius = 1;
	Circle(double r);
	
	//mutator
	void setRadius(double r);//used to set the value of the radius

	//Accessors
	double getRadius() const;
	double getArea() const;
	double getCirumference() const;

// Overloaded operators
   Circle operator ++();				// Prefix ++    increase the size of the radius by 1
   Circle operator ++(int);				// Postfix ++   increase the size of the radius by 1
   Circle operator --();				// Prefix --    decrease the size of the raious by 1
   Circle operator --(int);			// Postfix --       decrease the size of the raious by 1


   friend ostream &operator <<(ostream &, const Circle &); // Overloaded << operator
   /*Use this operator to display on the screen the value of the radius, the area and the circumference of the circle
   */


private:
	double radius;
};
#endif