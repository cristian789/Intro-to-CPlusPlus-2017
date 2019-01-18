#include "Shape.h"
#include <iostream>
#include <string>

/****************************************************************
FUNCTION: Shape()
USE:   This is the default constructor which initializes the
shapes color.
ARGUMENTS: string& shapeColor - Argument used to initialize
the shapes color.
****************************************************************/

Shape::Shape(const std::string& shapeColor) : color(shapeColor) {}

/****************************************************************
FUNCTION: print()
USE:   This function prints the color stored in the 'color'
string.
ARGUMENTS: None.
****************************************************************/

void Shape::print()
{
	std::cout << color;
}