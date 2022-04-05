#include <iostream>
using namespace std;

// Function to sort an array using insertion sort
void insertionSort(int array[], int size)
{
	int key, j;
	for (int i = 1; i < size; i++) // sorted = ar[0]       unsoted = ar[ 1 to size-1 ]
	{
		key = array[i]; // current index 6
		j = i - 1;		// index i -1 or previous 7

		while (j >= 0 && array[j] > key) // only j can handle the index
		{
			array[j + 1] = array[j]; // arr[i] = 7
			j = j - 1;				 // j = i -2
		}
		array[j + 1] = key; // for while loop does previous j is decreased by 1 and adding one give j    [  Not-while loop -> doesn't change its value  ]
	}
}

int main()
{
	// sample data to check the algorithm
	int sample_array[] = {2, 11, 25, 3, 44, 4, 4, 0, -33, 7, 1};
	int size = sizeof(sample_array) / sizeof(sample_array[0]);

	// array before sort
	cout << "Given array is \n";
	for (int i : sample_array)
		cout << i << ", ";

	insertionSort(sample_array, size);

	// array after sort
	cout << "\nSorted array is : \n";
	for (int i : sample_array)
		cout << i << ", ";

	return 0;
}