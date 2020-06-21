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
    scanf("%lld\n", &TESTCASE_NUM);
    while (TESTCASE_NUM--)
        solve();
#ifdef _DEBUG
    printf("\n=> Execution time: %ld ms\n\n", clock() - clock_start_time);
#endif
    return 0;
}

bool vis[26];
set<int> g[26];
string ans;

void dfs(int a)
{
    vis[a] = 1;
    ans += a + 'a';
    for (set<int>::iterator i = g[a].begin(); i != g[a].end(); i++)
    {
        if (!vis[*i])
            dfs(*i);
    }
}

void solve()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 26; i++)
    {
        g[i].clear();
    }
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    {
        g[s[i] - 'a'].insert(s[i - 1] - 'a');
        g[s[i - 1] - 'a'].insert(s[i] - 'a');
    }
    for (int i = 0; i < 26; i++)
    {
        if (g[i].size() > 2)
        {
            write("NO", endl);
            return;
        }
    }
    ans = "";
    for (int i = 0; i < 26; i++)
    {
        if (!vis[i] && g[i].size() < 2)
        {
            dfs(i);
        }
    }
    if (ans.size() < 26)
        write("NO", endl);
    else
        write("YES", endl, ans, endl);
}