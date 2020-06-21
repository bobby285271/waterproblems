#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        int t[n + 10];
        int temp = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
            if (i != 0 && t[i] != t[i - 1])
                temp = 0;
        }
        if (temp == 1)
        {
            cout << "1" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "1 ";
            }
            cout << endl;
            continue;
        }
        int ans = 2;
        int a[n + 10];
        a[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (t[i] != t[i - 1])
                a[i] = ((a[i - 1] == 2) ? 1 : 2);
            else
                a[i] = a[i - 1];
        }
        if (t[n - 1] != t[0] && a[n - 1] == a[0])
        {
            int mark = -1;
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i] == a[i + 1])
                {
                    mark = i + 1;
                    break;
                }
            }
            if (mark != -1)
            {
                for (int i = mark; i < n; i++)
                {
                    a[i] = ((a[i] == 2) ? 1 : 2);
                }
            }
            else
            {
                a[n - 1] = 3;
                ans++;
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}