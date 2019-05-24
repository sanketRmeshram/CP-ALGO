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
#define endl '\n'  
#define mod 1000000007
typedef  long long ll; 
typedef  unsigned long long ull; 
//using u64 = uint64_t; 
//using u128 = __uint128_t;
typedef vector< ll > edge; 
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll N=1e6+10;
ll n,a[N];
struct segment_tree
{
  ll t[4*N];

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
    t[v]=t[2*v]+t[2*v+1];
  }
  ll sum(ll v, ll tl, ll tr, ll l, ll r) 
  {
      if (l > r)  return 0;
      if (l == tl && r == tr) return t[v];
      
      ll tm = (tl + tr) / 2;
      return sum(v*2, tl, tm, l, min(r, tm))  + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
  }
  void update(ll v, ll tl, ll tr, ll pos, ll new_val) 
  {
      if (tl == tr)
      {
          t[v] = new_val;
          return;
      }  
        ll tm = (tl + tr) / 2;
        if (pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2+1, tm+1, tr, pos, new_val);
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
  void update(ll pos,ll val)
  {
    update(1,0,n-1,pos,val);
  }
  
};


int main()
{
  boost;
  
  return 0;
}
