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
typedef priority_queue <int, vector<int>, greater<int> > min_heap;
const ll mod=1e9+7;
const ll inf=1e9;
const ll N=(1<<20);


//
//
// ref :   https://codeforces.com/blog/entry/45223
//
int bit=20;
int a[N];
ll sum[N];

void sum_of_superset()
{
	// a contains value corresponding to each mask
	for(int i=0;i<(1<<bit);i++) sum[i]=a[i];	
	for(int i=0;i<bit;i++)
	{
		for(int mask=(1<<bit)-1;mask>=0;mask--)
		{
			if((mask &  (1<<i))==0) sum[mask]+=sum[mask^(1<<i)];
		}
	}	
}

void sum_of_subset()
{
	// a contains value corresponding to each mask
	for(int i=0;i<(1<<bit);i++) sum[i]=a[i];	
	for(int i=0;i<bit;i++)
	{
		for(int mask=0;mask<(1<<bit);mask++)
		{
			if((mask &  (1<<i))) sum[mask]+=sum[mask^(1<<i)];
		}
	}	
}

int main()
{
	boost;
	//

	return 0;
}
