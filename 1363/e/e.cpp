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

// upsolved by bobby285271

ll ans = 0; // the total cost
int n, a[MAXN], b[MAXN];
vector<int> g[MAXN]; // the tree

void dfs(int cur, int fa)
{
    int cnt = abs(b[cur]);                  // whether the current node needs change
    for (int i = 0; i < g[cur].size(); i++) // child of cur
    {
        if (g[cur][i] == fa) // the father of node cur has already been visited
            continue;
        // decide where to do the change for the subtree (root g[cur][i]), cur or g[cur][i]
        a[g[cur][i]] = min(a[cur], a[g[cur][i]]);
        dfs(g[cur][i], cur); // begin dfs from node g[cur][i], its father is node cur
        //
        b[cur] += b[g[cur][i]];   // collect status (abs diff of 0->1 and 1->0) from the whole subtree
        cnt += abs(b[g[cur][i]]); // count how many changes need to be done in the subtree
    }
    // do the change for as many pair of (0->1 and 1->0) as possible with cost a[cur]
    // the rest of them (unchanged node which needs change, should only contain 0->1 or 1->0) will be added to the father
    ans += 1LL * (cnt - abs(b[cur])) * a[cur];
}

void solve()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        read(a[i], x, y); // a[i]: cost
        b[i] = x - y;     // need change if b[i] is -1 or 1
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        read(u, v);
        g[u].push_back(v); // store the edges
        g[v].push_back(u);
    }
    dfs(1, 0); // begin dfs from node 1, suppose its father is node 0
    //
    // b[i] should be 0 which means the situation 0->1 equals to 1->0
    write(b[1] ? -1 : ans, endl);
}