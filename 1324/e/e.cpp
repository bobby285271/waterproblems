#if 0
    clear
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
#define mset multiset
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
    _write("\033[1m\033[31m\33[4m");
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
template <typename T>
inline T lowbit(T x) { return x & (-x); }
template <typename T>
inline bool isprime(T p)
{
    if (p == 2 || p == 3)
        return 1;
    if (p < 2 || (p % 6 != 1 && p % 6 != 5))
        return 0;
    for (T i = 5; i * i <= p; i = i + 6)
        if (p % i == 0 || p % (i + 2) == 0)
            return 0;
    return 1;
}

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
    printf("\033[1m\033[36m\n=> Execution time: %ld ms\033[0m\n\n", clock() - CLOCK_START_TIME);
#endif
    return 0;
}

int dp[2010][2010];

void solve()
{
    int n, h, l, r;
    read(n, h, l, r);
    int sum = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        read(temp);
        sum += temp;
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            if (((sum - j) % h) <= r && ((sum - j) % h) >= l)
            {
                dp[i][j]++;
            }
            if (i == n)
            {
                ans = max(ans, dp[i][j]);
            }
        }
    }
    write(ans, endl);
}