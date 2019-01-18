/*********************************************************************
PROGRAM:    CSCI 241 Assignmeny 9
PROGRAMMER: Cristian Aguirre
LOGON ID:   Z-1824863
DUE DATE:   12/5/2017, Extra Credit

FUNCTION:   This short assignment covers inheritance and polymorphism.
a series of classes to represent some simple geometric shapes and
a small program to test your classes.
*********************************************************************/

#include "Shape.h"
#include "Circle.h"
#include "Cylinder.h"
#include "Cone.h"

#include <iostream>
#include <vector>

int main(void)

{

	//Create vector shape with an initial size of 6

	std::vector <Shape *> shape(6);

	//Initialize vector with Shapes

	shape.push_back(new Circle("green", 10));

	shape.push_back(new Cone("yellow", 4, 6));

	shape.push_back(new Cylinder("blue", 8, 6));

	shape.push_back(new Cone("purple", 9, 7));

	shape.push_back(new Cylinder("red", 3,7));

	shape.push_back(new Circle("oranger", 5));

	std::cout << std::endl << "Printing all shapes..."

		<< std::endl << std::endl;

	//Process each element in vector 'shape'

	//'unsigned int' due to comparison warning

	for (unsigned int i = 0; i < shape.size(); ++i)
	{
		Shape *shapePtr = dynamic_cast<Shape *> (shape[i]);

		if (shapePtr != 0)

			shapePtr->print();
	}

	std::cout << std::endl << "Printing only Triangles..."

		<< std::endl << std::endl;

	//'unsigned int' due to comparison warning


	for (unsigned int i = 0; i < shape.size(); ++i)
	{
		Cylinder *cylinderPtr = dynamic_cast<Cylinder *> (shape[i]);
		
		if (cylinderPtr != 0)

			cylinderPtr->print();
	}

	std::cout << std::endl;
	return 0;

}