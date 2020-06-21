#include <bits/stdc++.h>
using namespace std;

struct temptemp
{
    int num;
    int id;
} p[100050];

bool cmp(temptemp a, temptemp b)
{
    return a.num < b.num;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            p[i].num = -1;
            p[i].id = i;
        }
        int lg = -1;
        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            int flag = 0;
            while (k--)
            {
                int temp;
                cin >> temp;
                if (p[temp].num == -1 && flag == 0)
                {
                    p[temp].num = i;
                    flag = 1;
                }
            }
            if (flag == 0 && lg == -1)
                lg = i;
        }

        if (lg == -1)
        {
            cout << "OPTIMAL" << endl;
        }
        else
        {
            sort(p + 1, p + 1 + n, cmp);
            cout << "IMPROVE" << endl;
            cout << lg << " " << p[1].id << endl;
        }
    }
    return 0;
}