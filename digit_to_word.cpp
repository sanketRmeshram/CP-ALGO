#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define check(x) cout << #x << " : " << (x) << endl
#define all(v) v.begin(),v.end() 
#define allr(v) v.rbegin(),v.rend() 
//#define endl '\n'  
typedef  long long ll; 
typedef  unsigned long long ull; 
typedef vector< ll > edge; 
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll mod=1e9+7;
const ll inf=1e15+10;
const ll N=1e6+10;

map<ll, string> s;

vector<string > tens(ll a)
{
	std::vector<string > ans;
	if(a  >=20 )
	{
		ans.pb(s[(a/10)*10]);
		if(a%10)
		{
			ans.pb(s[a%10]);
		}
	}
	else
	{
		ans.pb(s[a]);
	}
	return ans;
}


std::vector<string > get(ll a)
{
	std::vector<string> ans,temp;
	if(a/1000)
	{
		temp=tens(a/1000);
		for(auto &i:temp) ans.pb(i);
		ans.pb(s[1000]);	
	}	
	a=a%1000;
	if(a/100)
	{
		ans.pb(s[a/100]);
		ans.pb(s[100]);
	}
	if(a%100)
	{
		temp=tens(a%100);
		for(auto i:temp) ans.pb(i);
	}
	if((int)ans.size() == 0)
	{
		ans.pb(s[0]);
	}
	return ans;
}

void pre()
{
	s[0]="Zero";
	s[1]="One";
	s[2]="Two";
	s[3]="Three";
	s[4]="Four";
	s[5]="Five";
	s[6]="Six";
	s[7]="Seven";
	s[8]="Eight";
	s[9]="Nine";
	s[10]="Ten";
	s[11]="Eleven";
	s[12]="Twelve";
	s[13]="Thirteen";
	s[14]="Fourteen";
	s[15]="Fifteen";
	s[16]="Sixteen";
	s[17]="Seventeen";
	s[18]="Eighteen";
	s[19]="Nineteen";
	s[20]="Twenty";
	s[30]="Thirty";
	s[40]="Forty";
	s[50]="Fifty";
	s[60]="Sixty";
	s[70]="Seventy";
	s[80]="Eighty";
	s[90]="Ninety";
	s[100]="Hundred";
	s[1000]="Thousand";

}

int main()
{
	boost;

  	return 0;
}  
