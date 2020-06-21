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
    scanf("%lld\n", &TESTCASE_NUM);
    while (TESTCASE_NUM--)
        solve();
#ifdef _DEBUG
    printf("\033[1m\033[32m\n=> Execution time: %ld ms\033[0m\n\n", clock() - CLOCK_START_TIME);
#endif
    return 0;
}

struct BigInteger
{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    bool sign;
    size_t length;
    vector<int> num;

    BigInteger(long long x = 0) { *this = x; }
    BigInteger(const string &x) { *this = x; }
    BigInteger(const BigInteger &x) { *this = x; }
    void cutLeadingZero()
    {
        while (num.back() == 0 && num.size() != 1)
        {
            num.pop_back();
        }
        int tmp = num.back();
        if (tmp == 0)
        {
            length = 1;
        }
        else
        {
            length = (num.size() - 1) * WIDTH;
            while (tmp > 0)
            {
                length++;
                tmp /= 10;
            }
        }
    }
    BigInteger &operator=(long long x)
    {
        num.clear();
        if (x >= 0)
        {
            sign = true;
        }
        else
        {
            sign = false;
            x = -x;
        }
        do
        {
            num.push_back(x % BASE);
            x /= BASE;
        } while (x > 0);
        cutLeadingZero();
        return *this;
    }
    BigInteger &operator=(const string &str)
    {
        num.clear();
        sign = (str[0] != '-');
        int x, len = (str.size() - 1 - (!sign)) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int End = str.size() - i * WIDTH;
            int start = max((int)(!sign), End - WIDTH);
            sscanf(str.substr(start, End - start).c_str(), "%d", &x);
            num.push_back(x);
        }
        cutLeadingZero();
        return *this;
    }
    BigInteger &operator=(const BigInteger &tmp)
    {
        num = tmp.num;
        sign = tmp.sign;
        length = tmp.length;
        return *this;
    }

    BigInteger abs() const
    {
        BigInteger ans(*this);
        ans.sign = true;
        return ans;
    }

    const BigInteger &operator+() const { return *this; }

    BigInteger operator-() const
    {
        BigInteger ans(*this);
        if (ans != 0)
            ans.sign = !ans.sign;
        return ans;
    }

    BigInteger operator+(const BigInteger &b) const
    {
        if (!b.sign)
        {
            return *this - (-b);
        }
        if (!sign)
        {
            return b - (-*this);
        }
        BigInteger ans;
        ans.num.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= num.size() && i >= b.num.size())
                break;
            int x = g;
            if (i < num.size())
                x += num[i];
            if (i < b.num.size())
                x += b.num[i];
            ans.num.push_back(x % BASE);
            g = x / BASE;
        }
        ans.cutLeadingZero();
        return ans;
    }

    BigInteger operator-(const BigInteger &b) const
    {
        if (!b.sign)
        {
            return *this + (-b);
        }
        if (!sign)
        {
            return -((-*this) + b);
        }
        if (*this < b)
        {
            return -(b - *this);
        }
        BigInteger ans;
        ans.num.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= num.size() && i >= b.num.size())
                break;
            int x = g;
            g = 0;
            if (i < num.size())
                x += num[i];
            if (i < b.num.size())
                x -= b.num[i];
            if (x < 0)
            {
                x += BASE;
                g = -1;
            }
            ans.num.push_back(x);
        }
        ans.cutLeadingZero();
        return ans;
    }

    BigInteger operator*(const BigInteger &b) const
    {
        int lena = num.size(), lenb = b.num.size();
        BigInteger ans;
        for (int i = 0; i < lena + lenb; i++)
            ans.num.push_back(0);
        for (int i = 0, g = 0; i < lena; i++)
        {
            g = 0;
            for (int j = 0; j < lenb; j++)
            {
                long long x = ans.num[i + j];
                x += (long long)num[i] * (long long)b.num[j];
                ans.num[i + j] = x % BASE;
                g = x / BASE;
                ans.num[i + j + 1] += g;
            }
        }
        ans.cutLeadingZero();
        ans.sign = (ans.length == 1 && ans.num[0] == 0) || (sign == b.sign);
        return ans;
    }

    BigInteger e(size_t n) const
    {
        int tmp = n % WIDTH;
        BigInteger ans;
        ans.length = n + 1;
        n /= WIDTH;
        while (ans.num.size() <= n)
            ans.num.push_back(0);
        ans.num[n] = 1;
        while (tmp--)
            ans.num[n] *= 10;
        return ans * (*this);
    }

    BigInteger operator/(const BigInteger &b) const
    {
        BigInteger aa((*this).abs());
        BigInteger bb(b.abs());
        if (aa < bb)
            return 0;
        char *str = new char[aa.length + 1];
        memset(str, 0, sizeof(char) * (aa.length + 1));
        BigInteger tmp;
        int lena = aa.length, lenb = bb.length;
        for (int i = 0; i <= lena - lenb; i++)
        {
            tmp = bb.e(lena - lenb - i);
            while (aa >= tmp)
            {
                str[i]++;
                aa = aa - tmp;
            }
            str[i] += '0';
        }
        BigInteger ans(str);
        delete[] str;
        ans.sign = (ans == 0 || sign == b.sign);
        return ans;
    }

    BigInteger operator%(const BigInteger &b) const
    {
        return *this - *this / b * b;
    }

    BigInteger &operator++()
    {
        *this = *this + 1;
        return *this;
    }

    BigInteger &operator--()
    {
        *this = *this - 1;
        return *this;
    }

    BigInteger &operator+=(const BigInteger &b)
    {
        *this = *this + b;
        return *this;
    }

    BigInteger &operator-=(const BigInteger &b)
    {
        *this = *this - b;
        return *this;
    }

    BigInteger &operator*=(const BigInteger &b)
    {
        *this = *this * b;
        return *this;
    }

    BigInteger &operator/=(const BigInteger &b)
    {
        *this = *this / b;
        return *this;
    }

    BigInteger &operator%=(const BigInteger &b)
    {
        *this = *this % b;
        return *this;
    }

    bool operator<(const BigInteger &b) const
    {
        if (sign != b.sign)
        {
            return !sign;
        }
        else if (!sign && !b.sign)
        {
            return -b < -*this;
        }
        if (num.size() != b.num.size())
            return num.size() < b.num.size();
        for (int i = num.size() - 1; i >= 0; i--)
            if (num[i] != b.num[i])
                return num[i] < b.num[i];
        return false;
    }
    bool operator>(const BigInteger &b) const { return b < *this; }
    bool operator<=(const BigInteger &b) const { return !(b < *this); }
    bool operator>=(const BigInteger &b) const { return !(*this < b); }
    bool operator!=(const BigInteger &b) const { return b < *this || *this < b; }
    bool operator==(const BigInteger &b) const { return !(b < *this) && !(*this < b); }
    bool operator||(const BigInteger &b) const { return *this != 0 || b != 0; }
    bool operator&&(const BigInteger &b) const { return *this != 0 && b != 0; }
    bool operator!() { return (bool)(*this == 0); }

    friend ostream &operator<<(ostream &out, const BigInteger &x)
    {
        if (!x.sign)
            out << '-';
        out << x.num.back();
        for (int i = x.num.size() - 2; i >= 0; i--)
        {
            char buf[10];
            sprintf(buf, "%08d", x.num[i]);
            for (int j = 0; j < strlen(buf); j++)
                out << buf[j];
        }
        return out;
    }
    friend istream &operator>>(istream &in, BigInteger &x)
    {
        string str;
        in >> str;
        size_t len = str.size();
        int start = 0;
        if (str[0] == '-')
            start = 1;
        if (str[start] == '\0')
            return in;
        for (int i = start; i < len; i++)
        {
            if (str[i] < '0' || str[i] > '9')
                return in;
        }
        x.sign = !start;
        x = str.c_str();
        return in;
    }
};

void solve()
{
    BigInteger a, b;
    read(a, b);
    write(min(a, b) + max(b, a), endl);
}