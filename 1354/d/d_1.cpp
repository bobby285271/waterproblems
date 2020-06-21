#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n, q, cnt[N * 4];
void ins(int k, int l, int r, int x)
{
if (l == r)
{
cnt[k]++;
return;
}
int mid = (l + r) / 2;
if (x <= mid)
ins(k * 2, l, mid, x);
else
ins(k * 2 + 1, mid + 1, r, x);
cnt[k] = cnt[k * 2] + cnt[k * 2 + 1];
return;
}
int del(int k, int l, int r, int rnk)
{
if (l == r)
{
cnt[k]--;
return l;
}
int mid = (l + r) / 2, res;
if (cnt[k * 2] >= rnk)
res = del(k * 2, l, mid, rnk);
else
res = del(k * 2 + 1, mid + 1, r, rnk - cnt[k * 2]);
cnt[k] = cnt[k * 2] + cnt[k * 2 + 1];
return res;
}
int main()
{
scanf("%d%d", &n, &q);
int a;
for (int i = 0; i < n; i++)
{
scanf("%d", &a);
ins(1, 1, n, a);
}
while (q--)
{
scanf("%d", &a);
if (a > 0)
ins(1, 1, n, a);
else
del(1, 1, n, -a);
}
printf("%d\n", cnt[1] ? del(1, 1, n, 1) : 0);
}