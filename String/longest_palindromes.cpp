#include<bits/stdc++.h>
using namespace std;

// longest palindromes start at 0
// test: codeforces
const int M = (int)(2e6 + 239);
int pref[M], c;
string longest_palindrome(const string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}


//  Longest Palindromic Substring
// test: leetcode
 string longestPalindrome(string s) {
    long long res = 0, l = 0, n = s.size();

    int pos = 0;
    int len = 1;

    string st = "#";
    for(int i = 0; i < n; i++) {
        st.push_back(s[i]);
        st.push_back('#');
    }

    int m = st.size();
    vector<int> p(m);

    for (int i = 0, l = 0, r = -1; i < m; ++i) {
        int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < m && st[i - k] == st[i + k])
            k++;


        p[i] = --k;
        if(p[i] >= len) {
            pos = i;
            len = p[i];
        }
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    string ans = "";
    for(int i = pos-len; i <= pos+len; i++) {
        if(st[i] != '#') ans.push_back(st[i]);
    }
    return ans;
}
int main() {

}
