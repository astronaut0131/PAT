#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
int num[26];
using namespace std;
int main(){
	fill(num,num+26,0);
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(isalpha(s[i])){
			s[i]=tolower(s[i]);
		    num[s[i]-'a']++;
		}
	}
	int max=0;
	int u;
	for(int i=0;i<26;i++){
		if(num[i]>max){
		    u=i;
			max=num[i];	
		}
	}
	char temp ='a'+u;
	cout<<temp<<" "<<max;
	return 0;
}
