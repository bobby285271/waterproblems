#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int i = 0, j = n - 1;
        int flag = 0;
        while (1)
        {
            if (a[i] < i || a[j] < i)
            {
                flag = 1;
                break;
            }
            if (j - i == 1)
            {
                if (a[i] == a[j] && a[i] == i)
                {
                    flag = 1;
                }
                break;
            }
            if (i == j)
            {
                break;
            }
            i++;
            j--;
        }
        if (flag == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}