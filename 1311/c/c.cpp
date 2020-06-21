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
        string s;
        cin >> s;
        vector<int> cnt[30];
        int ans[30];
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < 26; i++)
        {
            cnt[i].clear();
        }
        int l = s.size();

        for (int i = 0; i < l; i++)
        {
            cnt[s[i] - 'a'].push_back(i + 1);
        }
        for (int i = 0; i < 26; i++)
        {
            cnt[i].push_back(l + 1);
        }
        for (int i = 0; i < m; i++)
        {
            int p;
            cin >> p;
            for (int j = 0; j < 26; j++)
            {
                int loc = upper_bound(cnt[j].begin(), cnt[j].end(), p) - cnt[j].begin();
                ans[j] += loc;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            ans[i] += cnt[i].size() - 1;
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}