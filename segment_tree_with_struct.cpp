#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.exceptions(cin.failbit)

struct data
{

	/*
		data you want to store in each node
	*/
	int sum=0,subarray=0,pref=0,suff=0;
	void initiate(int a)
	{
		sum=subarray=pref=suff=a;
	}
};
 
 
struct segment_tree
{
	int n;
	vector<data> a,t;
	void init(std::vector<data> b)
	{
		a=b;
		n=a.size();
		data temp;
		/*
			intiate your data here if you want to 
		*/
		t.assign(4*(n+10),temp);
		
	}
	data operation(data x,data y)
	{
		data a;

		/*
			operation on your data
		*/		
		a.sum=x.sum+y.sum;
		a.pref=max({x.pref,x.sum+y.pref});
		a.suff=max({y.suff,y.sum+x.suff});
		a.subarray=max({x.subarray,y.subarray,x.suff+y.pref});



 
		return a;
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
 
	data sum(int v, int tl, int tr, int l, int r) 
	{

		if (l == tl && r == tr) return t[v];
 
		int tm = (tl + tr) / 2;
		if(l>min(r, tm)) return sum(v*2+1, tm+1, tr, max(l, tm+1), r);
		if(max(l, tm+1)> r) return 	sum(v*2, tl, tm, l, min(r, tm));
		return operation (sum(v*2, tl, tm, l, min(r, tm))  , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
	}
	void update(int v, int tl, int tr, int pos, data new_val) 
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
	data sum(int a,int b)
	{
		return sum(1,0,n-1,a,b);
	}
	void update(int pos,data val)
	{
		update(1,0,n-1,pos,val);
	}
}; 


int main()
{
	boost;

	return 0;
} 
