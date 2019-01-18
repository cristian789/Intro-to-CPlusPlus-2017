//*****************************************************************
// FILE:       Provider.h
// PROGRAMMER: Cristian Aguirre
// LOGON ID:   Z-1824863
// DUE DATE:   9/26/2017
// Assigment:  3
// PURPOSE:   Declaration for the Provider class, which represents 
//            information about a health care provider.
//*****************************************************************


#ifndef PROVIDER_H
#define PROVIDER_H




//using namespace std;

class Provider
{
public:
	Provider();     			         //Default Constructor
										 //set
	void setIdnum       (char* );
	void setSpec        (char* );
	void setName        (char* );
	void setHospital    (char* ); 
	void setAddress     (char* );
	void setCity        (char* );
	void setState       (char* );
	void setZip         (char* );
	void setPhone       (char* );

	void print() const;


	const char* getProviderNumber();
	const char* getSpecialty();
	const char* getName();
private:
	char idnum[7];
	char spec[41];
	char name[41];
	char hospital[41];
	char address1[31];
	char city[21];
	char state[3];
	char zip[6];
	char phone[15];
};

#endif
