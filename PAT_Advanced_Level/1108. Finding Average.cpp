#include <iostream>
#include <stdio.h>
#include <cctype>
#include <sstream>
using namespace std;
float temp;
bool judge(string x){
	if(not (isdigit(x[0]) or x[0] == '-')){
		return false;
	}
	int dot_num = 0,dot_pos = 0;
	for(int i=0;i<x.length();i++){
		if(x[i] == '.'){
			dot_num++;
			dot_pos = i;
		}
	}
	if(dot_num > 1){
		return false;
	}
	else{
		if(dot_num == 1){
			int acc = x.length() - dot_pos-1;
			if(acc>2){
				return false;
			}
		}
		stringstream s;
		s<<x;
		s>>temp;
		if(temp >1000 or temp <-1000) return false;
		else return true;
	}
}

int main(){
	int N;
	cin>>N;
	int cnt = 0;
	float sum = 0;
	for(int i=0;i<N;i++){
		string x;
		cin>>x;
		if(judge(x)){
			cnt++;
			sum+=temp;
		}
		else{
			cout<<"ERROR: "<<x<<" is not a legal number"<<endl;
		}
	}
	printf("The average of %d",cnt);
	if(cnt == 0){
		printf(" numbers is Undefined");
	}
	else if(cnt == 1){
		printf(" number is %.2f",sum);
	}
	else{
		printf(" numbers is %.2f",sum/cnt);
	}
	return 0;
} 
