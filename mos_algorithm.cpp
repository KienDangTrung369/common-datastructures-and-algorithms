#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
struct node
{
    int l, r, k;
} q[MAXN];
int a[MAXN], pos[MAXN], cnt[MAXN];
long long s, ans[MAXN];
int n, m;
int l = 1, r;
bool cmp(node a, node b)
{
    if (pos[a.l] != pos[b.l])
        return pos[a.l] < pos[b.l];
    return a.r < b.r;
}
void Add(int x)
{
    s += cnt[a[x]] * a[x] * 2 + a[x];
    cnt[a[x]]++;
}
void Del(int x)
{
    s -= cnt[a[x]] * a[x] * 2 - a[x];
    cnt[a[x]]--;
}
int main()
{
    scanf("%d%d", &n, &m);
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pos[i] = i / sz;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].k = i;
    }
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        while (l < q[i].l)
            Del(l++);
        while (l > q[i].l)
            Add(--l);
        while (r < q[i].r)
            Add(++r);
        while (r > q[i].r)
            Del(r--);
        ans[q[i].k] = s;
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
