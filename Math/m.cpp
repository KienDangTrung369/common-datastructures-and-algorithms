#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 1e9 + 7;
vector<int> edges[100005];
int vis[100005];
int cnt = 0;
void dfs(int u) {
    vis[u] = 1;
    cnt++;
    for(int v : edges[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<ll> f(n + 1);
    f[0] = f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] * i) % M;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cnt = 0;
            dfs(i);
            if(cnt > 2) {
                ans = (ans + f[cnt]) % M;
            }
        }

    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
   // cin >> tc;
    while(tc--) {
        solve();
        cout << endl;
    }
}

