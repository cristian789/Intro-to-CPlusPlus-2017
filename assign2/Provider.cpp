#include <iostream>
#include <string>
#include <fstream>
#include "Provider.h"


/*****************************************************************
   Programmer: Cristian Aguirre
   Course:     CSCI  241- 0003
   Semester:   Fall 2017
   Assigment:  2
   Purpose:   The Provider class represents information about a health care Provider.
******************************************************************/




//using namespace std;
using std::cout; using std::endl;



// *****************************************************Provider Constructor*********************

Provider::Provider()
{  idnum[0] = spec[0] = name[0] = hospital[0] = address1[0] = city [0]
    = state [0] = zip [0] = phone [0] = '\0';
}


//*****************************************************Provide print*************************
void Provider::print() const
{ cout  << "#" << idnum << endl
        << name << endl
	<< spec << endl
        << hospital << endl
	<< address1 << endl
	<< city << " "
	<< state << " "
	<< zip << endl
	<< phone << "\n" << endl;
}
// /*
const char* Provider::getProviderNumber() 
{
	return idnum;
}

const char* Provider::getSpecialty()
{
	return spec;
}

const char* Provider::getName()
{
	return name;
}


