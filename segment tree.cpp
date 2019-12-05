#include <bits/stdc++.h>
using namespace std;

struct segment_tree
{
	int n;
	vector<int> a,t;
	void init(std::vector<int> b)
	{
		a=b;
		n=a.size();
		t.assign(4*(n+10),0);
		
	}
	int operation(int x,int y)
	{
		return x+y;
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
		t[v]=operation(t[2*v],t[2*v+1]);
	}

	int sum(int v, int tl, int tr, int l, int r) 
	{
		if (l > r)  return 0;
		if (l == tl && r == tr) return t[v];

		int tm = (tl + tr) / 2;
		return operation (sum(v*2, tl, tm, l, min(r, tm))  , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
	}
	void update(int v, int tl, int tr, int pos, int new_val) 
	{
		if (tl == tr)
		{
			t[v] = new_val;
			return;
		}  
	    int tm = (tl + tr) / 2;
	    if (pos <= tm) update(v*2, tl, tm, pos, new_val);
	    else update(v*2+1, tm+1, tr, pos, new_val);
	    t[v]=operation(t[2*v],t[2*v+1]); 
	}
	void build()
	{
		build(1,0,n-1);
	}
	int sum(int a,int b)
	{
		return sum(1,0,n-1,a,b);
	}
	void update(int pos,int val)
	{
		update(1,0,n-1,pos,val);
	}
}; 

int main()
{
	return 0;
}
