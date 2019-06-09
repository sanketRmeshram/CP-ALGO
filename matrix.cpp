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
 ll mod=1e9+7;
const ll inf=1e15+10;
const ll N=3e6;

struct matrix
{
	vector<vector<ll> > mat;
	void resize(ll a,ll b, ll initial)
	{
		mat.resize(a,vector<ll> (b,initial));
	}
	void identity()
	{
		for(auto &i:mat) for(auto &j:i) j=0;
		for(ll i=0;i<(ll)mat.size();i++) mat[i][i]=1;
	}
	ll get_rows()
	{
		return mat.size();
	}	
	ll get_cols()
	{
		return mat[0].size();
	}
	matrix operator + ( matrix & b)  const
	{
		matrix temp;
		ll ro,co;
		ro=b.get_rows();
		co=b.get_cols();
		temp.resize(ro,co,0);
		for(ll i=0;i<ro;i++)  
		{
			for(ll j=0;j<co;j++)
			{
				//temp.mat[i][j]=mat[i][j]+b.mat[i][j];
				temp.mat[i][j]=(mat[i][j]%mod)+(b.mat[i][j]%mod);
				temp.mat[i][j]%=mod;
			}
		}	
		return temp;
	}
	matrix operator * ( matrix & b)  const
	{
		matrix temp;
		ll ro,co;
		ro=mat.size();
		co=b.get_cols();
		ll mi=b.get_rows();
		temp.resize(ro,co,0);
		for(ll i=0;i<ro;i++)  
		{
			for(ll j=0;j<co;j++)
			{
				for(ll k=0;k<mi;k++)
				{
					//temp.mat[i][j]+=mat[i][k]*b.mat[k][j];
					temp.mat[i][j]+=((mat[i][k]%mod) * (b.mat[k][j]%mod));
					temp.mat[i][j]%=mod;
				}
			}
		}	
		return temp;
	}	
	void print()
	{
		for(auto &i:mat)
		{
			for(auto &j:i) cout<<j<<" ";
			cout<<endl;	
		}	

	}


};

matrix power(matrix a,ll b)
{
	matrix ans;
	ans.resize(a.get_rows(),a.get_cols(),0);
	ans.identity();
	while(b)
	{
		if(b & (ll)1)
		{
			ans=ans*a;
		}
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main()
{
	// problem : https://atcoder.jp/contests/abc129/tasks/abc129_f
	// my solution  :  https://atcoder.jp/contests/abc129/submissions/5862012
 	boost;
	ll l,a,b,m;
	cin>>l>>a>>b>>m;
	mod=m;
	ll lo,hi;
	matrix ans;
	ans.resize(1,3,0);
	ans.mat[0][0]=a%mod;
	ans.mat[0][1]=(a+b)%mod;
	ans.mat[0][2]=1;
	ll term =1,d=10;
	while(term<l)
	{
		lo=max((ll)0,((d/10-1)-a)/b);
		hi=min(l-1,max((d-1-a)/b,(ll)0));
		term+=hi-lo;
		ll now=hi-lo;
		matrix temp;
		temp.resize(3,3,0);
		temp.mat[0][0]=d%mod;
		temp.mat[1][0]=1;
		temp.mat[1][1]=1;
		temp.mat[2][1]=b%mod;
		temp.mat[2][2]=1;
		temp=power(temp,now);
		ans=ans*temp;
		d*=10;
		//check(term);check(hi);check(lo);
	}
	cout<<ans.mat[0][0];
  	return 0;
}  
