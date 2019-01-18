#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
protected:
	std::string color;

public:
	Shape(const std::string&);       //Constructor
									 //Virtual destructor not needed if using the vector
									 //virtual ~Shape() {}            //Virtual destructor

	virtual double get_area() = 0;   //Pure virtual

	virtual void print();            //Virtual



};

#endif //SHAPE_H
