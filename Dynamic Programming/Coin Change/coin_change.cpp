#include <bits/stdc++.h>
using namespace std;

int coins[] = {1,2,3,4,5}; 
int memo [] = {0};
int min_Coins(int N, int M)
{
  for(int i = 0;i<=N;i++)
    memo[i] = INT_MAX;
  
  memo[0] = 0;
  
  for(int i = 1;i<=N;i++)
  {
    for(int j = 0;j<M;j++)
    {
      if(coins[j] <= i)
        memo[i] = min(memo[i], 1 + memo[i - coins[j]]);
    }
  }
  return memo[N];
}

int main() {

  int sum = 50;
  int total_coins = 5;
  cout << min_Coins(sum, total_coins);
}