#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int zero = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a % 2 == 0)
                zero++;
            else if (a % 2 != 0)
                one++;
        }
        if (zero && one)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}