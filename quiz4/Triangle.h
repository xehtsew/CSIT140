#ifndef Triangle_H
#define Triangle_H

using namespace std;
class Triangle;//forward declaration

//some compilers require to prototype the << and >> operator functions
 ostream &operator <<(ostream & someStream, const Triangle & someTriangle); // Overloaded << operator

class Triangle
{
public:
	Triangle();//default value of base = 1 and height = 1;
	Triangle(double base, double height);

	//mutators
	void setBase(double b);//used to set the value of the base
	void setHeigth(double h);//used to set the value of the height

	//Accessors
	double getBase() const;
	double getHeight()const;
	double getArea()const;

	// Overloaded operators
   Triangle operator ++();				// Prefix ++		increase the size of the base by 1 abd height by 1
   Triangle operator ++(int);			// Postfix ++		increase the size of the base by 1 abd height by 1
   Triangle operator --();				// Prefix --		decrease the size of the base by 1 abd height by 1
   Triangle operator --(int);			// Postfix --		decrease the size of the base by 1 abd height by 1

   friend ostream &operator <<(ostream &, const Triangle &); // Overloaded << operator
/*Use this operator to display on the screen the value of the base, the height and the area of the triangle
   */

private:
	double base;
	double height;
};
#endif