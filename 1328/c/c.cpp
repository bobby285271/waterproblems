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
        string x;
        cin >> x;
        char a[n + 10], b[n + 10];
        int i = 0;
        for (; i < n; i++)
        {
            if (x[i] == '2')
                a[i] = '1', b[i] = '1';
            else if (x[i] == '0')
                a[i] = '0', b[i] = '0';
            else
            {
                a[i] = '1', b[i] = '0';
                i++;
                for (; i < n; i++)
                {
                    if (x[i] == '2')
                        a[i] = '0', b[i] = '2';
                    else if (x[i] == '0')
                        a[i] = '0', b[i] = '0';
                    else
                        a[i] = '0', b[i] = '1';
                }
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << b[i];
        }
        cout << endl;
    }
    return 0;
}