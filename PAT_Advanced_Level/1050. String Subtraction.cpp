#include <iostream>
#include <map>
using namespace std;
map <char,int> mapp;
int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.length();i++){
		mapp[s2[i]]=1;
	}
	for(int i=0;i<s1.length();i++){
		if(mapp[s1[i]]==0){
			cout<<s1[i];
		}
	}
	return 0;
}
