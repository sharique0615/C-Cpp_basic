//sum of series 
/* question : a series of number is given as 1+2-3+4-5+6-7....n find reuslt of this series */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=0;
	cout<<"enter last number of the series ";
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			sum=sum-i;
		}
		else
		{
			sum=sum+i;
		}
		
	}
	cout<<sum;
	return 0;
}
