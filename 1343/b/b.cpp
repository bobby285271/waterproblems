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
        if (n % 4 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        ll a[n + 2], b[n + 2];
        ll base = n * 8;
        for (int i = 1; i + 1 <= n / 2; i += 2)
        {
            a[i] = base + 2 * i;
            a[i + 1] = base - 2 * i;
            b[i] = a[i] + 1;
            b[i + 1] = a[i + 1] - 1;
        }
        for (int i = 1; i <= n / 2; i++)
        {
            cout << a[i] << " ";
        }
        for (int i = 1; i <= n / 2; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}