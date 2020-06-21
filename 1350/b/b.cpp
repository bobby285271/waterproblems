#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        ll s[n + 10];
        ll dp[n + 10];
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &s[i]);
            dp[i] = 1;
        }
        ll ans = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    if (s[i] > s[j])
                        dp[i] = max(dp[i], dp[j] + 1);
                    if (j != 1 && s[i] > s[i / j])
                        dp[i] = max(dp[i], dp[i / j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }
}