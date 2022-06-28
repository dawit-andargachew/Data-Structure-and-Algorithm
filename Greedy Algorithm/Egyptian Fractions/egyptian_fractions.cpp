#include <bits/stdc++.h>
using namespace std;
void egyptianFraction( int n,  int d)
{

    if (d == 0 || n == 0) // case zero
    return;

    if (d % n == 0) // case one
    {
        cout << "1/" << d / n;
        return;
    }
    if (n % d == 0) // case two
    {
        cout << n / d;
        return;
    }

// focus here and do it
    if (n > d)
    {
        cout << n / d << " + ";
        egyptianFraction(n % d, d);
        return;
    }

// last case
     int x = d / n + 1;
    cout << "1/" << x << " + ";
    egyptianFraction(n * x - d, d * x);

}
int main()
{
    int n, d;
    // 6/4
    n = 6;
    d = 14;
    cout << "Egyptian Fraction representation of " << n << "/" << d << " is" << endl;
    egyptianFraction(n, d);
    return 0;
}