#include <iostream>
using namespace std;

// Function to sort an array using insertion sort
void insertionSort(int array[], int size)
{
	int key, j;
	for (int i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
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