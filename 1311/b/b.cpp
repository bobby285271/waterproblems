#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n + 5], p[m];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n - i; j++)
            {
                int flag = -1;
                for (int k = 0; k < m; k++)
                {
                    if (p[k] == j)
                    {
                        flag = k;
                        break;
                    }
                }
                if (flag != -1 && a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        int check = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                check = 1;
                break;
            }
        }
        if (check == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}