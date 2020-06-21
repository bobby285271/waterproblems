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
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) { return a < b ? b : a; }
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) { return a < b ? a : b; }
void solve();
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
    printf("\n=> Execution time: %ld ms\n\n", clock() - clock_start_time);
#endif
    return 0;
}

int n, k;
vector<int> ans;
vector<int> g[MAXN];

int dfs(int u, int fa, int d)
{
    int sz = 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        if (g[u][i] == fa)
            continue;
        sz += dfs(g[u][i], u, d + 1);
    }
    ans.push_back(d - sz + 1);
    return sz;
}

void solve()
{
    read(n, k);
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    sort(ans.begin(), ans.end());
    ll s = 0;
    for (int i = 1; i <= k; i++)
        s += ans[ans.size() - i];
    write(s, endl);
}