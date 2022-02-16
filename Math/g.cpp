#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve() {
    string s;
    int n;
    cin >> s >> n;
    map<int, vector<int>> mp;
    map<int, int> mp2;
    int m = s.length();
    for(int i = 0; i < m; i++) {
        mp[s[i] - 'A'].push_back(i);
        mp[i] = s[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> k >> a >> b;
        map<int, vector<int>> temp;
        for(auto x : mp) {
            vector<int> t = x.second;
            int c = x.first;
            c += k;
            c %= 26;
            mp[c] = t;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    //cin >> tc;
    while(tc--) {
        solve();
        cout << endl;
    }
}
