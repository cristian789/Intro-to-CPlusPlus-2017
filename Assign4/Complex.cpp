//*****************************************************************
// FILE:       ProviderDB.h
// PROGRAMMER: Cristian Aguirre
// LOGON ID:   Z-1824863
// DUE DATE:   10/19/2017
// Assigment:  4
// PURPOSE:  
//             
//*****************************************************************


#include "Complex.h"
#include <iostream>

using std::ostream; using std::istream;
using std::cin;




Complex::Complex(double realNum, double imagNum)		//complex constructor taking real 
						//and imag num to set to NULL/0, Assign the method parameters to the corresponding 
						//data members.
{
	setRealPart(realNum);
	setImaginaryPart(imagNum);
}


void Complex::setComplex(double real, double imag)   //This method takes two double variables as arguments,
										   //representing the real and imaginary parts of a complex number.
{
	realNum = real;      //do something
	imagNum = imag;

};

void Complex::setRealPart(double realpart)
{
	realNum = realpart;

};
void Complex::setImaginaryPart(double imagpart)
{
	imagNum = imagpart;
};

void Complex::getComplex(double& realNum, double& imagNum) const
{
	&realNum;
	&imagNum;
};



double Complex::getRealPart() const
{
	return realNum;      //need to define

}
double Complex::getImaginaryPart() const
{
	return imagNum;     //need to define
};


Complex Complex::operator+(const Complex &rhs)const
{
	Complex result ;    // Declare a temporary object to hold the result and
							   // initialize it with the left operand (lhs)
	result.realNum = (this*realNum + rhs.realNum);
	result.imagNum = (this*imagNum + rhs.imagNum);

	return result;
};

Complex Complex::operator*(const Complex &rhs)const
{
	Complex result;    // Declare a temporary object to hold the result and
					   // initialize it with the left operand (lhs)
	result.realNum = (realNum*rhs.realNum) - (imagNum*rhs.imagNum);
	result.imagNum = (realNum*rhs.realNum) + (imagNum*rhs.realNum);

	return result;
};

bool Complex& Complex::operator==(const Complex &rhs) const
{
	if ((realNum == rhs.realNum) && (imagNum == rhs.imagNum))
		return true;
	else
		return false;
};

ostream &operator<<(ostream&output, const Complex &complexObj) //Print as Complex object as (a,b) with overloaded version
{
	output << '(' << complexObj.realNum << "," << complexObj.imagNum << ')'; //it allows usage as cout<<a<<b<<c
	return output;
};

iostream &operator>>(istream &input, Complex &complexObj)   //Get input from the user.
{
	input.ignore();  //ignore '('
	input >> complexObj.realNum;
	
	input.ignore(); //ignore ','
	
	input >> complexObj.imagNum;
	input.ignore(); //ignore ')
	return input;   //it allows usage as cin>>
};



