#include <iostream>
using namespace std;

// Function used to swap two numbers
void swapper(int *value_1, int *value_2)
{
    int temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}

// Function to sort an array using simple sort
int *simple_sort(int array[], int size)
{
    int temp;
    for (int i = 0; i <= size - 2; i++)
    {
        for (int j = i + 1; j <= size - 1; j++)
        {
            if (array[i] > array[j])
                swapper(&array[i], &array[j]);
        }
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

    int *sorted_array = simple_sort(sample_array, size);

    // array after sort
    cout << "\nSorted array is : \n";
    for (int i = 0; i < size; i++)
        cout << sorted_array[i] << ", ";

    return 0;
}