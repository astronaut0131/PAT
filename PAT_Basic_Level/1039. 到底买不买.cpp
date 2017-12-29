#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int wanted[150];
int main(){
	fill(wanted,wanted+150,0);
	int extra=0;
	int need=0;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s2.length();i++){
		wanted[(int)s2[i]]++;
	}
	for(int i=0;i<s1.length();i++){
        if(wanted[(int)s1[i]]==0){
        	extra++;
		}
		else{
			wanted[(int)s1[i]]--;
		}
	}
	int flag=0;
	for(int i=0;i<150;i++){
		if(wanted[i]!=0){
			flag=1;
			need+=wanted[i];
		}
	}
	if(flag==1){
		printf("No %d",need);
	}
	else{
		printf("Yes %d",extra);
	}
	return 0;
}
