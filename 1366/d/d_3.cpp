#if 0
    g++ -std=c++17 -O2 -Wall -lm "$0" && ./a.out
    exit
#endif
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#define endl '\n'
#define pb push_back
#define fir first
#define sec second
#define umap unordered_map
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;
long long TESTCASE_NUM = 1;
template <typename T>
inline void _read(T &x) { cin >> x; }
inline void _read(int &x) { scanf("%d", &x); }
inline void _read(long long &x) { scanf("%lld", &x); }
inline void _read(float &x) { scanf("%f", &x); }
inline void _read(double &x) { scanf("%lf", &x); }
inline void _read(char &x) { x = getchar(); }
inline void _read(char *x) { scanf("%s", x); }
inline void read() {}
template <typename T, typename... U>
inline void read(T &head, U &... tail)
{
    _read(head);
    read(tail...);
}
template <typename T>
inline void _write(const T &x) { cout << x; }
inline void _write(const int &x) { printf("%d", x); }
inline void _write(const long long &x) { printf("%lld", x); }
inline void _write(const float &x) { printf("%.6f", x); }
inline void _write(const double &x) { printf("%.8lf", x); }
inline void _write(const char &x) { putchar(x); }
inline void _write(const char *x) { printf("%s", x); }
inline void write() {}
template <typename T, typename... U>
inline void write(const T &head, const U &... tail)
{
    _write(head);
    write(tail...);
}
inline void debug() {}
#ifdef _DEBUG
template <typename T, typename... U>
inline void debug(const T &head, const U &... tail)
{
    _write("\033[1m\033[33m\33[4m");
    write(head, tail...);
    _write("\033[0m");
    // system("sleep 1");
}
#else
template <typename T, typename... U>
inline void debug(const T &head, const U &... tail)
{
}
#endif
void solve();
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) { return a < b ? b : a; }
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) { return a < b ? a : b; }

signed main()
{
#ifdef _FILEIO
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
#ifdef _DEBUG
    clock_t CLOCK_START_TIME = clock();
#endif
    // scanf("%lld\n", &TESTCASE_NUM);
    while (TESTCASE_NUM--)
        solve();
#ifdef _DEBUG
    printf("\033[1m\033[32m\n=> Execution time: %ld ms\033[0m\n\n", clock() - CLOCK_START_TIME);
#endif
    return 0;
}

int prime[10000100];

void solve()
{

    for (int i = 2; i < 10000100; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = 1; i * j < 10000100; j++)
                prime[i * j] = i;
        }
    }
    int n;
    read(n);
    pii a[n + 10];
    umap<int, pii> preans;
    for (int i = 0; i < n; i++)
    {
        int temp;
        read(temp);
        // BEGIN data-oriented processing V2
        // See https://codeforces.ml/contest/1366/submission/83490830 for V1
        if (preans.count(temp) != 0)
        {
            a[i] = preans[temp];
            continue;
        }
        // END data-oriented processing V2.0
        int cur = temp;
        vi fac;
        fac.clear();
        while (cur > 1)
        {
            fac.pb(prime[cur]);
            cur /= prime[cur];
        }
        umap<int, int> fac_cnt;
        fac_cnt.clear();
        for (auto j : fac)
        {
            fac_cnt[j]++;
        }
        unique(fac.begin(), fac.end());
        for (auto j : fac)
        {
            for (auto k : fac)
            {
                if (__gcd(j + k, temp) == 1)
                {
                    a[i].fir = j;
                    a[i].sec = k;
                    goto nexti;
                }
            }
        }
        for (auto j : fac)
        {
            int k = pow(j, fac_cnt[j]);
            if (temp / k == 1)
                continue;
            if (__gcd(k + temp / k, temp) == 1)
            {
                a[i].fir = k;
                a[i].sec = temp / k;
                goto nexti;
            }
        }
    nexti:
        if (a[i].fir == 0)
        {
            a[i] = {-1, -1};
        }
        preans[temp] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        write(a[i].fir, ' ');
    }
    write(endl);
    for (int i = 0; i < n; i++)
    {
        write(a[i].sec, ' ');
    }
    write(endl);
}