#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1.5e7 + 1;

bitset<MAX> isPrime;
vector<int> primes;
int spf[MAX];

void sieve() {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < (int)primes.size() && primes[j] <= (MAX - 1) / i; j++) {
            int p = primes[j];
            isPrime[i * p] = 0;
            spf[i * p] = p;
            if (i % primes[j] == 0) break;
        }
    }
}

ll phi(ll a) {
    ll temp = a;
    ll ans = a;
    ll d = 2;
    while(d * d <= temp) {
        ll cnt = 0;
        while(temp % d == 0) {
            temp /= d;
            cnt++;
        }
        if(cnt > 0) ans -= ans / d;
        d++;
    }
    if(temp > 1) ans -= ans / temp;
    return ans;
}

int main() {

}
