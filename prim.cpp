//https://www.spoj.com/problems/MST/

#include <bits/stdc++.h>
using namespace std;
 
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.exceptions(cin.failbit)
 
const int inf=1e9+10; // initialize inf > max_cost_of_edge
const int N=1e5+10;
std::vector< pair < int ,int > > v[N]; // vertex,weight
 
int parent[N],val[N]; // sum all elements of val you will get cost of cost of mst
 
void prim(int s,int n)
{
	vector<bool> extracted(n,0);
	for(int i=0;i<n;i++) parent[i]=-1,val[i]=inf;
	set< pair<int,int> > mst;
	val[s]=0;
	for(int i=0;i<n;i++) mst.insert(make_pair(val[i],i));
	while(int(mst.size()))
	{
		auto it=mst.begin();
		int now=it->second;
		mst.erase(it);
		extracted[now]=1;
		for(auto i:v[now])
		{
			int to =i.first;
			if(extracted[to]==0)
			{
				if(i.second < val[to])
				{
					mst.erase(make_pair(val[to],to));
					val[to]=i.second;
					parent[to]=now;
					mst.insert(make_pair(val[to],to));
				}
			}
		}
	}	
 
}
 
int main()
{
	boost;
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int x,y,w;
		cin>>x>>y>>w;
		x--;y--;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	prim(0,n);
	long long ans=0;
	for(int i=0;i<n;i++) ans+=val[i];
	cout<<ans;
 
	return 0;
} 
