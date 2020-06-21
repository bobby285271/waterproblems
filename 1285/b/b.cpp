#include <bits/stdc++.h>
using namespace std;
int main()
{
    int number;
    cin >> number;
    while (number--)
    {
        long long n = 0, j = 0, sum = 0, maxx = 0, total = 0;
        cin >> n >> maxx;
        sum = maxx;
        total = maxx;
        int flag = 1, flag2 = 0;
        while (--n)
        {
            cin >> j;
            total += j;
            if (sum <= 0)
            {
                sum = 0;
                flag = -1;
            }
            sum += j;
            if (maxx < sum)
            {
                maxx = sum;
                if (n == 1)
                    flag2 = 1;
            }
        }
        if (maxx < total || (maxx == total && (flag == 1 && flag2 == 1)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}