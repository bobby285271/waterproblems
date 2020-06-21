#include <bits/stdc++.h>
using namespace std;

long long su[100010];

int main()
{
    su[1] = 1;
    for (int i = 2; i < 100005; i++)
    {
        su[i] = su[i - 1] + (i - 1);
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long l = upper_bound(su + 1, su + 100005, k) - su;
        l--;
        long long ansa = l;
        long long ansb = k - su[l];
        // cout << ansa << " " << ansb << endl;
        for (long long i = n - 1; i >= 0; i--)
        {
            if (i == ansa || i == ansb)
                cout << "b";
            else
                cout << "a";
        }
        cout << endl;
    }

    return 0;
}