#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.exceptions(cin.failbit)


struct segment_tree
{
	int n;
	vector<int> a,t,lazy;
	void init(vector<int> b)
	{
		a=b;
		n=a.size();
		t.assign(4*(n+10),0);
		lazy.assign(4*(n+10),0);
	}

	void build(int v,int left ,int right)
	{
		if(left==right)
		{
			t[v]=a[left];
			return;
		}
		int mid=(left+right)/2;
		build(2*v,left,mid);
		build(2*v+1,mid+1,right);
		t[v]=(t[2*v]+t[2*v+1]);
	}

	int sum(int v, int tl, int tr, int l, int r) 
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
	    int tm = (tl + tr) / 2;
	    return sum(v*2, tl, tm, l, min(r, tm)) +  sum(v*2+1, tm+1, tr, max(l, tm+1), r);
	}
	void update(int v, int tl, int tr, int l,int r, int addend) 
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
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = t[v*2] + t[v*2+1];    
	}
	void build()
	{
		build(1,0,n-1);
	}
	int sum(int a,int b)
	{
		return sum(1,0,n-1,a,b);
	}
	void update(int l,int r,int addend)
	{
		update(1,0,n-1,l,r,addend);
	}
	
};


int main()
{
	boost;
	int n;
	cin>>n;
	std::vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	segment_tree s;
	s.init(a);
	s.build();
	cout<<s.sum(0,2)<<endl;
	s.update(0,2,-1);
	cout<<s.sum(0,1)<<endl;	
	return 0;
}
