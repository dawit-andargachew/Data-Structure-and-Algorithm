#include <iostream>
#include <limits.h>
using namespace std;

int rod_cut(int p[], int n)
{
    int memo[n + 1];
    int num;
    memo[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        num = INT_MIN;
        for (int i = 0; i < j; i++)
        {
            num = max(num, p[i] + memo[j - i - 1]);
        }
        memo[j] = num;
    }
    return memo[n];
}

int main()
{
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20};

    cout<<rod_cut(p,5);

    return 0;
}