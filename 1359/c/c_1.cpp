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
    clock_t clock_start_time;
    clock_start_time = clock();
#endif
    read(TESTCASE_NUM);
    // while (getchar() != '\n');
    while (TESTCASE_NUM--)
        solve();
#ifdef _DEBUG
    write("\n=> Execution time: ", clock() - clock_start_time, " ms\n\n");
#endif
    return 0;
}

void solve()
{
    double h, c, t;
    read(h, c, t);
    // if (t * 2 == h + c)
    // {
    //     write(2, endl);
    //     return;
    // }
    // else
    // {
    ll a = 1.0 * (c - t) / (h + c - 2 * t);
    a = max(1, a);
    ll ans = 2 * a - 1;
    // write(a, endl);
    double diff = fabs((1.0 * h * a + c * (a - 1)) / (2 * a - 1) - t);
    // write(tem, endl);
    for (int i = max(1, a - 1); i <= a + 1; i++)
    {
        // write(i), endl;
        // write(((1.0 * h * i + c * (i - 1))), endl);
        if (fabs((1.0 * h * i + c * (i - 1)) - t * (2 * i - 1)) < diff * (2 * i - 1))
        {
            diff = fabs(((1.0 * h * i + c * (i - 1)) / (2 * i - 1)) - t);
            // write(diff, endl);
            // write(fabs(1.0 * h * a + c * (a - 1) / (2 * a - 1) - t), endl);
            ans = 2 * i - 1;
        }
    }
    double i = 1;
    if (fabs((1.0 * h * i + c * i) - t * (2 * i)) < diff * (2 * i))
    {
        diff = fabs(((1.0 * h * i + c * (i)) / (2 * i)) - t);
        // write(diff, endl);
        // write(fabs(1.0 * h * a + c * (a - 1) / (2 * a - 1) - t), endl);
        ans = 2 * i;
    }
    // write(ans, endl);
    write(max(1LL, ans), endl);
    // }
}