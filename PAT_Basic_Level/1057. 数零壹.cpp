#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main(){
	int n=0;
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(isalpha(s[i])){
			s[i]=tolower(s[i]);
			n+=s[i]-'a'+1;
		}
	}
	int num0=0,num1=0;
	while(n!=0){
		if(n%2==0){
			num0++;
		}
		else{
			num1++;
		}
		n/=2;
	}
	cout<<num0<<" "<<num1;
}
