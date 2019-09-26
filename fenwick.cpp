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
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <mypair, vector<mypair>, greater<mypair> > min_heap;
const ll mod=1e9+7;
const ll inf=1e9;
const ll N=1e5+10;

struct Fenwick_Tree_add
{
	vector<int> bit;
	int n;
	int operation(int a,int b)
	{
		return a+b;
	}
	int reverse_operation(int element,int b)
	{
		return element-b;
	}
	void init(vector<int> a)
	{
		n=a.size();
		bit=vector<int>(n,0);
		for(int i=0;i<n;i++)
		{
			add(i,a[i]);
		}
	}
	int get(int r)
	{
		int ans=bit[r];
		r=(r&(r+1))-1;
		while(r>=0)		
		{
			ans=operation(ans,bit[r]);
			r=(r&(r+1))-1;
		}
		return ans;
	}
	int query(int l,int r)
	{
		if(l>0) return reverse_operation(get(r),get(l-1));
		else return get(r);
	}
	void add(int index,int delta)
	{
		while(index<n)
		{
			bit[index]=operation(bit[index],delta);
			index=index|(index+1);
		}
	}
	void update(int index,int now)
	{
		add(index,reverse_operation(now,query(index,index)));
	}	
};

int main()
{
	boost;
	int cas=0;
	while(1)
	{
		cas++;
		int n;
		cin>>n;
		if(n==0) return 0;
		cout<<"Case "<<cas<<":"<<endl;
		std::vector<int> a(n);
		for(auto &i:a) cin>>i;
		Fenwick_Tree_add s;
		s.init(a);	
		while(1)
		{
			string temp;
			cin>>temp;
			if(temp=="END") break;
			int a,b;
			cin>>a>>b;
			if(temp=="M")
			{
				a--;b--;
				cout<<s.query(a,b)<<endl;
			}
			else
			{
				a--;
				s.update(a,b);
			}
		}	
		cout<<endl;
	}
	return 0;
}
