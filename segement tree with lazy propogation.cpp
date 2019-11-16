#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define check(x) cout << #x << " : " << (x) << endl
#define inf 1e15
#define all(v) v.begin(),v.end() 
#define allr(v) v.rbegin(),v.rend() 
//#define endl '\n'  
#define mod 1000000007
typedef  long long ll; 
typedef  unsigned long long ull; 
//using u64 = uint64_t; 
//using u128 = __uint128_t;
typedef vector< ll > edge; 
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll N=1e5+10;
ll n,a[N];
struct segment_tree
{
	ll t[4*N],lazy[4*N];
	segment_tree()
	{
		memset(lazy,0,sizeof(lazy));
	}

	void build(ll v,ll left ,ll right)
	{
		if(left==right)
		{
			t[v]=a[left];
			return;
		}
		ll mid=(left+right)/2;
		build(2*v,left,mid);
		build(2*v+1,mid+1,right);
		t[v]=(t[2*v]+t[2*v+1]);
	}

	ll sum(ll v, ll tl, ll tr, ll l, ll r) 
	{
		if(lazy[v]) 
		{
			t[v]+=(tr-tl+1)*lazy[v];
			if(tl!=tr)
			{
				lazy[2*v]+=lazy[v];
				lazy[2*v+1]+=lazy[v];
			}
			lazy[v]=0;
		}
	    if (l > r)  return 0;
	    if (l == tl && r == tr) return t[v];
	    ll tm = (tl + tr) / 2;
	    return sum(v*2, tl, tm, l, min(r, tm)) +  sum(v*2+1, tm+1, tr, max(l, tm+1), r);
	}
	void update(ll v, ll tl, ll tr, ll l,ll r, ll addend) 
	{
		if(lazy[v]) 
		{
			t[v]+=(tr-tl+1)*lazy[v];
			if(tl!=tr)
			{
				lazy[2*v]+=lazy[v];
				lazy[2*v+1]+=lazy[v];
			}
			lazy[v]=0;
		}
		if(l>r) return;
		if(l==tl  and  r==tr)
		{
			t[v]+=(r-l+1)*addend;
			if(l!=r)
			{
				lazy[2*v]+=addend;
				lazy[2*v+1]+=addend;
			}
			return;

		}  
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = t[v*2] + t[v*2+1];    
	}
	void build()
	{
		build(1,0,n-1);
	}
	ll sum(ll a,ll b)
	{
		return sum(1,0,n-1,a,b);
	}
	void update(ll l,ll r,ll addend)
	{
		update(1,0,n-1,l,r,addend);
	}
	
};
typedef struct segment_tree segt;

int main()
{
	boost;
	cin>>n;
	for(ll i=0;i<n;i++) cin>>a[i];
	segt s;
	s.build();
	cout<<s.sum(0,2)<<endl;
	s.update(0,2,-1);
	cout<<s.sum(0,2)<<endl;	
	return 0;
}
