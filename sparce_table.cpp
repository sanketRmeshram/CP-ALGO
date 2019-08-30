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

struct sparce_table
{
	vector<int> a;
	vector< vector<int> > table;
	int n,LOG;
	void init(vector<int> b)
	{
		a=b;
		n=a.size();
		LOG=((int)log2(n))+1;
		vector<vector<int> >  temp(n,vector<int> (LOG+1));
		table=temp;
	} 
	int operation(int x,int y)
	{
		return min(x,y);
	}
	void build()
	{
		for(int i=0;i<n;i++) table[i][0]=a[i];
		for(int j=1;j<=LOG;j++)
		{
			for(int i=0;(i+(1<<j)-1) <= (n-1);i++ )
			{
				table[i][j]=operation(table[i][j-1],table[i+(1<<(j-1))][j-1]);
			}
		}	
	}
	int query(int L,int R)
	{
		int k=log2(R-L+1);
		return operation(table[L][k],table[R-(1<<k)+1][k]);
	}

};

int main()
{
	boost;

	return 0;
}
