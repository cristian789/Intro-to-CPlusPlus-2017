#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <string>

class Circle : public Shape
{
protected:

	int radius;

public:

	Circle(std::string, int);
	virtual double get_area();
	virtual void print();

};

#endif //CIRCLE_H
