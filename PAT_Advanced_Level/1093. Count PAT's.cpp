#include <iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int p=0,t=0;
	int sum=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='T'){
			t++;
		}
	}
	for(int i=0;i<s.length();i++){
		if(s[i]=='P'){
			p++;
		}
		else if(s[i]=='T'){
			t--;
		}
		else if(s[i]=='A'){
			sum+=p*t;
			sum%=1000000007;
		}
	}
	cout<<sum;
	return 0;
}
