#include <iostream>
#include <cmath>
using namespace std;
int main(){
	string x;
	cin>>x;
	int pos_E;
	int pos_dot;
	for(int i=1;i<x.length();i++){
		if(x[i]=='.'){
			pos_dot= i;
		}
		if(x[i]=='E'){
			pos_E= i;
			break;
		}
	}
	int num=0;
    for(int i=pos_E+2;i<x.length();i++){
    	int temp = x[i]-'0';
    	num+=pow(temp,x.length()-i-1);
    }
    printf("%d\n",num);
    if(x[0]=='-'){
	    cout<<'-';
	}
	if(x[pos_E+1]=='+'){	
    	cout<<x[1];
    	int count=0;
    	for(int i=pos_dot+1;i<pos_E;i++){
    		cout<<x[i];
    		count++;
		}
		for(int i=0;i<num-count;i++){
			cout<<"0";
		}
	}
	else{
		cout<<"0.";
		for(int i=0;i<num-1;i++){
			cout<<"0";
		}
		cout<<x[1];
		for(int i=pos_dot+1;i<pos_E;i++){
			cout<<x[i];
		}
	}
	return 0;
}
