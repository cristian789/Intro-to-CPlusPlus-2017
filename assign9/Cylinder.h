#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"
#include <string>

class Cylinder : public Shape
{
protected:
	int height;
	int radius;
public:
	Cylinder(std::string, int, int);
	virtual double get_area();
	virtual double get_volume();    

	virtual void print();
};

#endif //CYLINDER_H