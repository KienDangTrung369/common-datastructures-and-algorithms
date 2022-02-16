#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;
/*
typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
*/
/*
//ordered set can contain duplicates like a multiset.
//number of elements in set which are smaller than given number --> order_of_key

//index of given number in the set --> find_by_order

*/
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
    int n;
    cin >> n;
    ordered_set<int> pp, nn;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += min(pp.order_of_key(x), nn.order_of_key(-x));
        pp.insert(x);
        nn.insert(-x);
    }
    cout << ans;
}
int main() {

    //https://codeforces.com/contest/1579/problem/E2
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen("file.in", "r", stdin);
    int tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
        cout << "\n";
    }

}
