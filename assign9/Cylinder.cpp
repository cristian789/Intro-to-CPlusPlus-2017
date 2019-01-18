

#include "Cylinder.h"
#include <iostream>
#include <string>


Cylinder::Cylinder(std::string cylColor, int cylRadius, int cylHeight) : Shape(cylColor)
{
	radius = cylRadius;
	height = cylHeight;
}


/****************************************************************
FUNCTION: get_area()
USE:   This function calculates the area of the cylinder based
on the values that are stored in the 'height' and 'radius'
variables. It returns a double which is the calculated
area.
ARGUMENTS: None.
****************************************************************/

double Cylinder::get_area()

{
	double area = 0.0;
	area = (2 * 3.14 * radius * height) + (2 * 3.14 * height * (radius * radius));
	return area;
}


double Cylinder::get_volume()

{
	double volume = 0.0;
	volume = (3.14 * (radius * radius)) * height;
	return volume;
}



/****************************************************************
FUNCTION: print()
USE:   This function first calls the base class 'Shape' for the
color to be printed, and then it prints out the cylinder
height, radius, area, and volume.
ARGUMENTS: None.
****************************************************************/

void Cylinder::print()
{
	Shape::print(); //Prints color

	std::cout << " cylinder, radius " << radius

		<< ", area " << get_area() << ", height "

		<< height << ", volume" << get_volume() << std::endl;
}