//*****************************************************************
// FILE:       Complex.h
// PROGRAMMER: Cristian Aguirre
// LOGON ID:   Z-1824863
// DUE DATE:   10/19/2017
// Assigment:  4
// PURPOSE:    
//             
//*****************************************************************gma once

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
friend std::ostream &operator<<(std::ostream&, const Complex&);
friend std::istream &operator>>(std::istream&, Complex&);

public:
	Complex(double realNum = 0.0, double imagNum = 0.0);

	void setComplex(double, double);
	void setRealPart(double);
	void setImaginaryPart(double);
	
	void getComplex(double&, double&) const;

	double getRealPart() const;
	double getImaginaryPart() const;

	
	Complex operator+(const Complex& rhs ) const;   //overloads 
	Complex operator*(const Complex& rhs) const;
	
	bool const &operator==(const Complex &)const;


private:
	double realNum;
	double imagNum;




};


#endif

