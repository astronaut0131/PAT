#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
using namespace std;
int string2int(string x){
	int result;
	stringstream s;
	s << x;
	s >> result;
	return result;
}

void break_string(string s,vector <string> *p){
	string cache = "";
	for(int i=0;i<s.length();i++){
		if(s[i] != ' ' and i != s.length() - 1){
			cache += s[i];
		}
		else{
			if(i == s.length() - 1)
				cache += s[i];
			(*p).push_back(cache);
			cache ="";
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
	}
	int M;
	scanf("%d",&M);
	cout<<M<<endl;
	getchar();
	for(int i=0;i<M;i++){
		string s;
		vector <string> segment;
		getline(cin,s);
		break_string(s,&segment);
		bool judge;
		if(segment.size() == 4)
			judge = string2int(segment[0]) == root->val;
		else if(segment.size() == 5)

		else if(segment.size() == 6)
			judge = string2int(sgement[0])==
		else if(segment.size() == 7){
			if(segment[3] == "left"){

			}
			else{

			}
		}
		else{

		}
	}
	return 0;
}