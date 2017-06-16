#include<bits/stdc++.h>
using namespace std;

int n,c;

int cow(int num,int a[])
{
	int cows=1,pos=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]-pos>=num)
		{
			pos=a[i];
			cows++;
			if(cows==c)
			{
				return 1;
			}
		}
	}
	return 0;
}

int bs(int a[])
{
	int start=0,max=-1,end=a[n-1];
	while(end>start)
	{
	 int mid=(start+end)/2;
	 if(cow(mid,a)==1)
	 {
		if (mid>max)
            max=mid;
            start=mid+1;
	 }
	 else
	 {
		end=mid;
	 }
    }
    return max;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&c);
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int k=bs(a);
		printf("%d\n",k);
	}
	return 0;
}
