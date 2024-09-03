//sum of digits
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num,sum=0;
	cout<<"enter number ";
	cin>>num;
	
	for(int i=0;num != 0 ;i++)
	{
		sum=sum+num%10;
		num=num/10;
	}
	cout<<sum;
	return 0;
}
