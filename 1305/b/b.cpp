#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    vector<int> vis[1100];
    int ans = 0;
    while (1)
    {
        ans++;
        int flag2 = 0;
        int p1 = 0;
        int p2 = a.size() - 1;
        while (p1 < a.size() && p2 >= 0)
        {
            int flag = 0;
            while (p1 < a.size())
            {
                if (p1 < a.size() && a[p1] == '(')
                {
                    // cout << p1 <<endl;
                    a[p1] = 'a';
                    flag++;
                    break;
                }
                p1++;
            }
            while (p2 >= 0 && p2 > p1)
            {
                if (p2 >= 0 && a[p2] == ')')
                {
                    // cout << p2 <<endl;
                    a[p2] = 'a';
                    flag++;
                    break;
                }
                p2--;
            }

            if (p2 >= 0 && p1 < a.size() && p1 < p2 && flag == 2)
            {

                flag2 = 1;
                vis[ans].push_back(p1);
                vis[ans].push_back(p2);
                p1++;
                p2--;
                if (p1 >= p2)
                    break;
            }
            else
            {
                break;
            }
        }
        if (flag2 == 0)
            break;
    }
    cout << ans - 1 << endl;

    for (int i = 1; i < ans; i++)
    {
        sort(vis[i].begin(), vis[i].end());
        cout << vis[i].size() << endl;
        for (int j = 0; j < vis[i].size(); j++)
        {
            cout << vis[i][j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
