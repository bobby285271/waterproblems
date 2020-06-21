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
        int a[n + 10];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1 && a[0] % 2 != 0)
            cout << "-1" << endl;
        else
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 0)
                {
                    flag = 1;
                    cout << "1" << endl
                         << i + 1 << endl;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "2" << endl
                     << "1 2" << endl;
            }
        }
    }
    return 0;
}