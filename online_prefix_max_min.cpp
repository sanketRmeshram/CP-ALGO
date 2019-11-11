#include <bits/stdc++.h>
using namespace std;
 
const int inf=1e9;
struct online_prefix_max  //// this will return maximum value with key <=given_key
{
	map<int,int> ma;
	int query(int key)
	{
		auto it=ma.upper_bound(key);
		if(it==ma.begin()) return -inf;
		it--;
		return it->second;
	}
	void insert(int key,int value)
	{
		auto it=ma.lower_bound(key);
		if(it!=ma.begin())
		{
			auto prev=it;
			prev--;
			if(prev->second>=value)
			{
				return;
			}
		}
		while(it!=ma.end()  and it->second <= value)
		{
			it=ma.erase(it);
		}
		ma.insert({key,value});
	}
};

struct online_prefix_min  // this will return minimum value with key <=given_key
{
	map<int,int> ma;
	int query(int key) 
	{
		auto it=ma.upper_bound(key);
		if(it==ma.begin()) return inf;
		it--;
		return it->second;
	}
	void insert(int key,int value)
	{
		auto it=ma.lower_bound(key);
		if(it!=ma.begin())
		{
			auto prev=it;
			prev--;
			if(prev->second<=value)
			{
				return;
			}
		}
		while(it!=ma.end()  and it->second >= value)
		{
			it=ma.erase(it);
		}
		ma.insert({key,value});
	}
};

int main()
{

    online_prefix_min s;
    s.insert(1,-5);
    s.insert(2,-12);
    s.insert(2,-10);
    s.insert(10,-56);
    s.insert(0,-2);
    while(1)
    {
    	int q;
    	cin>>q;
    	cout<<s.query(q)<<endl;
    }
    return 0;
}
