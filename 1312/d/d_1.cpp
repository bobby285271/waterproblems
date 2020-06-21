#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;

const long long mod = 998244353;
const long long Max = 1e6 + 10;
long long fact[Max], ifact[Max]; //fact[i]是i的阶乘,ifact[i]是阶乘的除法逆元，两者用于求组合数

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

void init() //初始化
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
        return 0; //不合法
    return (fact[n] * ifact[m] % mod) * ifact[n - m] % mod;
}

int main()
{
    init();
    long long n_, m_;
    cin >> n_ >> m_;
    long long ans_ = 0;
    for (long long i = n_ - 1; i <= m_; i++)
    {
        ans_ += C(i - 1, n_ - 2) % M * (n_ - 2) % M * pow_mod(2, n_ - 3) % M;
    }
    cout << ans_ % M << endl;
    return 0;
}