#include <iostream>
using namespace std;

// Function used to swap two numbers
void swapper(int *value_1, int *value_2)
{
    int temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}

void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

void she_sort(int *arr, int n)
{
    int gap, j, k;
    for (gap = n / 2; gap > 0; gap = gap / 2)
    { // initially gap = n/2,  decreasing by gap /2
        for (j = gap; j < n; j++)
        {
            for (k = j - gap; k >= 0; k = k - gap)
            {
                if (arr[k + gap] >= arr[k])
                    break;
                else
                    swapper(&arr[k + gap], &arr[k]);
            }
        }
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

    shellSort(sample_array, size);

    // array after sort
    cout << "\nSorted array is : \n";
    for (int i : sample_array)
        cout << i << ", ";

    return 0;
}