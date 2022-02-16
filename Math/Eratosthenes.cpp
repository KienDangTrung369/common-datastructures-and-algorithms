#include<bits/stdc++.h>
using namespace std;

bool primes[1000001];
int primesCount[1000001];
void seive() {
    memset(primes, true, sizeof(primes));
    primes[0] = false;
    primes[1] = false;
    for(int i=2;i*i<=1000000;i++) {
        if(primes[i]) {
            for(int j=i*i;j<=1000000;j+=i) {
                primes[j] = false;
            }
        }
    }
    primesCount[0] = primesCount[1] = 0;
    for(int i=2;i<=1000000;i++) {
        primesCount[i] = primesCount[i-1]+primes[i];
    }
}

int main() {

}
