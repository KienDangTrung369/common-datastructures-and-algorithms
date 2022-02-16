#include<bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll inf = 1e18;

using namespace std;
vector<int> zfunction(const string& s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
int main() {
 // freopen("file.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
  //  cin >> tc;
    while(tc--) {
//        solve();
        cout << "\n";
    }
}
