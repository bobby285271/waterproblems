#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        if (n % 2 == 0 && k % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (n % 2 != 0 && k % 2 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        long long base = k * k;
        if (n >= base)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}