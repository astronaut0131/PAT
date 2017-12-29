#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int N;
string get_string(int x){
	stringstream s;
	s<<x;
	return s.str();
}
string make_string(string x){
	vector <char> v;
	int pos = -1,pos_dot = -1,k;
	for(int i=0;i<x.length();i++){
		if(x[i] != '0' and x[i]!='.'){
			if(v.size() == 0)
				pos = i;
			if(v.size() < N)
				v.push_back(x[i]);
		}
		else if(x[i] == '0' and v.size() != 0 and v.size() < N){
			v.push_back(x[i]);
		}
		else if(x[i] == '.') pos_dot = i;
	}
	if(pos == -1) k = 0;
	else if(pos_dot == -1) k = x.length();
	else if(pos_dot < pos) k = pos_dot - pos + 1; 
	else k = pos_dot - pos;
	string temp = "0.";
	for(int i=0;i<v.size();i++){
		temp += v[i];
	}
	if(pos == -1){
		for(int i=0;i<N;i++){
			temp += '0';
		}
	}
	temp += "*10^";
	temp += get_string(k);
	return temp;
}
int main(){
	scanf("%d",&N);
	string A,B;
	cin>>A>>B;
	string res_A = make_string(A);
	string res_B = make_string(B);
	if(res_A == res_B) cout<<"YES "<<res_A;
	else cout<<"NO "<<res_A<<" "<<res_B;
	return 0;
}
