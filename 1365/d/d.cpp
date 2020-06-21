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
    scanf("%lld\n", &TESTCASE_NUM);
    while (TESTCASE_NUM--)
        solve();
#ifdef _DEBUG
    printf("\033[1m\033[32m\n=> Execution time: %ld ms\033[0m\n\n", clock() - clock_start_time);
#endif
    return 0;
}

int n, m, vis[60][60];
string a[60];
void dfs(int x, int y)
{
    debug(x, ' ', y, endl);
    if (x < 0 || y < 0 || x >= n || y >= m)
        return;
    if (vis[x][y] == 1 || a[x][y] == '#')
        return;
    vis[x][y] = 1;
    if (x > 0)
        dfs(x - 1, y);
    if (x < n - 1)
        dfs(x + 1, y);
    if (y > 0)
        dfs(x, y - 1);
    if (y < m - 1)
        dfs(x, y + 1);
}

void check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            debug(a[i][j]);
        }
        debug("  |  ");
        for (int j = 0; j < m; j++)
        {
            debug(vis[i][j]);
        }
        debug(endl);
    }
    debug(endl);
}

void solve()
{
    read(n, m);
    for (int i = 0; i < n; i++)
    {
        read(a[i]);
    }
    memset(vis, 0, sizeof(vis));
    queue<pii> b;
    while (!b.empty())
        b.pop();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'B')
            {
                b.push({i, j});
            }
        }
    }
    check();

    while (!b.empty())
    {
        int i = b.front().fir, j = b.front().sec;
        if (j + 1 < m && a[i][j + 1] == '.')
            a[i][j + 1] = '#';
        if (i + 1 < n && a[i + 1][j] == '.')
            a[i + 1][j] = '#';
        if (j > 0 && a[i][j - 1] == '.')
            a[i][j - 1] = '#';
        if (i > 0 && a[i - 1][j] == '.')
            a[i - 1][j] = '#';
        b.pop();
    }
    dfs(n - 1, m - 1);
    check();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'G' && vis[i][j] == 0)
            {
                write("No", endl);
                return;
            }
            if (a[i][j] == 'B' && vis[i][j] == 1)
            {
                write("No", endl);
                return;
            }
        }
    }
    write("Yes", endl);
}