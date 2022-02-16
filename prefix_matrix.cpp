#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pref2d(vector<vector<int>> &v, int m, int n) {
    vector<vector<int>> p(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            p[i + 1][j + 1] = v[i][j] + p[i + 1][j] + p[i][j + 1] - p[i][j];
    return p;
}
int sum2d(vector<vector<int>> &p, int c1, int r1, int c2, int r2) {
    return p[c2 + 1][r2 + 1] + p[c1][r1] - p[c1][r2 + 1] - p[c2 + 1][r1];
}

int main() {
    return 0;
}
