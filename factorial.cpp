//first n factorial 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,fact=1;
	cout<<"enter";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		fact=i*fact;
		cout<<"factorials are "<<fact<<endl;
	}
	return 0;
}
