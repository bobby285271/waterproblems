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

void solve()
{
    int n;
    read(n);
    int a[n + 10], b[n + 10];
    a[0] = 0;
    bool vis[n + 10];
    for (int i = 1; i <= n; i++)
        read(a[i]);
    memset(b, -1, sizeof(b));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i - 1])
        {
            b[i] = a[i - 1];
            vis[b[i]] = 1;
        }
    }
    vis[a[n]] = 1;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        while (vis[cur] == 1)
        {
            cur++;
        }
        if (b[i] == -1)
        {
            b[i] = cur;
            vis[cur] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        write(b[i], ' ');
    }
    write(endl);
}