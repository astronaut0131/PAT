#include <iostream>
#include <vector>
using namespace std;
vector <string> v;
int main(){
	int N;
	int min = 666;
	cin>>N;
	getchar();
	for(int i=0;i<N;i++){
		string x;
		getline(cin,x);
		v.push_back(x);
		if(x.length() < min){
			min = x.length();
		}
	}
	string last = "";
	for(int i=0;i<=min;i++){
		string temp = v[0].substr(v[0].length()-i,v[0].length());
		int flag = 1;
		for(int j=1;j<v.size();j++){
			if(temp != v[j].substr(v[j].length()-i,v[j].length())){
				flag = 0;
				break;
			}
		}
		if(flag){
			last = temp;
		} 
		else break;
	}
	if(last == "") cout<<"nai";
	else cout<<last;
	return 0;
}
