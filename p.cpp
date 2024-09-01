//pattern 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cout<<"enter value for n ";
	cin>>n;
	k=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<j ;
		}
		cout<<endl;
		k--;
	}
	return 0;
}
