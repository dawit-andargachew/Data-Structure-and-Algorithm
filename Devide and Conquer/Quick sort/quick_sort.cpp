#include <iostream>
using namespace std;

// Function used to swap two numbers
void swapper(int *value_1, int *value_2)
{
    int temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}

// function that consider last element as pivot, place the pivot at its exact position, and place
// smaller elements to left of pivot and greater elements to right of pivot.
int partition(int a[], int start, int end) // qucik sort for with normal code
{
    int pivot = a[end]; // pivot element
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        // If current element is smaller than the pivot
        if (a[j] < pivot)
        {
            i++;
            swapper(&a[i], &a[j]);
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;
    return (i + 1);
}

// function to implement quick sort with recurssion
void quick_sort(int array[], int start, int end)
{
    if (start < end)
    {
        int partitioning_index = partition(array, start, end);
        quick_sort(array, start, partitioning_index - 1);
        quick_sort(array, partitioning_index + 1, end);
    }
}

/* function to print an array */
void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
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

    quick_sort(sample_array, 0, size - 1);

    // array after sort
    cout << "\nSorted array is : \n";
    for (int i : sample_array)
        cout << i << ", ";

    return 0;
}