#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (int i = 2; (1 << i) - 1 <= n; i++)
        {
            ll a = (1 << i) - 1;
            if (n % a == 0)
            {
                cout << n / a << endl;
                break;
            }
        }
    }
    return 0;
}