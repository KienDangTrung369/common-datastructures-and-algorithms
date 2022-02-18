#include<bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll inf = 1e18;
const int N = 1e6 + 10;
int failure[N];
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
void build_failure_function(string pattern, int m) {
  failure[0] = 0;
  failure[1] = 0; //base case

  for(int i = 2; i <= m; i++) {  //i is length of the prefix we are dealing with
    // j is the index of the largest next partial match
    // (the largest suffix/prefix) of the string under index i - 1
    int j = failure[i - 1];
    while(true) {
      // check if the last character of prefix of length i "expands" the current "candidate"
      if(pattern[j] == pattern[i - 1]) {
        failure[i] = j + 1;
        break;
      }
      // if we cannot "expand" even the empty string
      if(j == 0) {
          failure[i] = 0;
          break;
      }
      // else go to the next best "candidate" partial match
      j = failure[j];
    }
  }
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
