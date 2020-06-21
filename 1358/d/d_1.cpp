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
    // read(TESTCASE_NUM);
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
    ll n, x;
    read(n, x);
    ll a[2 * n + 10];
    ll s[2 * n + 10];
    ll ss[2 * n + 10];
    a[0] = 0, s[0] = 0, ss[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        s[i] = s[i - 1] + (1 + a[i]) * a[i] / 2;
        ss[i] = ss[i - 1] + a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        a[i] = a[i - n];
        s[i] = s[i - 1] + (1 + a[i]) * a[i] / 2;
        ss[i] = ss[i - 1] + a[i];
        // write(s[i], endl);
    }

    ll pl = 2 * n, pr = 2 * n, ans = 0;
    while (pr >= n - 3 && pl >= 0)
    {
        while (ss[pr] - ss[pl] < x)
        {
            pl--;
            // still ok if pl == 0
            if (pl < 0)
            {
                write(ans, endl);
                return;
            }
        }
        // write(pr, endl);
        ll remd = ss[pr] - ss[pl] - x;
        // write(pl + 1, ' ', pr, endl);
        ans = max(ans, s[pr] - s[pl] - ((1 + remd) * remd / 2));
        pr--;
    }
    write(ans, endl);
}
