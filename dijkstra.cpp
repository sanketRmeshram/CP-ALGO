#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define check(x) cout << #x << " : " << (x) << endl
#define all(v) v.begin(),v.end() 
#define endl '\n'  
typedef long long ll; 
typedef unsigned long long ull; 
typedef long double ld;
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <mypair, vector<mypair>, greater<mypair> > min_heap;
const ll mod=1e9+7;
const ll inf=1e16;
const ll N=1e5+10;
 
vector< pair<int,int> > v[N]; //  vertex , weight 
ll dist[N];
int pi[N];
bool final[N];
int n;
void dijkstra(int s)
{
	min_heap curr;
	for(int i=1;i<=n;i++) dist[i]=inf;
	final[s]=1;
	dist[s]=0;
	pi[s]=-1;
	for(int i=1;i<=n;i++) curr.push({dist[i],i});
	int finalized=1;
	while(finalized!=n)
	{
		
		auto a=curr.top();
		curr.pop();
		
		if(a.ff != dist[a.ss]) continue;
		++finalized;
		final[a.ss]=1;
		for(auto &i:v[a.ss])
		{
			if( final[i.ff]==0 and (dist[a.ss]+i.ss)< dist[i.ff])
			{
				pi[i.ff]=a.ss;
				dist[i.ff]=(dist[a.ss]+i.ss);
				curr.push({dist[i.ff],i.ff});
			}
		}
	}
 
}

int main()
{
	return 0;
}
