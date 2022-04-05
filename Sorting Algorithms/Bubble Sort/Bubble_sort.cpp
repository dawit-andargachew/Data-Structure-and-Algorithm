#include <iostream>
using namespace std;

// Function used to swap two numbers
void swapper(int *value_1, int *value_2)
{
  int temp = *value_1;
  *value_1 = *value_2;
  *value_2 = temp;
}

// Function to sort an array using bubble sort
int *bubble_sort(int array[], int size)
{
  for (int i = size - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
    {
      if (array[j] > array[j + 1])
        swapper(&array[j], &array[j + 1]); // swap array[j] with array[j+1]
    }
  return array;
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

  int *sorted_array = bubble_sort(sample_array, size);

  // array after sort
  cout << "\nSorted array is : \n";
  for (int i = 0; i < size; i++)
    cout << sorted_array[i] << ", ";

  return 0;
}