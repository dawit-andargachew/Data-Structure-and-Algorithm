#include <iostream>

using namespace std;

int linear_sear(int array[], int key, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (key == array[i])
      return i;
  }
  return -1;
}

int main()
{
  // sample data to check the above searching algorithm
  int sample_data[] = {1, 7, 19, 63, 52, 22, 33, 4, 85};

  int size = sizeof(sample_data) / sizeof(sample_data[0]) - 1;

  int result = linear_sear(sample_data, 4, size);
  if (result != -1)
    cout << "The number is foud at index " + to_string(result) << endl;
  else
    cout << "Sorry, the number is not found there\n";
  return 0;
}