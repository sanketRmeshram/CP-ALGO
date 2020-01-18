#include <bits/stdc++.h>
using namespace std;

vector<int> get(int n) // a[i]=number of intergers < n have i_th bit set .
{
	vector<int> a(int(log2(n))+1,0);
	while(n)
	{
		int k=log2(n);
		n-=(1<<k);
		a[k]+=n+1;
		int bit=0;
		if(k)for(int j=0;j<k;j++) a[j]+=(1<<(k-1));
	}	
	return a;
}

int main()
{

	return 0;
}
