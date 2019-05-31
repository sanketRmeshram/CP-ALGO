#include <bits/stdc++.h>
using namespace std;
// https://community.topcoder.com/stat?c=problem_statement&pm=10239&rd=14151
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
const ll mod=1000000007;
const ll inf=1e15;
const ll N=1e5+1;
ll y[100];
class 	SuperSum
{
public:
	ll calculate(ll k, ll n);
	
};
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
struct lagran_inter
{
	std::vector<ll> fact,coff;
	ll k;
	lagran_inter(ll n)
	{
		k=n;
		fact.resize(n+1,1);
		for(ll i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
	}
	void build()
	{
		coff.resize(k+1,1);
		ll flag;
		if(k%2) flag=-1;
		else flag=1;
		for(ll i=0;i<=k;i++)
		{
			coff[i]=flag*((inverse(fact[i])*inverse(fact[k-i]))%mod);
			flag*=-1;
		}
	}
	ll get(ll n)
	{
		ll ans=0;
		if(n<=k) return y[n];
		for(ll i=0;i<=k;i++)
		{
			ans=(ans+((inverse(n-i)*y[i])%mod)*coff[i]+mod)%mod;
		}
		for(ll i=0;i<=k;i++)
		{
			ans=(ans*(n-i))%mod;
		}
		return ans;
	}
};
typedef struct lagran_inter lag;
ll SuperSum:: calculate(ll k, ll n)
{
	ll cal[k+1][k+2];
	for(ll i=0;i<k+2;i++) cal[0][i]=i;
	for(ll i=0;i<=k;i++) cal[i][0]=0;
	for(ll i=1;i<=k;i++) for(ll j=1;j<k+2;j++) cal[i][j]=(cal[i][j-1]+cal[i-1][j])%mod;
	for(ll i=0;i<k+2;i++) y[i]=cal[k][i];
	lag poly(k+1);
	poly.build();
	return poly.get(n);
}

int main()
{
	SuperSum c;
	cout<<c.calculate(10,35);
  	return 0;
}
