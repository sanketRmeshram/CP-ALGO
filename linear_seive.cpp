#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define check(x) cout << #x << " : " << (x) << endl
#define all(v) v.begin(),v.end() 
#define allr(v) v.rbegin(),v.rend() 
//#define endl '\n'  
typedef  long long ll; 
typedef  unsigned long long ull; 
typedef vector< ll > edge; 
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll mod=1e9+7;
const ll inf=1e15+10;
const ll N=3e6;

std::vector<ll> pr;
ll lp[N];
void linear_seive(ll n)
{
	memset(lp,0,sizeof(lp));
	for(ll i=2;i<=n ;i++)
	{
		if(lp[i]==0)
		{
			lp[i]=i;
			pr.pb(i);
		}
		for(ll j=0;j<(ll)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n ;j++)
		{
			lp[i*pr[j]]=pr[j];
		}
	}
}

int main()
{
	boost;
	
  	return 0;
}  
