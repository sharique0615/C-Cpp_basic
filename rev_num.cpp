//reverse digit of a number,ex if num is 125 result should be 521
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num,old_rev=0,rev;
	cout<<"enter number ";
	cin>>num;
	
	for(int i=0;num != 0 ;i++)
	{
		rev=num%10;
		old_rev=(old_rev * 10) + rev;
		num=num/10;
	}
	cout<<old_rev;
	return 0;
	
}

  
