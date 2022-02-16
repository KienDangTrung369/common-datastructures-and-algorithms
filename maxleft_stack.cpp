#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rd(){
	ll x;
	scanf("%lld",&x);
	return x;
}


int main(){
    freopen("file.in", "r", stdin);
	int n = rd();
	vector<ll> h(n + 1),w(n + 1);
	vector<ll> sum(n + 1);
	vector<int> lpos(n + 1),rpos(n + 1);
	for(int i = 1;i <= n;i++){
		h[i] = rd();
		w[i] = rd();
		sum[i] = sum[i - 1] + w[i];
	}
	stack<int> st;
	for(int i = 1;i <= n;i++){
		while(!st.empty() && h[st.top()] > h[i]) {
			rpos[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) {
		rpos[st.top()] = n + 1;
		st.pop();
	}
	for(int i = n;i >= 1;i--){
		while(!st.empty() && h[st.top()] > h[i]) {
			lpos[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		lpos[st.top()] = 0;
		st.pop();
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		ll W = sum[rpos[i] - 1] - sum[lpos[i]];
		ans = max(ans,W * h[i]);
	}
	for(int i = 1; i <= n; i++) {
        cout << rpos[i] << " ";
	}
	cout << "\n";
	for(int i = 1; i <= n; i++) {
        cout << lpos[i] << " ";
	}
	cout << "\n";
	cout << ans;
}
