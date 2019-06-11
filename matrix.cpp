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
typedef pair< string , string > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll mod=1e9+7;
const ll inf=1e15;
const ll N=3e5+10;
struct matrix
{
	vector<vector<ll> > mat;
	matrix(ll a,ll b, ll initial)
	{
		vector<vector<ll> >  temp(a,vector<ll> (b,initial));
		mat=temp;
	}
	void resize(ll a,ll b, ll initial)
	{
		vector<vector<ll> >  temp(a,vector<ll> (b,initial));
		mat=temp;
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
		
		ll ro,co;
		ro=b.get_rows();
		co=b.get_cols();
		matrix temp(ro,co,0);
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
		
		ll ro,co;
		ro=mat.size();
		co=b.get_cols();
		ll mi=b.get_rows();
		matrix temp(ro,co,0);
		for(ll i=0;i<ro;i++)  
		{
			for(ll j=0;j<co;j++)
			{
				temp.mat[i][j]=0;
				for(ll k=0;k<mi;k++)
				{
					//temp.mat[i][j]+=mat[i][k]*b.mat[k][j];
					temp.mat[i][j]+=(((mat[i][k]%mod) * (b.mat[k][j]%mod))%mod);
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
	matrix ans(a.get_rows(),a.get_cols(),0);
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
	boost;
	// http://fusharblog.com/solving-linear-recurrence-for-programming-contest/?fbclid=IwAR2ku0FHxHJG9BsZIlVqQiseewnnwOzXYTVE0Sl5RBI5EPq1rwQ6VYEcpOI
  	return 0;
}  
