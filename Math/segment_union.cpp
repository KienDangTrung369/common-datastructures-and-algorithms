#include<bits/stdc++.h>
using namespace std;
double segment_union(vector< pair<double, double>> segs) {
    int n = segs.size();
    vector< pair<double, bool> > x(n*2);
    for(int i = 0; i < n; i++) {
        x[i*2] = make_pair(segs[i].first, false);
        x[i*2+1] = make_pair(segs[i].second, true);
    }
    sort(x.begin(), x.end());

    double res = 0.0;
    double ans = 0.0;
    int c = 0;
    for(int i = 0; i < 2 * n; i++) {
        if (c && i) res += x[i].first - x[i-1].first;
        if (x[i].second) ++c;
        else --c;
        /*
        if(c == 0) {
            ans = max(ans, res);
            res = 0.0;
        }
        */
    }
    return res;
}
int main() {
    vector< pair<double, double>> segs(3);
    for(int i = 0; i < 3; i++) {
        cin >> segs[i].first >> segs[i].second;
    }
    cout << segment_union(segs);
}
