//*****************************************************************
// FILE:       ProviderDB.h
// PROGRAMMER: Cristian Aguirre
// LOGON ID:   Z-1824863
// DUE DATE:   9/26/2017
// Assigment:  3
// PURPOSE:    The ProviderDB class implementation should (eventually) contain definitions for all of the methods 
//             information about a health care provider.
//*****************************************************************

#ifndef PROVIDERDB_H
#define PROVIDERDB_H
#include "Provider.h"
#include <string.h>



class ProviderDB
{
public:
	ProviderDB();                        //default constructor
	ProviderDB(const char*);
	
	void printdb() const;
	

	void sortByProviderNumber();

	void sortBySpecialty();

	void sortByName();
	

	void processTransactions(const char*);

	int searchForProviderNumber(const char*);

private:
	Provider provider_array[40];
	int num_provider = 0;
};

#endif
