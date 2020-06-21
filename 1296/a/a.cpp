#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int temp;
        int one = 0;
        int two = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2 == 0)
                two++;
            else
                one++;
        }
        if (n % 2 == 0 && one == n)
        {
            cout << "NO" << endl;
        }
        else if (two == n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}