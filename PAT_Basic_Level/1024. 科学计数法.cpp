#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s[0]=='-'){
		cout<<'-';
	}
	int pos;
	for(int i=3;i<s.length();i++){
		if(s[i]=='E'){
			pos=i;
			break;
		}
	}
	int num=0;
	for(int i=pos+2;i<s.length();i++){
		num+=(s[i]-'0')*pow(10,s.length()-1-i);
	}
	if(s[pos+1]=='+'){
		cout<<s[1];
		if(pos-3>num){
			for(int i=3;i<=3+num-1;i++){
				cout<<s[i];
			}
			cout<<".";
			for(int i=num+3;i<pos;i++){
				cout<<s[i];
			}
		}
		else{
			for(int i=3;i<pos;i++){
				cout<<s[i];
			}
		}
		for(int i=num+1-(pos-2);i>0;i--){
			cout<<'0';
		}
	}
	else{
		cout<<"0.";
		for(int i=1;i<num;i++){
			cout<<"0";
		}
		cout<<s[1];
		for(int i=3;i<pos;i++){
			cout<<s[i];
		}
	}
	return 0;
}
