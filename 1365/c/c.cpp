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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;
long long TESTCASE_NUM = 1;
template <class T>
void _read(T &x) { cin >> x; }
void _read(int &x) { scanf("%d", &x); }
void _read(long long &x) { scanf("%lld", &x); }
void _read(float &x) { scanf("%f", &x); }
void _read(double &x) { scanf("%lf", &x); }
void _read(char &x) { x = getchar(); }
void _read(char *x) { scanf("%s", x); }
void read() {}
template <class T, class... U>
void read(T &head, U &... tail)
{
    _read(head);
    read(tail...);
}
template <class T>
void _write(const T &x) { cout << x; }
void _write(const int &x) { printf("%d", x); }
void _write(const long long &x) { printf("%lld", x); }
void _write(const float &x) { printf("%.6f", x); }
void _write(const double &x) { printf("%.8lf", x); }
void _write(const char &x) { putchar(x); }
void _write(const char *x) { printf("%s", x); }
void write() {}
template <class T, class... U>
void write(const T &head, const U &... tail)
{
    _write(head);
    write(tail...);
}
void debug() {}
#ifdef _DEBUG
template <class T, class... U>
void debug(const T &head, const U &... tail)
{
    _write("\033[1m\033[33m");
    write(head, tail...);
    _write("\033[0m");
}
#else
template <class T, class... U>
void debug(const T &head, const U &... tail)
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
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    long clock_start_time = clock();
#endif
    // scanf("%lld\n", &TESTCASE_NUM);
    while (TESTCASE_NUM--)
        solve();
#ifdef _DEBUG
    printf("\033[1m\033[32m\n=> Execution time: %ld ms\033[0m\n\n", clock() - clock_start_time);
#endif
    return 0;
}

int c[2 * MAXN + 10];

bool vis[2 * MAXN + 10];

int n;

void solve()
{

    read(n);
    int a[n + 10], b[2 * n + 10];
    int loc[n + 10];
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        loc[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        read(b[i]);
        b[n + i] = b[i];
        c[i] = loc[b[i]];
        c[n + i] = c[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        c[i] -= i;
        debug(c[i], ' ');
    }
    debug(endl);

    map<int, int> cntcnt;
    for (int i = 1; i <= 2 * n; i++)
    {
        cntcnt[c[i]]++;
    }
    ll ansansansans = 1;
    for (map<int, int>::iterator i = cntcnt.begin(); i != cntcnt.end(); i++)
    {
        ansansansans = max(ansansansans, i->second);
        debug(i->first, ' ', i->second, endl);
    }
    write(ansansansans, endl);
}