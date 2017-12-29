#include <iostream>
using namespace std;
int main(){
	string x;
	cin>>x;
	int u=-1,v;
	for(int i=0;i<x.length();i++){
		for(int j=i;j<x.length();j++){
			if(2*i+j==x.length()+2){
				if(i>u){
					u=i;
					v=j;
				}
			}
		}
	}
	for(int i=0;i<u-1;i++){
		cout<<x[i];
		for(int j=0;j<v-2;j++){
			cout<<" ";
		}
		cout<<x[x.length()-i-1]<<endl;
	}
	for(int i=u-1;i<u+v-1;i++){
		cout<<x[i];
	}
	return 0;
}
