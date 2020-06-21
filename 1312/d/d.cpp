#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
const long long Max = 2e5 + 10;
long long fact[Max], ifact[Max];

long long pow_mod(long long n, long long k)
{
    long long res = 1;
    n = n % mod;
    while (k > 0)
    {
        if (k & 1)
            res = res * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = ifact[0] = 1;
    for (long long i = 1; i < Max; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        ifact[i] = pow_mod(fact[i], mod - 2);
    }
}

long long C(long long n, long long m)
{
    if (n < m || m < 0)
        return 0;
    return (fact[n] * ifact[m] % mod) * ifact[n - m] % mod;
}

int main()
{
    init();
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    for (long long i = n - 1; i <= m; i++)
    {
        ans += C(i - 1, n - 2) % mod * (n - 2) % mod * pow_mod(2, n - 3) % mod;
    }
    cout << ans % mod << endl;
    return 0;
}