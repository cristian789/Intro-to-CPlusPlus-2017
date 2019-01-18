#ifndef Cone_H
#define Cone_H

#include "Shape.h"
#include <string>

class Cone : public Shape
{
protected:
	int height;
	int radius;

public:
	Cone(std::string, int, int);

	virtual double get_area();
	virtual double get_volume();

	virtual void print();

};

#endif //CONE_H
