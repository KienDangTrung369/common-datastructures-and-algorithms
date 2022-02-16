#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX = 1e6 + 10;
const int N = 1e5 + 10;
vector<int> edges[N];

int shortest_cycles(int n) {
    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        vector<int> dist(n, INF);
        vector<int> parent(n, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(int child : edges[v]) {
                if(dist[child] == INF) {
                    dist[child] = dist[v] + 1;
                    parent[child] = v;
                    q.push(child);
                } else if(parent[v] != child && parent[child] != v) {
                    ans = min(ans, dist[v] + dist[child] + 1);
                }
            }
        }
    }
    ans = (ans == INF ? -1 : ans);
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a;
    for(int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        if(val > 0) a.push_back(val);
    }

    vector<int> bits(61);
    for(int i = 0; i < a.size(); i++) {
        for(int bit = 0; bit <= 60; bit++) {
            if((a[i] >> bit) & 1) {
                bits[bit]++;
                if(bits[bit] >= 3) {
                    cout << 3;
                    return;
                }
            }
        }
    }

    for(int i = 0; i < a.size(); i++) {
        for(int j = i + 1; j < a.size(); j++) {
            if(a[i] & a[j]) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    int ans = shortest_cycles((int)a.size());
    cout << ans;
 }

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
   // cin >> tc;
    while(tc--) {
        solve();
        cout << endl;
    }
}

