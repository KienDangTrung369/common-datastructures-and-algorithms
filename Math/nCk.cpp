#include <bits/stdc++.h>
using namespace std;

const int N = 200043;
const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y) {

    int z = 1;
    while(y) {

        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x) {

    return binpow(x, MOD - 2);
}

int divide(int x, int y) {

    return mul(x, inv(y));
}

int fact[N];

void precalc() {

    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k) {

    return divide(fact[n], mul(fact[k], fact[n - k]));
}

int main() {

    precalc();
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if(n > 2)
        ans = mul(C(m, n - 1), mul(n - 2, binpow(2, n - 3)));
    cout << ans << endl;
}
