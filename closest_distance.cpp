#include<bits/stdc++.h>
using namespace std;
#define inf 1e20
struct coordinate
{
	double x,y;
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

double minimum_distance_strip(coordinate * points,int n,double d,double mid)
{
	coordinate *strip;
	strip=(coordinate*)malloc((n)*sizeof(coordinate));
	int total=0;
	for(int i=0;i<n;i++) if(abs(points[i].x-mid)<d) strip[total++]=points[i];
	double dist=inf;	
	for(int i=0;i<total;i++)
	{
		for(int j=0,index=i+1;j<7 and index<total;j++,index++)
		{
			dist=min(dist,distance(strip[i],strip[index]));
		}
	}	
	free(strip);
	return dist;
}

double minimum_distance(coordinate* points, int n,coordinate** points_by_y)
{
	if(n==2) 
	{
		(*points_by_y)=mearge(points,1,points+1,1);
		return distance(points[0],points[1]);
	}
	if(n<2)
	{
		(*points_by_y)=(coordinate*)malloc(1*sizeof(coordinate));
		(*points_by_y)[0]=points[0];
		return inf;
	}
	int half=n/2;
	coordinate* left;
	coordinate* right;
	double d1=minimum_distance(points,half,&left);
	double d2=minimum_distance(points+half,n-half,&right);
	double midx=points[half-1].x;
	double d=min(d1,d2);
	(*points_by_y)=mearge(left,half,right,n-half);
	free(left);
	free(right);
	return min(d,minimum_distance_strip(*points_by_y,n,d,midx));
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
	for(int i=0;i<n;i++) cin>>points[i].x>>points[i].y;
	sort(points,points+n,cmp);
	coordinate *a;
	cout<<minimum_distance(points,n,&a);	
	return 0;
}
