#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

int n, q, dep[MAXN], par[MAXN], ldf[MAXN], rdf[MAXN], dfc, seq[MAXN];
vector<int> G[MAXN];

int qpow(int b, int e)
{
    int a = 1;
    for (; e; e /= 2, b *= b)
        if (e % 2 == 1)
            a = a * b;
    return a;
}

void dfs(int u, int pa)
{
    dep[u] = dep[par[u] = pa] + 1;
    ldf[u] = ++dfc;
    for (int v : G[u])
        if (v != pa)
            dfs(v, u);
    rdf[u] = dfc;
}

bool cmp(int a, int b)
{
    return dep[a] < dep[b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    while (q--)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> seq[i];
            seq[i] = seq[i] == 1 ? 1 : par[seq[i]];
        }
        sort(seq + 1, seq + k + 1, cmp);
        int flag = 1;
        for (int i = 2; i <= k; i++)
        {
            if (ldf[seq[i]] < ldf[seq[i - 1]] || ldf[seq[i]] > rdf[seq[i - 1]])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}