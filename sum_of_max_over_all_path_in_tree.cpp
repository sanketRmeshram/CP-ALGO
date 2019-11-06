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
#define show(a) for(auto i:a) cout<<i<<" ";cout<<endl
typedef long long ll; 
typedef unsigned long long ull; 
typedef long double ld;
typedef pair< int , int > mypair;
typedef priority_queue <int> max_heap;
typedef priority_queue <mypair, vector<mypair>, greater<mypair> > min_heap;
const ll mod=1000000007;
const ll inf=1e9;
const ll N=1e6+10;
int a[N];
vector<int> v[N];
int parent[N];
int size[N];
bool visited[N];
int find_set(int node)
{
	if(node==parent[node]) return node;
	return parent[node]=find_set(parent[node]); 
}
void uni(int a,int b)
{
	a=find_set(a);
	b=find_set(b);
	if(a==b) return;
	if(rand()%2) swap(a,b);
	parent[b]=a;
	size[a]+=size[b];
}

ll sum_of_maxima(int n) // this will calculate sumation of max_element for each pair of verstex
{
	for(int i=0;i<n;i++) size[i]=1,parent[i]=i,visited[i]=0;
	vector<pair<int,int> > order;
	for(int i=0;i<n;i++) order.pb(mp(a[i],i));
	sort(all(order));
	ll ans=0;
	for(auto i:order)
	{
		int node=i.ss;
		ll sum=0,sum_sq=0;
		for(auto j:v[node])
		{
			if(visited[j]==1 )
			{
				sum+=size[find_set(j)];
				sum_sq+=1ll*size[find_set(j)]*size[find_set(j)];

			}
		}
		ans+=1ll*a[node]*(sum+1);
		ans+=1ll*a[node]*((sum*sum-sum_sq)/2);
		for(auto j:v[node] )
		{
			if(visited[j]==1 )
			{
				uni(j,node);
			}
		}
		visited[node]=1;
	}	
	return ans;
}
int main()
{
    boost;
    //https://codeforces.com/contest/915/problem/F
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<(n-1);i++)
    {
    	int x,y;
    	cin>>x>>y;
    	x--;y--;
    	v[x].pb(y);
    	v[y].pb(x);

    }	
    ll ans=sum_of_maxima(n);

    return 0;
}
