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
//#define endl '\n'  
#define mod 998244353
typedef  long long ll; 
typedef  unsigned long long ull; 
//using u64 = uint64_t; 
//using u128 = __uint128_t;
typedef vector< ll > edge; 
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll N=5000+20;

struct minimum_queue
{
	stack < pair<ll,ll> > s1,s2;

	ll size()
	{
		return (ll)s1.size()+(ll)s2.size();
	}
	bool empty()
	{
		return size()==0;
	}
	ll get_min()
	{
		ll minimum;
		if (s1.empty() || s2.empty()) 
		    minimum = s1.empty() ? s2.top().second : s1.top().second;
		else
		    minimum = min(s1.top().second, s2.top().second);	
		return minimum;    	
	}
	void push(ll new_element)
	{
		ll minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
		s1.push({new_element, minimum});
	}

	ll pop()
	{
		if(s2.empty())
		{
			while(!s1.empty())
			{
				ll element=s1.top().first;
				s1.pop();
				ll minimum = s2.empty() ? element : min(element, s2.top().second);
				s2.push({element, minimum});
			}
		}
		ll remove_element = s2.top().first;
		s2.pop();
		return remove_element;
	}
};
typedef struct minimum_queue minimum_queue;

int main()
{
	boost;
	std::vector<ll> v={4,12,-3,-10,49,-100};
	minimum_queue qe;
	ll i=0;
	while(1)
	{
		bool flag;
		cin>>flag;
		if(flag) qe.push(v[i]),i++;
		else qe.pop();
		cout<<qe.get_min()<<endl;

	}

	return 0;
}
