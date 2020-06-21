#include <bits/stdc++.h>
using namespace std;

long long p[200050];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << (n + n - k + 1) * k / 2 << " ";
    long long flag = -1;
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (p[i] > n - k)
        {
            if (flag == -1)
            {
                flag = i;
            }
            else
            {
                ans = (ans * (i - flag)) % 998244353;
                flag = i;
            }
        }
    }
    cout << ans % 998244353 << endl;
    return 0;
}