#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid] & Second subarray is arr[mid+1..end]
void merge(int array[], int left, int mid, int right)
{
    int sub_ArrayOne = mid - left + 1;
    int sub_ArrayTwo = right - mid;

    // Create temp arrays
    int *leftArray = new int[sub_ArrayOne], *rightArray = new int[sub_ArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < sub_ArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sub_ArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOf_SubArrayOne = 0;    // Initial index of first sub-array
    int indexOf_SubArrayTwo = 0;    // Initial index of second sub-array
    int indexOf_MergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOf_SubArrayOne < sub_ArrayOne && indexOf_SubArrayTwo < sub_ArrayTwo)
    {
        if (leftArray[indexOf_SubArrayOne] <= rightArray[indexOf_SubArrayTwo])
        {
            array[indexOf_MergedArray] = leftArray[indexOf_SubArrayOne];
            indexOf_SubArrayOne++;
        }
        else
        {
            array[indexOf_MergedArray] = rightArray[indexOf_SubArrayTwo];
            indexOf_SubArrayTwo++;
        }
        indexOf_MergedArray++;
    }
    // Copy the remaining elements of left[], if there are any
    while (indexOf_SubArrayOne < sub_ArrayOne)
    {
        array[indexOf_MergedArray] = leftArray[indexOf_SubArrayOne];
        indexOf_SubArrayOne++;
        indexOf_MergedArray++;
    }
    // Copy the remaining elements of right[], if there are any
    while (indexOf_SubArrayTwo < sub_ArrayTwo)
    {
        array[indexOf_MergedArray] = rightArray[indexOf_SubArrayTwo];
        indexOf_SubArrayTwo++;
        indexOf_MergedArray++;
    }
}

// begin is for left index and end is right index of the sub-array of arr to be sorted
void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    int sample_array[] = {6, 2, 0, 5, 1, 4, 3};
    int size = sizeof(sample_array) / sizeof(sample_array[0]);

    cout << "Given array is \n";

    // array before sort
    cout << "The array before sort is : \n";
    for (int i : sample_array)
        cout << i << ", ";

    mergeSort(sample_array, 0, size - 1);

    cout << "\nSorted array is \n";
    for (int i : sample_array)
        cout << i << ", ";
    return 0;
}