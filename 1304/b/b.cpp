#include <bits/stdc++.h>
using namespace std;

int sol[200];

int main()
{
    int n, m;
    cin >> n >> m;
    string a[n];
    string ans[n];
    // "lowercase Latin letters only."
    for (int i = 0; i < n; i++)
    {
        ans[i] = "!!";
        cin >> a[i];
    }
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (a[i] == "!" || a[j] == "!")
                continue;
            int flag = 0;
            for (int k = 0; k < m; k++)
            {
                if (a[i][k] != a[j][m - 1 - k])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                ans[p] = a[i];
                ans[n - 1 - p] = a[j];
                a[i] = "!";
                a[j] = "!";
                p++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == "!")
            continue;
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != a[i][m - 1 - j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && (ans[p] == "!!" || ans[p].size() < a[i].size()))
        {
            ans[p] = a[i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] != "!!")
            cnt += ans[i].size();
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] != "!!")
            cout << ans[i];
    }
    cout << endl;
    return 0;
}