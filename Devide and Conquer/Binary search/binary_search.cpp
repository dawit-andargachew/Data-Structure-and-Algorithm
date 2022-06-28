#include <iostream>
using namespace std;

//
int binarySearch(int array[], int key, int size)
{
  int first = 0, last = size;
  int mid;
  bool is_found;

  while (first <= last && !is_found)
  {
    mid = (first + last) / 2;
    if (key == array[mid])
      is_found = true;
    else if (key < array[mid])
      last = mid - 1;
    else
      first = mid + 1;
  }

  if (is_found)
    return mid;
  else
    return -1;
}

int main()
{
  // sample data to check the above searching algorithm
  int sample_data[] = {1, 4, 13, 24, 55, 56, 67, 68, 59, 100};
  int size = sizeof(sample_data) / sizeof(sample_data[0]);

  int result = binarySearch(sample_data, 100, size);
  if (result != -1)
    cout << "\nThe value is found at index " + to_string(result) +
                "\n the value it hold is " + to_string(sample_data[result]);
  else
    cout << "the number is not in the list! Sorry\n";
  return 0;
}