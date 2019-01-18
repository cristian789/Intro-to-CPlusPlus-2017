/******************************************************
   Programmer: Cristian Aguirre
   Course:     CSCI  241- 0003
   Semester:   Fall 2017
   Assigment:  3

   Function:   Main Program 
*********************************************************/



#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "Provider.h"
#include "ProviderDB.h"


using std::cout; using std:: endl;


//****************************************************main *********************************/
int main ()
{	

	
	ProviderDB obj1("providerdb");
	
	obj1.processTransactions("transactions.txt");


	/*
	obj1.sortByProviderNumber();
	obj1.printdb();

	obj1.sortBySpecialty();
	obj1.printdb();
	
	obj1.sortByName();
	obj1.printdb();
*/

	return 0;
}


