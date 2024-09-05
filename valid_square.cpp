//valid perfect square
#include<bits/stdc++.h>
using namespace std;
int main() {
	int num;
	cout<<"enter num ";
	cin>>num;

	for(int i=1; i<num; i++) {

		if(i*i == num ) {
			cout<<i;
			break;
		} else if(i*i>num) {
			cout<<"not a perfect sq";
			break;
		} 
		else {
			continue;
		}
		return 0;
	}

}
