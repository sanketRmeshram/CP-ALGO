#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;

struct online_prefix_max  //// this will return maximum value with key <=given_key
{
	map<int,int> ma;
	pair<int,int> not_found=make_pair(-inf,-inf);
	pair<int,int> query(int key)
	{
		auto it=ma.upper_bound(key);
		if(it==ma.begin()) return not_found;
		it--;
		return *it;
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

vector<int> lis(vector<int> a) //returns  strictly increasing subsequence's indices
{
	int n=a.size();
	vector<int> dp(n,0);
	vector<int> prev(n,0);
	map<int,int> index;
	dp[0]=1;
	online_prefix_max s;
	s.insert(a[0],dp[0]);
	prev[0]=-1;
	index[a[0]]=0;
	for(int i=1;i<n;i++)
	{
		auto now=s.query(a[i]-1);
		if(now!=s.not_found)
		{
			dp[i]=now.second+1;
			prev[i]=index[now.first];
		}
		else
		{
			dp[i]=1;
			prev[i]=-1;
		}
		index[a[i]]=i;
		s.insert(a[i],dp[i]);
	}
	int ans=max_element(dp.begin(), dp.end())-dp.begin();
	vector<int> ind;
	while(ans!=-1)
	{
		ind.push_back(ans);
		ans=prev[ans];
	}
	reverse(ind.begin(), ind.end());
	return ind;


}
int main()
{
	

    return 0;
}
