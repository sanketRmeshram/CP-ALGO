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
const ll N=1e6+10;

ll mod_expo(ll a,ll b, ll c)
{
	ll ans=1;
	while(b)
	{
		if(b & (ll)1) ans=(ans*a)%c;
		a=(a*a)%c;
		b=b>>1;
	}
	return ans;
}
ll inverse(ll n)
{
	return mod_expo(n,mod-2,mod);
}


int main()
{
	boost;

  	return 0;
}  
