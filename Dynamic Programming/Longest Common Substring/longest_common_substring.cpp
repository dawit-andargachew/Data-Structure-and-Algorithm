/* 
Dynamic Programming solution to
find length of the
longest common substring 
*/
#include <iostream>
#include <string.h>
using namespace std;


int common(string one, string two)
{
    int  x = one.length();
    int y= two.length();

    int table[x + 1][y+ 1];
    table[0][0] = 0;
    int result = 0;

    for (int i = 1; i <= one.length(); i++)
    {
        for (int j = 1; j <= two.length(); j++)
        {
            if (one[i - 1] == two[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                result = max(result, table[i][j]);
            }

            else
                table[i][j] = 0;
        }
    }
    return result;
}


int main()
{
    string X = "newsiscomming";

    string Y = "newsisgone.com";

    cout << "Length of Longest Common Substring is "
         << common(X, Y);
    return 0;
}

