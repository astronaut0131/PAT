#include <iostream>
#include <string>
using namespace std;
int main(){
	int result=0;
	string s;
	cin>>s;
	int count_t=0,count_p=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='T'){
			count_t++;
		}
	}
	for(int i=0;i<s.length();i++){
		if(s[i]=='P'){
			count_p++;
		}
		if(s[i]=='T'){
			count_t--;
		}
		if(s[i]=='A'){
			result+=(count_p*count_t);
			result=result%1000000007;
		}
	}
	cout<<result;
	return 0;
}
