#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<pair<int, int>> values;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        values.assign(2*size, {0, 0});
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x] = {v, 1};
            return ;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m , rx);
        }
        pair<int, int> res;
        if(values[2*x+1].first < values[2*x+2].first) {
            res = values[2*x+1];
        }
        else if(values[2*x+1].first > values[2*x+2].first) {
            res = values[2*x+2];
        }
        else {
            res = {values[2*x+1].first, values[2*x+1].second + values[2*x+2].second};
        }
        values[x] = res;

    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    pair<int, int> calc(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) return {INT_MAX, 0};
        if(lx >= l && rx <= r) return values[x];

        int m = (lx + rx) / 2;

        pair<int, int> value1 = calc(l, r, 2*x+1, lx,  m);
        pair<int, int> value2 = calc(l, r, 2*x+2, m, rx);

        if(value1.first < value2.first) {
            return value1;
        }
        else if(value1.first > value2.first) {
            return value2;
        }
        else {
            return {value1.first, value1.second + value2.second};
        }
    }

    pair<int, int> calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.set(i, x);
    }

    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            pair<int, int> res = st.calc(l, r);
            cout << res.first <<" " << res.second<< "\n";
        }
    }
}
