#include <bits/stdc++.h>
using namespace std;

int a[100020][35];
int b[100020];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        b[i] = temp;
        for (int j = 32; j >= 0; j--)
        {
            a[i][j] = temp % 2;
            temp /= 2;
        }
    }


    int ans;
    for (int j = 0; j < 33; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == 1)
            {
                ans = i;
                cnt++;
            }
        }
        if (cnt == 1)
        {
            cout << b[ans];
            for (int k = 0; k < n; k++)
            {
                if (k != ans)
                {
                    cout << " " << b[k];
                }
            }
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}