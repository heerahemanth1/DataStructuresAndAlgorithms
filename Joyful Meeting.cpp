#include<bits/stdc++.h>
using namespace std;

bool check(string str1,string str2)
{
    int len1=str1.length();
    int len2=str2.length();
    if (len1!=len2)
    {
        return 0;
    }
    if(len1==len2)
    {
    	sort(str1.begin(),str1.end());
    	sort(str2.begin(),str2.end());
        for(int i=0;i<len1;i++)
        {
         if(str1[i]!=str2[i])
         {
        	return 0;
        	break;
		 }
	    }
	}
    return 1;
}
 
int main()
{
    int t;
    cin>>t;
    if(t<100)
    {
      while(t--)
      {
        string str1,str2;
        cin>>str1;
        cin>>str2;
        bool j=check(str1,str2);
        if(j==1)
        {
        	cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
          cout<<endl;
      }
    }
    return 0;
}
