#include<bits/stdc++.h>
using namespace std;
int parent[1000000];
int size[1000000];
set < int > pres; // present components
void make_set(int v)
{
	parent[v] = v;
	size[v] = 1;
	pres.insert(v);
}
int find_set(int v)
{
	if(v == parent[v])
		return v;
	return  parent[v] = find_set(parent[v]); // path compression
}
void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(size[a] < size[b])
			swap(a, b);
		parent[b] = a; // making the smaller a child of bigger (Union by size)
		size[a] += size[b];
		pres.erase(b);
	}
	/*
	if(a != b)
	{
		if(rank[a] < rank[b])
			swap(a, b);
		parent[b] = a;
		if(rank[a] == rank[b]) // Union by rank
			rank[a]++;
	}
	*/
	// pres.erase(b);
}
int main() {

}


/*
int parent[N];
int sz[N];

int find_set(int v)
{
	if(v == parent[v])
		return v;
	return  parent[v] = find_set(parent[v]);
}
void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(sz[a] < sz[b])
			swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}
*/
