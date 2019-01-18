//*****************************************************************
// FILE:       ProviderDB.cpp
// PROGRAMMER: Cristian Aguirre
// LOGON ID:   Z-1824863
// DUE DATE:   9/26/2017
// Assigment:  3
// PURPOSE:   The ProviderDB.cpp should (eventually) search using the binary search algorithm. 
// It should also take a second file with characters to be taken into certain actions like
// all, number, and specialty to be outputed to the certain action. 
//*****************************************************************




#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include "ProviderDB.h"

//using namespace std;
using std::endl; using std::cout;
using std::ifstream; using std::cerr; using std::ios;
using std::cin; using std::string; using std::ws;   using std::cerr;

ProviderDB::ProviderDB()       //constructor setting num_provider to 0
{
	num_provider=0;
}

ProviderDB::ProviderDB(const char*  providerdb)   //alternate constructor taking the providerdb file
{	
	ifstream inFile;

	inFile.open(providerdb, ios::binary);
	if (!inFile)
	{ 
		cerr << "Could not open in file" << endl;
		exit (-1);
	}

	inFile.read((char*) this, sizeof(ProviderDB));
	inFile.close();
}

void ProviderDB::printdb() const       //print header array loop
{
	cout << "Health Care Provider Listing" << endl;

	for (int i = 0; i <num_provider ; i++)
	{
		provider_array[i].print();
		cout << endl;
	}
}	



void ProviderDB::sortByProviderNumber()        // sorting methods....
{
	int i, j;
	Provider providernum;
	for (i = 1; i < num_provider; i++)
	{
		providernum = provider_array[i];

		for (j = i; (j > 0) && (strcmp(provider_array[j - 1].getProviderNumber(), providernum.getProviderNumber()) > 0); j--)
			provider_array[j] = provider_array[j - 1];

		provider_array[j] = providernum;
	}
}



void ProviderDB::sortBySpecialty()
{
	int i, j;
	Provider providernum;
	for (i = 1; i < num_provider; i++)
	{
		providernum = provider_array[i];

		for (j = i; (j > 0) && (strcmp(provider_array[j - 1].getSpecialty(), providernum.getSpecialty()) > 0); j--)
			provider_array[j] = provider_array[j - 1];

		provider_array[j] = providernum;
	}

}


void ProviderDB::sortByName()
{
	int i, j;
	Provider providernum;
	for (i = 1; i < num_provider; i++)
	{
		providernum = provider_array[i];

		for (j = i; (j > 0) && (strcmp(provider_array[j - 1].getName(), providernum.getName()) > 0); j--)
			provider_array[j] = provider_array[j - 1];

		provider_array[j] = providernum;
	}

}


void ProviderDB::processTransactions(const char* trans) //taking the transactions.txt
{
	
	
	
	ifstream inFile;

	inFile.open(trans);
	if (!inFile)
	{
		cerr << "\nCould not open in file" << endl;
		exit(-1);
	}


	/*******************************************ACTIONS**************************************************************/

	string action;
	char providerNumber[7];
	char specialty[41];


	inFile >> action;
	while (inFile)
	{
		if (action == "all")
		{
			cout << "\n Transaction type by all" << endl;
			sortByName();
			printdb();
			cout << endl;
		}

		else if (action == "number")
		{

			inFile >> providerNumber;
			sortByProviderNumber();
			int result = searchForProviderNumber(providerNumber);
			
			if (result == -1)
			{
				cerr << "\nProvider number was not found!" << endl;
			}
			else
			{
				cout << "\nTransaction by number of: " << provider_array[result].getProviderNumber() << endl; 
				provider_array[result].print();
			}
			cout << endl;
		}


		else if (action == "specialty")
		{	
			inFile >> ws;

			inFile.getline(specialty, 41);
			
			cout << "\nTransaction type by the specialty of: " << specialty << endl;
			sortBySpecialty();
			int counter = 0;       //integer for counting the amount of loops of in the seach for specialties. 
			for (int i = 0; i < num_provider; i++)
			{
				if (strcmp(specialty, provider_array[i].getSpecialty()) == 0)
				{
					provider_array[i].print();
					counter += 1;
				}
			}

			cout << "The number of providers with the specialty in " << specialty << " were: " << counter << endl;
		}

		inFile >> action;
	}
	inFile.close();
}


int ProviderDB::searchForProviderNumber(const char* searchNumber)    //seaching for the number inputed 
{
	int low = 0;
	int high = num_provider - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (strcmp(searchNumber, provider_array[mid].getProviderNumber()) == 0)
			return mid;

		if (strcmp(searchNumber, provider_array[mid].getProviderNumber()) < 0)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;

}


