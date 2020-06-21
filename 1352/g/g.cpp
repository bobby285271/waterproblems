#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << "1" << endl;
            continue;
        }
        if (n == 2 || n == 3)
        {
            cout << "-1" << endl;
            continue;
        }
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n - 4; i += 2)
            {
                cout << i << " ";
            }
            cout << n - 1 << " " << n - 3 << " ";
            for (int i = n; i >= 1; i -= 2)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 1; i <= n; i += 2)
            {
                cout << i << " ";
            }
            cout << n - 3 << " " << n - 1 << " ";
            for (int i = n - 5; i >= 1; i -= 2)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}