#include<bits/stdc++.h>
using namespace std;
long long rd() {
    long long x = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' &&ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void put(long long x) {
    if(x == 0) return;
    if(x < 10) {
        putchar(x + '0');
        return ;
    }
    put(x / 10);
        putchar(x % 10 + '0');
}

struct Point {
    long long x;
    long long y;
    Point(){};
    Point(long long _x, long long _y) : x(_x), y(_y) {};
};
long long operator ^ (const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

struct Pol {
    int n;
    Point p[1005];
    void input(int _n) {
        n = _n;
        for(int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }
    }
    long long get_area() {
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += ((p[i]) ^ (p[(i+1) % n])); //(q.first - p.first) * (q.second + p.second)
        }
        return sum;
    }
};

int main(){
  // freopen("file.in", "r", stdin);
	int n;
	while(~scanf("%d", &n)) {
        Pol poly;
        poly.input(n);

        long long temp = poly.get_area();

        if(temp < 0) temp *= -1;

        if(temp % 2 == 1) {
            put(temp / 2);
            putchar('.');
            putchar('5');
            putchar('0');
        } else {
            put(temp / 2);
            putchar('.');
            putchar('0');
            putchar('0');
        }
        puts("");
	}
}
