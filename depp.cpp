#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	int i;
	cout<<"enter num ";
	cin>>num;
	
	while(1)
	{
	int sum=0;
	for(i=0;num>0;i++)
	{
		sum=sum+num%10;
		num=num/10;
	}
	if(sum<10)
	{
		cout<<sum;
		break;
	}
	else
	{
	num=sum;
    }
}
	return 0;
}
