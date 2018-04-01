#include<sstream>
#include<iostream>
#include<vector>
#include<cctype> 
#include<map>
using namespace std;
int main(){
	string a,b;
	vector <char> c; 
	cin>>a>>b;
	int i=0,j=0;
	map <char,int> clear;
	for(i=0;i<a.length();i++){
		a[i]=toupper(a[i]);
	} 
	for(i=0;i<b.length();i++){
		b[i]=toupper(b[i]);
	}
	i=0;
	while(j<b.length()){
		if(a[i]==b[j]){
			i++;
			j++;
		}
		else{
			c.push_back(a[i]);
			i++; 
		}
	}
	for(i=0;i<c.size();i++){
		if(clear[c[i]]==0)
		clear[c[i]]=1;
		else c[i]=' ';
	}
	for(i=0;i<c.size();i++){
		if(c[i]!=' ')
		cout<<c[i];
	}
	return 0;
}