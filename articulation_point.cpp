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
#define show(x) for(auto &i:x) cout<<i<<" ";cout<<endl; 
typedef long long ll; 
typedef unsigned long long ull; 
typedef long double ld;
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll mod=998244353;
const ll inf=1e16;
const ll N=1e5+10;

vector<int> v[N];
bool visited[N];
int dis[N],low[N];

int tim=0;
bool is_arti[N];
// remember low of decendent and id of ancestor
void dfs(int node , int parent)
{
	visited[node]=1;
	dis[node]=tim;
	low[node]=tim;
	tim++;
	int child=0;
	for(auto &i:v[node])
	{
		if(i!=parent)
		{
			if(visited[i]==0)
			{
				dfs(i,node);
				low[node]=min(low[node],low[i]);
				if(low[i]>=dis[node] and parent!=-1)
				{
					is_arti[node]=1;
				}
				child++;
			}
			else
			{
				low[node]=min(low[node],dis[i]);
			}
		}
	}
	if(parent==-1 and child>=2) is_arti[node]=1;
}


int main()
{
    boost;
    
    return 0;
} 
