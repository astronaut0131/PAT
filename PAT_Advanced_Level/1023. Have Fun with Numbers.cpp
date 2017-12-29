#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map <int,int> mapp;
map <int,int> mapo;
int main(){
	string x;
	cin>>x;
	for(int i=0;i<x.length();i++){
		mapo[x[i]-'0']++;
	}
	reverse(x.begin(),x.end());
	int temp=0;
	for(int i=0;i<x.length();i++){
		int m=x[i]-'0';
		x[i]=(m*2%10+temp)+'0';
		temp=m*2/10;
	}
	reverse(x.begin(),x.end());
	for(int i=0;i<x.length();i++){
		mapp[x[i]-'0']++;
	}
	if(temp!=0){
		mapp[temp]++;
	}
	int flag=0;
	for(int i=0;i<=9;i++){
		if(mapp[i]!=mapo[i]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	if(temp!=0){
		cout<<temp;
	}
	cout<<x;
	return 0;
}
