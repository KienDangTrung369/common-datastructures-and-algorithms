#include<bits/stdc++.h>
using namespace std;


bool binary_search(vector<int> &a, int x) {
    int left = 0, right = a.size();
    while(left < right) {
        int middle = (left + right) / 2;
        if (a[middle] <= x) {
            left = middle + 1;
        }
        else {
            right = middle;
        }
    }

    if(left > 0 && a[left - 1] == x) return true;
    else return false;
}

int main() {

    return 0;
}
