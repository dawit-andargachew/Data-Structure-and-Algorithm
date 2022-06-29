#include <bits/stdc++.h>
using namespace std;


void max_activities(int start_time[], int finish_time[], int size)
{
	int i, j;

	cout <<"activities :  "<< endl;
    
	i = 0;
	cout <<" "<< i;

	for (j = 1; j < size; j++)
	{
	if (start_time[j] >= finish_time[i])
	{
		cout <<" " << j;
		i = j;
	}
	}
}


int main()
{
	int start_time[] = {1, 3, 0, 5, 8, 5};
	int finish_time[] = {2, 4, 6, 7, 9, 9};
	int size = sizeof(start_time)/sizeof(start_time[0]);
	max_activities(start_time, finish_time, size);
	return 0;
}

