//basic mathematical operations using functions
#include <bits/stdc++.h>
using namespace std;
int add(int a,int b)
{
	int sum=a+b;
	return sum;
}
int diff(int a, int b)
{
	int sub=a-b;
	return sub;
}
int prod(int a,int b)
{
	int mult=a*b;
	return mult;
}
int divi(int a,int b)
{
   int quot(a/b);
	return quot;
}
int rem(int a,int b)
{
	int mod(a%b);
	return mod;
}
int main()
{
	int a,b;
	cout<<"enter nums ";
	cin>>a>>b;
	cout<<add(a,b)<<endl;
	cout<<diff(a,b)<<endl;
	cout<<prod(a,b)<<endl;
	cout<<divi(a,b)<<endl;	
	cout<<rem(a,b)<<endl;
	return 0;
}
