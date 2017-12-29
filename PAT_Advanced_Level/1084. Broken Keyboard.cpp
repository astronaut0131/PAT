#include <iostream>
#include <map>
#include <cctype>
#include <vector>
using namespace std;
map <char,int> mapp;
vector <char> v;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++){
		s1[i]=toupper(s1[i]);
	}
	for(int i=0;i<s2.length();i++){
		s2[i]=toupper(s2[i]);
	}
	for(int i=0;i<s1.length();i++){
		int flag=0;
		for(int j=0;j<s2.length();j++){
			if(s1[i]==s2[j]){
				flag=1;
				break;
			}
		}
		if(flag==0&&mapp[s1[i]]==0){
			cout<<s1[i];
			mapp[s1[i]]++;
		}
	}
	return 0;
}
