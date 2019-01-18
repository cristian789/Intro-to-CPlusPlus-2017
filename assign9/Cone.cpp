
#include "Cone.h"
#include <iostream>
#include <string>
#include <cmath>

/****************************************************************
FUNCTION: Cone()
Cone is derived from Circle using public inheritance.
****************************************************************/

Cone::Cone(std::string coneColor, int coneRadius, 
	int coneHeight) : Shape(coneColor)
{

	radius = coneRadius;
	height = coneHeight;


}

/****************************************************************
FUNCTION: get_area()
USE:   This function calculates the area of the cone based
on the values that are stored in the 'height' and 'radius'
variables. It returns a double which is the calculated
area.
ARGUMENTS: None.
****************************************************************/



double Cone::get_area()
{
	double area = 0.0;
	area = (3.14 * radius) * (radius + sqrt(pow(height, 2) + pow(radius, 2)));
		return area;
}

double Cone::get_volume()
{
	double volume = 0.0;
	volume = (3.14 * pow(radius, 2)) * (height / 3);
		return volume;
}



void Cone::print()         // This function first calls the base class 'Shape' for the

color to be printed

{

	Shape::print(); //Prints color

	std::cout << " cone, radius " << radius

		<< ", area " << get_area() << ", height "

		<< height<< ", volume " << get_volume()<< std::endl;

}