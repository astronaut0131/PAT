#include <iostream>
#include <algorithm>
using namespace std;
int num[10];
int main(){
	fill(num,num+10,0);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		int temp=s[i]-'0';
		num[temp]++;
	}
	for(int i=0;i<=9;i++){
		if(num[i]!=0){
			cout<<i<<":"<<num[i]<<endl;
		}
	}
	return 0;
}
