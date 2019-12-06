#include <bits/stdc++.h>
using namespace std;
 
const int N=1e5 + 10;

const int LOG=17;  // set it to ceil(lg(max_n))+1

int parent[N][LOG+1]; // stores 2^i th  parent in parent[node][i] if no parent stores -1 
int height[N];
vector<int> v[N];
bool visited[N];
void dfs(int node,int h=0,int p=-1)
{
	parent[node][0]=p;
	height[node]=h;
	visited[node]=1;
	for(auto i:v[node])
	{
		if(visited[i]==0) dfs(i,h+1,node);
	}

}

int up_parent(int node,int up) // this returns up-th  parent
{

	/*
		use this templet to compute anything over x to it's some parent
	*/
	if(up==0) return node;
	for(int bit=0;bit<=LOG and (up>>bit);bit++)
	{
		if(up & (1<<bit))
		{
			node=parent[node][bit];
		}
	}
	return node;
}
int lca(int x,int y)
{
	if(height[x]>height[y])
	{
		x=up_parent(x,height[x]-height[y]);
	}
	if(height[y]>height[x])
	{
		y=up_parent(y,height[y]-height[x]);
	}
	if(x==y) return x;
	for(int bit=LOG;bit>=0;bit--)
	{
		if(parent[x][bit]!=parent[y][bit])
		{
			x=parent[x][bit];
			y=parent[y][bit];
		}
	}
	return parent[x][0];
}
void build(int node,int n) // node = root of tree and n = number of elements
{
	memset(visited,0,sizeof(visited));
	memset(parent,-1,sizeof(parent));
	dfs(node);
	for(int bit=1;bit<=LOG;bit++)
	{
		for(int i=0;i<n;i++)
		{
			if(parent[i][bit-1]!=-1)
			{
				parent[i][bit]=parent[parent[i][bit-1]][bit-1];
			}
		}
	}
}

int main()
{

	
	return 0;
}
