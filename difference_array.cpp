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

struct difference_array
{
	vector<int> a;
	int n;

	void init(vector<int> b)
	{
		a=b;
		int n=a.size();
		
	}
	void build()
	{
		for(int i=n-1;i>0;i--) a[i]-=a[i-1];
	}
	void add(int L,int R,int val)
	{
		a[L]+=val;
		if((R+1)<n) a[R+1]-=val;
	}
	vector<int> get_back()
	{
		vector<int> ans;
		ans=a;
		for(int i=1;i<n;i++) ans[i]+=ans[i-1];
		return ans;	
	}
	
};


int main()
{
	boost;

	return 0;
}
