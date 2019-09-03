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
typedef long long ll; 
typedef unsigned long long ull; 
typedef long double ld;
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <mypair, vector<mypair>, greater<mypair> > min_heap;
const ll mod=1e9+7;
const ll inf=1e16;
const ll N=5e5+10;

struct point
{
    long double x,y;
    int get_quad()
    {
        if(x>=0 and y>=0 ) return 0;
        if(x<=0 and y>=0) return 1;
        if(x<=0 and y<=0) return 2;
        if(x>=0 and y<=0 ) return 3;

    }
    bool operator < ( point &other)
    {
        int q1=get_quad();
        int q2=other.get_quad();
        if(q1!=q2) return q1<q2;
        if(q1==0)
        {
            return abs(y/x) < abs(other.y/other.x);
        }
        if(q1==1)
        {
            return abs(y/x) > abs(other.y/other.x);
        }
        if(q1==2)
        {
            return abs(y/x) < abs(other.y/other.x);
        }
        if(q1==3)
        {   
            return abs(y/x) > abs(other.y/other.x);
        }   
    }
    point operator + (const point &other)
    {
        point a=point{x+other.x,y+other.y};
        return a;
    }
    point operator - (const point &other)
    {
        point a=point{x-other.x,y-other.y};
        return a;
    }   

};

long double dist(point a ,point b=point{0,0})
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
} 

int main()
{
    boost;
    
    return 0;
}
