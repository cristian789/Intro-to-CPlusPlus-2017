#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "ProviderDB.h"

//using namespace std;
using std::endl; using std::cout;
using std::ifstream; using std::cerr; using std::ios;

ProviderDB::ProviderDB()
{	num_provider=0;
}

ProviderDB::ProviderDB(const char*  providerdb)
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

void ProviderDB::printdb() const
{
	cout << "Health Care Provider Listing" << endl;

	for (int i = 0; i <num_provider ; i++)
	{
		provider_array[i].print();
		cout << endl;
	}
}	



void ProviderDB::sortByProviderNumber()
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

