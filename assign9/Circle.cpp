#include "Circle.h"
#include <iostream>
#include <cmath>
#include <string>

/****************************************************************
FUNCTION: Circle()
USE:   This is the default constructor for the Circle class. It
takes the color of a circle and the radius.
ARGUMENTS: 1. string cirColor - This string is sent to the
shape base class for initialization.
2. int cirRadius - This is the radius of the
circle and is stored in the private variable
'radius'.
****************************************************************/


Circle::Circle(std::string cirColor, int cirRadius) : Shape(cirColor)
{
	radius = cirRadius;
}


/****************************************************************
FUNCTION: get_area()
USE:   This function calculates the area of the circle based on
the value stored in 'radius'. It returns a double which
is the calculated area.
ARGUMENTS: None.
****************************************************************/

double Circle::get_area()
{
	double area = 0.0;
	area = (M_PI * pow(radius, 2));
	return area;
}

/****************************************************************
FUNCTION: print()
USE:   This function first calls the base class 'Shape' for the
color to be printed, and then it prints out the circle
radius and area.
ARGUMENTS: None.
****************************************************************/

void Circle::print()
{
	Shape::print();   //Prints color
	std::cout << " circle, radius " << radius
		<< ", area " << get_area() << std::endl;
}