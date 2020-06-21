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
        while (1)
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[i] - a[j] == i - j)
                    {
                        swap(a[i], a[j]);
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
                break;
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}