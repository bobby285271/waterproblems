// To view my solutions (and make hacks) please scroll down to the bottom. Thanks.

// Dasyatis（bobby28527?）的 Codeforces 模板

//万能头：C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

//万能头：C
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

//万能头：C++11 不支持的时候需要删除
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>

#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
using namespace std;

//一些常用的别名
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;
#define endl '\n'
#define pb push_back
#define fir first
#define sec second

//数据组数，如果需要读入反注释 main 函数对应位置
ll TESTCASE_NUM = 1;

//读入函数，参考了 dreamoon 神犇的模板
//一个参数对应一个读入，不吃空格和回车
template <class T>
void _read(T &x)
{
    cin >> x;
}
void _read(int &x) { scanf("%d", &x); }
void _read(ll &x) { scanf("%lld", &x); }
void _read(float &x) { scanf("%f", &x); }
void _read(double &x) { scanf("%lf", &x); }
void _read(char &x) { x = getchar(); }
void _read(char *x) { scanf("%s", x); }
template <class T, class U>
void _read(pair<T, U> &x)
{
    _read(x.first);
    _read(x.second);
}
void read() {}
template <class T, class... U>
void read(T &head, U &... tail)
{
    _read(head);
    read(tail...);
}

//输出函数，参考了 dreamoon 神犇的模板
//一个参数对应一个输出，不是回车后面自动加空格
template <class T>
void _write(const T &x) { cout << x << " "; }
void _write(const int &x) { printf("%d ", x); }
void _write(const ll &x) { printf("%lld ", x); }
void _write(const float &x) { printf("%.6f ", x); }   //保留六位小数
void _write(const double &x) { printf("%.8lf ", x); } //保留八位小数
void _write(const char &x)
{
    putchar(x);
    if (x != '\n')
        putchar(' ');
}
void _write(const char *x) { printf("%s ", x); }
template <class T, class U>
void _write(const pair<T, U> &x)
{
    _write(x.first);
    _write(x.second);
}
template <class T>
void _write(const vector<T> &x)
{
    for (auto i = x.begin(); i != x.end(); _write(*i++))
        ;
}
void write() {}
template <class T, class... U>
void write(const T &head, const U &... tail)
{
    _write(head);
    write(tail...);
}

//快速幂：pow(x, n) % m
inline ll qpow(ll x, ll n, ll m)
{
    ll res = 0;
    while (n)
    {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

//只用 cin 和 cout 的时候使用此函数加速
inline void fastio()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}

//刘汝佳的大数模板
struct BigInteger
{
    static const int BASE = 100000000; //和 WIDTH 保持一致
    static const int WIDTH = 8;        //八位一存储,如修改记得修改输出中的 %08d
    bool sign;                         //符号, 0 表示负数
    size_t length;                     //位数
    vector<int> num;                   //反序存
                                       //构造函数
    BigInteger(long long x = 0) { *this = x; }
    BigInteger(const string &x) { *this = x; }
    BigInteger(const BigInteger &x) { *this = x; }
    //剪掉前导 0，并且求一下数的位数
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
    //赋值运算符
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
        sign = (str[0] != '-'); //设置符号
        int x, len = (str.size() - 1 - (!sign)) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int End = str.size() - i * WIDTH;
            int start = max((int)(!sign), End - WIDTH); //防止越界
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
    //绝对值
    BigInteger abs() const
    {
        BigInteger ans(*this);
        ans.sign = true;
        return ans;
    }
    //正号
    const BigInteger &operator+() const { return *this; }
    //负号
    BigInteger operator-() const
    {
        BigInteger ans(*this);
        if (ans != 0)
            ans.sign = !ans.sign;
        return ans;
    }
    // + 运算符
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
    // - 运算符
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
    // * 运算符
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
    // *10^n 大数除大数中用到
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
    // / 运算符 (大数除大数)
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
    // % 运算符
    BigInteger operator%(const BigInteger &b) const
    {
        return *this - *this / b * b;
    }
    // ++ 运算符
    BigInteger &operator++()
    {
        *this = *this + 1;
        return *this;
    }
    // -- 运算符
    BigInteger &operator--()
    {
        *this = *this - 1;
        return *this;
    }
    // += 运算符
    BigInteger &operator+=(const BigInteger &b)
    {
        *this = *this + b;
        return *this;
    }
    // -= 运算符
    BigInteger &operator-=(const BigInteger &b)
    {
        *this = *this - b;
        return *this;
    }
    // *=运算符
    BigInteger &operator*=(const BigInteger &b)
    {
        *this = *this * b;
        return *this;
    }
    // /= 运算符
    BigInteger &operator/=(const BigInteger &b)
    {
        *this = *this / b;
        return *this;
    }
    // %=运算符
    BigInteger &operator%=(const BigInteger &b)
    {
        *this = *this % b;
        return *this;
    }
    // < 运算符
    bool operator<(const BigInteger &b) const
    {
        if (sign != b.sign) //正负，负正
        {
            return !sign;
        }
        else if (!sign && !b.sign) //负负
        {
            return -b < -*this;
        }
        //正正
        if (num.size() != b.num.size())
            return num.size() < b.num.size();
        for (int i = num.size() - 1; i >= 0; i--)
            if (num[i] != b.num[i])
                return num[i] < b.num[i];
        return false;
    }
    bool operator>(const BigInteger &b) const { return b < *this; }                     // >  运算符
    bool operator<=(const BigInteger &b) const { return !(b < *this); }                 // <= 运算符
    bool operator>=(const BigInteger &b) const { return !(*this < b); }                 // >= 运算符
    bool operator!=(const BigInteger &b) const { return b < *this || *this < b; }       // != 运算符
    bool operator==(const BigInteger &b) const { return !(b < *this) && !(*this < b); } // == 运算符
    // 逻辑运算符
    bool operator||(const BigInteger &b) const { return *this != 0 || b != 0; } // || 运算符
    bool operator&&(const BigInteger &b) const { return *this != 0 && b != 0; } // && 运算符
    bool operator!() { return (bool)(*this == 0); }                             // ！ 运算符

    //重载 << 使得可以直接输出大数
    friend ostream &operator<<(ostream &out, const BigInteger &x)
    {
        if (!x.sign)
            out << '-';
        out << x.num.back();
        for (int i = x.num.size() - 2; i >= 0; i--)
        {
            char buf[10];
            //如 WIDTH 和 BASR 有变化,此处要修改为 %0(WIDTH)d
            sprintf(buf, "%08d", x.num[i]);
            for (int j = 0; j < strlen(buf); j++)
                out << buf[j];
        }
        return out;
    }
    //重载 >> 使得可以直接输入大数
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
    while (TESTCASE_NUM--)
        solve();
#ifdef _DEBUG
    write(endl, "Execution time:", clock() - clock_start_time, "ms", endl, endl);
#endif
    return 0;
}

////////////////////////////////////////////////////////////////
//////////////////////// Solution Below ////////////////////////
////////////////////////////////////////////////////////////////

void solve()
{
    int n;
    read(n);
    while (getchar() != '\n')
        ;
    string a[n + 10];
    for (int i = 0; i < n; i++)
    {
        read(a[i]);
    }
    bool flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '1')
            {
                if (i == n - 1 || j == n - 1 || a[i][j + 1] == '1' || a[i + 1][j] == '1')
                {
                    ;
                }
                else
                {
                    flag = 0;
                }
            }
        }
    }
    write(flag ? "YES" : "NO", endl);
}
