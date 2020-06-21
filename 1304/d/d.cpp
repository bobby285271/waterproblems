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
        int a[n + 5];
        int b[n + 5];
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
            b[i] = n - i;
        }
        string s;
        cin >> s;
        char p = s[0];
        int cnt = 1;
        int l = 0;
        if (n == 2)
        {
            if (p == '<')
                cout << "1 2" << endl
                     << "1 2" << endl;
            else
                cout << "2 1" << endl
                     << "2 1" << endl;
            continue;
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == p)
                cnt++;
            if (s[i] != p)
            {
                if (p == '>')
                {
                    int fm = a[l + cnt];
                    for (int j = 0; j <= cnt; j++)
                    {
                        // cout << l + j << endl;
                        a[l + j] = fm;
                        fm--;
                    }
                    p = '<';
                    l = i;
                    cnt = 1;
                }
                else
                {
                    int fm = b[l + cnt];
                    for (int j = 0; j <= cnt; j++)
                    {
                        // cout << l + j << endl;
                        b[l + j] = fm;
                        fm++;
                    }
                    p = '>';
                    l = i;
                    cnt = 1;
                }
            }
            if (s[i] == p && i == n - 2)
            {
                if (p == '>')
                {
                    int fm = a[n - 1];
                    for (int j = 0; l + j < n; j++)
                    {
                        // cout << l + j << endl;
                        a[l + j] = fm;
                        fm--;
                    }
                }
                else
                {
                    int fm = b[n - 1];
                    for (int j = 0; l + j < n; j++)
                    {
                        // cout << l + j << endl;
                        b[l + j] = fm;
                        fm++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}