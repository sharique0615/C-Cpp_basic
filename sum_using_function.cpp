//function basic 
#include<bits/stdc++.h>
using namespace std;
int add(int a,int b)
{
	int sum=a+b;
	return sum;
}
int main()
{
	int res,a,b;
	cout<<"enter two numbers" ;
	cin>>a>>b;
	res=add(a,b);
	cout<<res;
	return 0;
}
