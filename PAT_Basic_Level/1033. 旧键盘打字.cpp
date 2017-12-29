#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
vector <int> num,alpha,symbol;
int main(){
	string A,B;
	getline(cin,A);
	getline(cin,B);
	if(A.length()==0){
		cout<<B;
		return 0;
	}
	int flag=0;
	for(int j=0;j<A.length();j++){
		if(isdigit(A[j])){
			num.push_back(A[j]);
		}
		else if(isalpha(A[j])){
			alpha.push_back(A[j]);
		}
		else{
			symbol.push_back(A[j]);
			if(A[j]=='+'){
				flag=1;
			}
		}
		
	}
	for(int i=0;i<B.length();i++){
		int judge=0;
		if(isalpha(B[i])||isdigit(B[i])||B[i]=='_'||B[i]==','||B[i]=='.'||B[i]=='-'){
			if(isdigit(B[i])){
			for(int j=0;j<num.size();j++){
				if(num[j]==B[i]){
					judge=1;
					break;
				}
			}
		}
		else if(isalpha(B[i])){
			if(flag==1&&isupper(B[i])){
				continue;
			}
			else{
				char temp=toupper(B[i]);
				for(int j=0;j<alpha.size();j++){
					if(alpha[j]==temp){
						judge=1;
						break;
					}
				}	
			}
		}
		else{
			for(int j=0;j<symbol.size();j++){
				if(symbol[j]==B[i]){
					judge=1;
					break;
				}
			}
		}
		if(judge==0){
			printf("%c",B[i]);
		}
		}
	}
	return 0;
}
