/* Programmer: Cristian Aguirre
   Course:     CSCI  241- 0003
   Semester:   Fall 2017
   Assigment:  1
*********************************************************/



#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;


class Provider
{
	public:
                Provider();     			         //Default Constructor
								//set
		void setIdnum    (char* alpha) {strcpy (idnum, alpha);  }
		void setSpec     (char* alpha) {strcpy (spec, alpha);   }
		void setName     (char* alpha) {strcpy (name, alpha);   }
		void setHospital (char* alpha) {strcpy (hospital, alpha);}
		void setAddress  (char* alpha) {strcpy (address1, alpha); }
		void setCity     (char* alpha) {strcpy (city, alpha); }
		void setState    (char* alpha) {strcpy (state, alpha); }
		void setZip      (char* alpha) {strcpy (zip, alpha); }
		void setPhone    (char* alpha) {strcpy (phone, alpha); }

		void print();

	private:
		char idnum[7];
		char spec[41];
		char name[41];
		char hospital[41];
		char address1[31];
		char city[21];
		char state[3];
		char zip[6];
		char phone [15];
};

// *****************************************************Provider Constructor*********************

Provider::Provider ()
{  idnum[0] = spec[0] = name[0] = hospital[0] = address1[0] = city [0]
    = state [0] = zip [0] = phone [0] = '\0';
}


//*****************************************************Provide print*************************
void Provider::print()
{ cout  << "#" << idnum << endl
        << name << endl
	<< spec << endl
        << hospital << endl
	<< address1 << endl
	<< city << endl
	<< state << endl
	<< zip << endl
	<< phone << "\n" << endl;
}


//****************************************************main *********************************
int main ()
{	 ifstream inFile;
	inFile.open("providers.csv");
	if (inFile.fail())
	{ cerr << "Could not open in file" << endl;
	 exit (-1);
	}

	Provider array[40];
	unsigned char index = 0;
	const char* a_ptr;
	char ptr [256];
	char* token;
	char fullname [41];
	string str;


        getline(inFile, str);              //getline
        while (!inFile.eof())
  {	a_ptr = str.c_str();                  //would this work ???
	strcpy (ptr,a_ptr);

//*************************************************************************Tokenizing***

	token = strtok(ptr, ",");
	array[index].setIdnum (token);

	token = strtok(NULL, ",");
	array[index].setSpec(token);


	token = strtok(NULL, ",");
	strcpy(fullname, token);

	token = strtok (NULL,",");
	strcat(fullname, ",");
	strcat(fullname, token);

	token = strtok(NULL, ",");
	if (token[1] == '.')  //middle name exist
	{ strcat (fullname, ",");
	  strcat (fullname, token);
	  token = strtok(NULL, ",");
	}

		//else
	strcat (fullname, "," );
	strcat (fullname, token);
	array[index].setName(fullname);

	token = strtok(NULL, ",");
	array[index].setHospital(token);

	token = strtok(NULL, ",");
	array[index].setAddress(token);

	token = strtok(NULL, ",");
	array[index].setCity(token);

	token = strtok(NULL, ",");
	array[index].setState(token);

	token = strtok(NULL, ",");
	array[index].setZip(token);

	token  =strtok(NULL, ",");
	array[index].setPhone(token);
	// ********************************end of provider**************

	index++;
	getline (inFile, str);
	}
	inFile.close();					//close of csv

	cout << "There are " << int (index) << "Providers recorded." << endl;
	for (unsigned char i = 0; i < index; i++)
		array[i].print();

	return 0;
}


