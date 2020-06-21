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

// upsolved by bobby285271

int n, m, n1, n2, n3;
vi g[5100];
bool vis[5100], tp[5100], dp[5100][5100];
int ans[5100];
vi area;
vector<pii> a;

pii dfs(int x, bool type)
{
    tp[x] = type; // store the partition of x
    pii temp = {(type == 0), (type == 1)};
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); i++)
    {
        if (vis[g[x][i]] == 1 && tp[g[x][i]] == type)
            return {-1, -1}; // exit if conflict is met
        if (vis[g[x][i]] == 0)
        {
            pii temptemp = dfs(g[x][i], !type);
            if (temptemp.fir == -1 && temptemp.sec == -1)
                return {-1, -1};
            temp.fir += temptemp.fir;
            temp.sec += temptemp.sec;
        }
    }
    return temp; // return the number of nodes of both partition
}

void dfs2(int x, bool aaa)
{
    if (n2 > 0 && aaa == 0)
        ans[x] = 2; // assign the answer to the node 
    else if (n1 > 0)
        ans[x] = 1, n1--; // when "1" are all used, then we assign "3" to the node
    else
        ans[x] = 3;
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); i++)
    {
        if (vis[g[x][i]] == 0)
        {
            dfs2(g[x][i], !aaa);
        }
    }
}

void solve()
{
    read(n, m, n1, n2, n3);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        read(u, v);
        g[u].pb(v); // store the edges
        g[v].pb(u);
    }

    // check if the given graph is bipartite
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            // store the node where we begin dfs, this node always belongs to partition 0
            area.pb(i);
            pii cnt = dfs(i, 0); // dfs for every connected component
            if (cnt.fir == -1 && cnt.sec == -1)
            {
                // NOT a bipartite
                write("NO", endl);
                return;
            }
            a.pb(cnt); // store the number of nodes of both partition
        }
    }

    // do some checks
    debug(a.size(), endl);
    for (int i = 0; i < a.size(); i++)
    {
        debug(a[i].fir, ' ', a[i].sec, endl);
    }
    
    // dp[i][j] = 1 means after processing ith connected component,
    // it is possible to assign 2 to exactly j nodes
    //
    // dp[i][j] = 0 means it is impossible to do so
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < 5100; j++)
        {
            if (dp[i][j] != 0) // only possible state (dp[i][j]==1) can update further states
            {
                dp[i + 1][j + a[i].fir] = 1;
                dp[i + 1][j + a[i].sec] = 1;
            }
        }
    }
    if (dp[a.size()][n2] == 0)
    {
        write("NO", endl);
        return;
    }
    write("YES", endl);
    memset(vis, 0, sizeof(vis));
    int cur = n2;
    // dp[i][j] should be updated by either dp[i-1][j-a[i-1].fir] or dp[i-1][j-a[i-1].sec]
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (dp[i][cur - a[i].fir] == 1)
        {
            //all nodes in area[i] belongs to partition 0, we assign all nodes in partition 0 with 2
            dfs2(area[i], 0); 
            cur -= a[i].fir;
        }
        else
        {
            //in this case, we assign all nodes in partition 0 with 1 or 3
            dfs2(area[i], 1);
            cur -= a[i].sec;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        write(ans[i]); //output the answer
    }
    write(endl);
    return;
}
