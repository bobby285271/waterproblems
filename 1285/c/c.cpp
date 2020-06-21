#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    for (long long i = sqrt(x) + 1; i >= 1; i--)
    {
        if (x % i != 0)
            continue;
        long long y = x / i;
        if (y / __gcd(y, i) * i == x)
        {
            cout << i << " " << y << endl;
            return 0;
        }
    }
    return 0;
}