#include <bits/stdc++.h>

using namespace std;

queue<int> check;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int a[4][n + 2];
    // memset(a, 1, sizeof(a));
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            a[i][j] = 1;
        }
        cout << endl;
    }
    while (q--)
    {
        int r, c;
        cin >> r >> c;
        a[r][c] *= -1;
        check.push(c);
        int csize = check.size();
        int flag = 0;


        while (csize--)
        {
            int tocheck = check.front();
            check.pop();
            if (a[2][tocheck] == -1)
            {
                if (a[1][tocheck - 1] == -1 || a[1][tocheck] == -1 || a[1][tocheck + 1] == -1)
                {
                    check.push(tocheck);
                    flag = 1;
                    break;
                }
            }
            if (a[1][tocheck] == -1)
            {
                if (a[2][tocheck - 1] == -1 || a[2][tocheck] == -1 || a[2][tocheck + 1] == -1)
                {
                    check.push(tocheck);
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
