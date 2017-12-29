#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector <string> result;
string chinese[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};	
void read(string s){
	if(s.length() == 1){
		result.push_back(chinese[s[0]-'0']);
	}
	else if(s.length() == 2){
		result.push_back(chinese[s[0]-'0']);
		result.push_back("Shi");
		if(s[1] != '0')
		result.push_back(chinese[s[1]-'0']);
	}
	else if(s.length() == 3){
		result.push_back(chinese[s[0]-'0']);
		result.push_back("Bai");
		if(s[1] != '0' and s[2] == '0'){
			result.push_back(chinese[s[1]-'0']);
			result.push_back("Shi");
		}
		else if (s[1] == '0' and s[2] != '0'){
			result.push_back("ling");
			result.push_back(chinese[s[2]-'0']);
		}
		else if(s[1]!='0' and s[2]!='0'){
			read(s.substr(1,2));
		}
	}
	else{
		if(s[0] != '0'){
			result.push_back(chinese[s[0]-'0']);
			result.push_back("Qian");
			if(s[1] == '0'){
				result.push_back("ling");
				read(s.substr(2,2));
			}
			else{
				read(s.substr(1,3));
			}
		}	
		else{
			result.push_back("ling");
			int pos = -1;
			for(int i=1;i<s.length();i++){
				if(s[i] != '0'){
					pos = i;
					break;
				}
			}
			if(pos!=-1){
				read(s.substr(pos,s.length()-pos));
			}
		}
	}
}
int main(){
	string s;
	cin>>s;
	if(s[0] == '-'){
		result.push_back("Fu");
		s = s.substr(1,s.length()-1);	
	}
	if(s.length() == 9){
		result.push_back(chinese[s[0]-'0']);
		result.push_back("Yi");
		read(s.substr(1,4));
		result.push_back("Wan");
		read(s.substr(5,4));
	}	
	else if(s.length()>=5 and s.length()<9){
		read(s.substr(0,s.length()-4));
		result.push_back("Wan");
		read(s.substr(s.length()-4,4));
	}
	else{
		read(s);
	}
	for(int i=0;i<result.size();i++){
		if(i != 0) cout<<" ";
		cout<<result[i];
	}
	return 0;
}
