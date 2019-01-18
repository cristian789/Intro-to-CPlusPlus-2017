
#ifndef mergesort_h
#define mergesort_h

/*********************************************************************
PROGRAM:    CSCI 241 Assignment 8, Part 3
PROGRAMMER: Cristian Aguirre
LOGON ID:   z1824863
DUE DATE:   due date of assignment

FUNCTION:   merges two sorted subvectors
*********************************************************************/


template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool(*compare)(const T&, const T&))
{

	
	vector<T> temp(high - low + 1);

	int i = low;          // Subscript for start of left sorted subvector
	int j = mid + 1;  // Subscript for start of right sorted subvector
	int k = 0;  // Subscript for start of merged vector

	while (i <= mid && j <= high)
	{
		if (compare(set[j], set[i]))
		{
			temp[k] = set[j];
			j++;
			k++;
		}
		else {

			temp[k] = set[i];
			i++;
			k++;
		}
	}
	// Copy over any remaining elements of left subvector
	while (i <= mid)
	{
		temp[k] = set[i];
		i++;
		k++;//Copy element i of set into element k of temp Add one to i
			//Add one to k
	}
	// Copy over any remaining elements of right subvector
	while (j <= high)
	{
		temp[k] = set[j];
		j++;
		k++;//Copy element j of set into element k of temp Add one to j

	}
	// Copy merged elements back into original vector
	for (i = 0, j = low; j <= high; i++, j++)
		set[j] = temp[i]; // Copy element i of temp into element j of set

}

// This recursive function divides a vector into two subvectors, sorts them, and then merges the two sorted subvectors.
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool(*compare)(const T&, const T&))
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Divide and conquer
		mergeSort(set, low, mid, compare);
		mergeSort(set, mid + 1, high, compare);
		// Combine
		merge(set, low, mid, high, compare);
	}

}

//sort the items in the vector set using the merge sort algorithm

template <class T>
void mergeSort(vector<T>& set, bool(*compare)(const T&, const T&))
{


	mergeSort(set, 0, set.size() - 1, compare);
}


#endif