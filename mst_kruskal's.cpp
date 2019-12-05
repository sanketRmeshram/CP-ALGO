//https://www.spoj.com/problems/MST/

/*
	Sort edges as per weight 
	traverse edges if including this edge do not form a cycle include it in mst
	very easy to code
*/


#include <bits/stdc++.h>
using namespace std;
 
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.exceptions(cin.failbit)
 
const int N=1e5+10;
int parent[N];
int find_set(int a)
{
	if(parent[a]==a) return a;
	return parent[a]=find_set(parent[a]);
}
bool uni(int a,int b)
{
	a=find_set(a);
	b=find_set(b);
	if(a==b) return 0;
	if(rand()%2) swap(a,b);
	parent[a]=b;
	return 1;
}
 
int main()
{
	boost;
	int n,m;
	cin>>n>>m;
	std::vector< pair< int , pair <int,int> > > v;
	while(m--)
	{
		int x,y,z;
		cin>>x>>y>>z;
 
		v.push_back(make_pair(z,make_pair(x,y)));
	}
	for(int i=0;i<=n;i++) parent[i]=i;
	sort(v.begin(), v.end());
	long long ans=0;
	for(auto i:v)
	{
		if(uni(i.second.first,i.second.second))
		{
			ans+=i.first;
		}
	}
	cout<<ans;
	return 0;
} 
