#include <iostream>
#include <algorithm>
using namespace std;
bool is_symmetric(string s){
	if(s[0] != s[s.length() - 1])
		return false;
	string copy = s;
	reverse(s.begin(), s.end());
	return s == copy;
}
int main(){
	int max_len = 0;
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		for(int j=s.length()-1-i;j>=0;j--){
			string substring = s.substr(i,j);
			/*if(is_symmetric(substring) and substring.length() > max_len){
				max_len = substring.length();
				break;
			}*/
			cout<<substring<<endl;
		}
	}
	printf("%d",max_len);
	return 0;
}