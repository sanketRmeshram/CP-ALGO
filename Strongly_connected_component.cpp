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

vector<int> v[N],tra[N]; // v is original tra is it's transpose
bool visited[N];
vector<int> order;
vector<int> component;
int vectex[N]; // vertex[i] will store the representative element for  scc to which i belong
void dfs(int node)
{
	visited[node]=1;
	for(auto &i:v[node])
	{
		if(visited[i]==0)
		{
			dfs(i);
		}
	}
	order.pb(node);
}

void dfs2(int node)
{
	visited[node]=1;
	for(auto &i:tra[node])
	{
		if(visited[i]==0)
		{
			dfs2(i);
		}
	}
	component.pb(node);
}

void find_scc(int n)
{
	memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++)
    {
    	if(visited[i]==0)
    	{
    		dfs(i);
    	}
    }	
    reverse(all(order));
    int cnt=0;
    memset(visited,0,sizeof(visited));
    for(auto &i:order)
    {
    	if(visited[i]==0)
    	{
    		dfs2(i);
    		for(auto &j:component) vectex[j]=component[0];
    		cnt++;	
    		component.clear();
    	}
    }    
    cout<<cnt<<endl;
}


int main()
{
    boost;


    return 0;
} 
