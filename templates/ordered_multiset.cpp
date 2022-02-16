#include<bits/stdc++.h>
using namespace std;

/*
If you do not sacrifice for what you want, What you want becomes the sacrifice.
1-Brute Force (complete search)(bitmask)(Number theory)
2-greedy sorting two pointer
3-Binary Search
4-dp
5-prefix sum
6-graph,bit manipulation(dependency)
7-segment tree (fenwick tree)

1-try going backward if given find A to B ,you find B to A
2-try out small test cases or do brute force solutions to find pattern
3-dont get stuck on only one approach
4-if given find substring ,go for hashing , prefix sum ,bit mask techniques
5-calculate contributtion of each element towards our answer
6-graph=tree + back edges (edges that connect to current node's ancestors)
7-insert duplicate values in set like pair<int,int> = <value, -index>
8-in multi source bfs think in reverse direction
9-bigger length can be divided into length of 2 and 3

dp patterns
1-dp[i] ->answer ending at i or using first i elements what is the answer
2-dp[i][j] -> using first i elements if current weight is j what is the answer
  here u can include ith element or not
3-unbounded knapsack,can include current element again or move to next element
4-dp(i,j) -> using first i and j elements of X and Y what is the answer (LCS)
5-for base case think if there is only one element or no element at all
6-to do an iterative version of recursive dp start iterating from back
*/

// ordered_multiset
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// NOTE
// find_by_order and order_of_key work the same as for a set.
// However for searching, lower_bound and upper_bound work oppositely. Also, let's say you want to erase x, use s.erase(s.upper_bound(x)) (as upper bound is considered as lower bound)

 int main() {

 }


