#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string x;
	getline(cin,x);
	int max_len = 0;
	for(int i=0;i<x.length();i++){
		for(int j=1;j<x.length()-i+1;j++){
			string s = x.substr(i,j);
			if(s[0] == s[s.length()-1]){
				string temp = s;
				reverse(s.begin(),s.end());
				if(temp == s and temp.length()>max_len){
					max_len = temp.length();
				}
			}
		}
	}
	cout<<max_len;
	return 0;
}
