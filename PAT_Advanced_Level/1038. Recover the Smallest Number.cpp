#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(string A,string B){
	return A+B < B+A;
}
int main(){
	int N;
	scanf("%d",&N);
	vector <string> v;
	getchar();
	v.resize(N);
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),cmp);
	string res = "";
	for(int i=0;i<v.size();i++){
		res += v[i];
	}
	while(res[0] == '0' and res.length() > 0){
		res.erase(res.begin());
	}
	if(res.length() == 0) cout<<"0";
	else cout<<res; 
	return 0;
}
