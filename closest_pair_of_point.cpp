#include<bits/stdc++.h>
using namespace std;
#define inf 1e20
#define check(x) cout << #x << " : " << (x) << endl
//  https://www.spoj.com/problems/CLOPPAIR/
struct coordinate
{
    double x,y;
    int index;
};

double distance(coordinate a,coordinate b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

coordinate* mearge(coordinate* a,int n,coordinate* b,int m)
{
    coordinate* ans;
    ans=(coordinate*)malloc((n+m)*sizeof(coordinate));
    int total=n+m;
    for(int i=0,j=0,index=0;index<(total);index++)
    {
        if(i==n) ans[index]=b[j++];
        else if (j==m) ans[index]=a[i++];
        else if(a[i].y< b[j].y) ans[index]=a[i++];
        else ans[index]=b[j++];
    }
    return ans;
}

pair<double, pair<int,int> > minimum_distance_strip(coordinate * points,int n,double d,double mid)
{
    coordinate *strip;
    strip=(coordinate*)malloc((n)*sizeof(coordinate));
    int total=0;
    for(int i=0;i<n;i++) if(abs(points[i].x-mid)<d) strip[total++]=points[i];
    pair<double, pair<int,int> > dist=make_pair(inf,make_pair(-1,-1));   
    for(int i=0;i<total;i++)
    {
        for(int j=0,index=i+1;j<7 and index<total;j++,index++)
        {
            dist=min(dist,make_pair(distance(strip[i],strip[index]),make_pair(strip[i].index,strip[index].index)));
        }
    }   
    return dist;
}

pair<double, pair<int,int> > minimum_distance(coordinate* points, int n,coordinate** points_by_y)
{
    if(n==2) 
    {
        (*points_by_y)=mearge(points,1,points+1,1);
        return make_pair(distance(points[0],points[1]),make_pair(points[0].index,points[1].index));
    }
    if(n<2)
    {
        (*points_by_y)=(coordinate*)malloc(1*sizeof(coordinate));
        (*points_by_y)[0]=points[0];
        return make_pair(inf,make_pair(-1,-1));
    }
    int half=n/2;
    coordinate* left;
    coordinate* right;
    pair<double, pair<int,int> > d1=minimum_distance(points,half,&left);
    pair<double, pair<int,int> > d2=minimum_distance(points+half,n-half,&right);
    double midx=points[half-1].x;
    auto d=min(d1,d2);
    (*points_by_y)=mearge(left,half,right,n-half);
    free(left);
    free(right);
    return min(d,minimum_distance_strip(*points_by_y,n,d.first,midx));
}

bool cmp(coordinate a,coordinate b)
{
    return a.x < b.x;
}

int main()
{
    int n;
    cin>>n;
    coordinate* points;
    points=(coordinate*)malloc(n*sizeof(coordinate));
    for(int i=0;i<n;i++) {cin>>points[i].x>>points[i].y; points[i].index=i;}
    sort(points,points+n,cmp);
    coordinate *a;
    auto ans=minimum_distance(points,n,&a);
    cout<<min(ans.second.first,ans.second.second)<<" "<<max(ans.second.first,ans.second.second)<<" "<<fixed<<setprecision(6)<<ans.first;
    return 0;
}
