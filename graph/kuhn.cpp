#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) {
        cin >> i;
    }

    g.clear();
    g.resize(n);
    for(int i = 0; i < n; i++) {
        while(a[i]) {
            if(a[i] <= n)
                g[i].push_back(a[i] - 1);
            a[i] >>= 1;
        }
    }

    mt.assign(n, -1);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        used.assign(n, false);
        cnt += try_kuhn(i);
    }

    for(int i : mt) {
        cout << i << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
        cout << endl;
    }
}
