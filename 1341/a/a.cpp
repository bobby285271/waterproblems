#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        // cin >> nn;
        // for (ll i = 0; i < n; i++)
        // {
        ll a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        if (((a + b) * n) < c - d || ((a - b) * n) > c + d)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
        // }
    }
    return 0;
}