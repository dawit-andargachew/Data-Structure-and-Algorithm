#include <iostream>
using namespace std;

int fibo(int n)
{
    int memo[n + 2];
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++)
        memo[i] = memo[i - 1] + memo[i - 2];
    return memo[n];
}

int main()
{


   // enter a number to find the nth fibocacci
    cout << fibo(9);
    return 0;
}