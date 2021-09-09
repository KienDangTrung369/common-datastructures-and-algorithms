#include<bits/stdc++.h>
using namespace std;

int mod = 998244353;
struct MOD
{
	long long p;
	vector<long long >fact;
	MOD(long long mod,int n)
	{
		this->p = mod;
		fact.resize(n+1);
		fact[0] = 1;
		for(long long i = 1;i<n+1;i++)
		{
			fact[i] = (fact[i-1]*i)%p;
		}
	}
	long long fastpow(long long a,long long b)
	{
		long long res = 1;
		while(b > 0) {
			if(b % 2 != 0) {
				res = (res * a) % p;
			}
			a = (a * a) % p;
			b /= 2;
		}
		return res;
	}
	long long inverse(long long a)
	{
		return fastpow(a,p - 2);
	}
	long long binomial(long long n, long long k)
	{
		long long ans = fact[n];
		ans = (ans*inverse(fact[k]))%p;
		ans = (ans*inverse(fact[n-k]))%p;
		return ans;
	}
	long long multiply(int a,int b)
	{
		return (a*b)%p;
	}
	long long divide(int a, int b)
	{
		return (a*inverse(b))%p;
	}
};

int main() {

}
