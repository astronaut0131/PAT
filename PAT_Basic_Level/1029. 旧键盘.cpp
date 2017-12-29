#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
bool visited[300];
using namespace std;
int main(){
	fill(visited,visited+300,false);
	string s1,s2;
	cin>>s1>>s2;
	int count=0;
	for(int i=0;i<s1.length();i++){
		s1[i]=toupper(s1[i]);
	}
	for(int i=0;i<s2.length();i++){
		s2[i]=toupper(s2[i]);
	}
	for(int i=0;i<s1.length();i++){
		if(visited[s1[i]-'\0']==false){
			int flag=0;
		    for(int j=0;j<s2.length();j++){
     			if(s1[i]==s2[j]){
	     			flag=1;
		    		break;
     			}
         	}
         	if(flag==0){
	    		cout<<s1[i];
	    		visited[s1[i]-'\0']=true;
	   	    }
		}
	}
	return 0;
}
