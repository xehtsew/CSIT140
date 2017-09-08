#ifndef Square_H
#define Square_H
using namespace std;
class Square;//forward declaration

//some compilers require to prototype the << and >> operator functions
 ostream &operator <<(ostream & someStream, const Square & someSquare); // Overloaded << operator

class Square
{
public:
	Square();//default value of length = 1;
	Square(double side);

	//mutator
	void setLength(double side);//used to set the value of the length

	//Accessors
	double getLength() const;
	double getArea() const;
	double getPerimeter() const;

	// Overloaded operators
   Square operator ++();				// Prefix ++		increase the size of the length by 1
   Square operator ++(int);				// Postfix ++		increase the size of the length by 1
   Square operator --();				// Prefix --		decrease the size of the length by 1
   Square operator --(int);			// Postfix --			decrease the size of the length by 1

   friend ostream &operator <<(ostream &, const Square &); // Overloaded << operator
    /*Use this operator to display on the screen the value of the length, the area and the perimeter of the square
   */

private:
	double length;
};
#endif