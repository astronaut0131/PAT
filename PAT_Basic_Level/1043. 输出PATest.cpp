#include <iostream>
#include <string>
using namespace std;
int main(){
	int P=0,A=0,T=0,e=0,s=0,t=0;
	int count=0;
	string x;
	cin>>x;
	for(int i=0;i<x.length();i++){
		if(x[i]=='P'){
			P++;
			count++;
			continue;
		}
		if(x[i]=='A'){
			A++;
			count++;
			continue;
		}
		if(x[i]=='T'){
			T++;
			count++;
			continue;
		}
		if(x[i]=='e'){
			e++;
			count++;
			continue;
		}
		if(x[i]=='s'){
			s++;
			count++;
			continue;
		}
		if(x[i]=='t'){
			t++;
			count++;
			continue;
		}
	}
	while(count>0){
		if(P!=0){
			cout<<"P";
			P--;
			count--;
		}
		if(A!=0){
			cout<<"A";
			A--;
			count--;
		}
		if(T!=0){
			cout<<"T";
			T--;
			count--;
		}
		if(e!=0){
			cout<<"e";
			e--;
			count--;
		}
		if(s!=0){
			cout<<"s";
			s--;
			count--;
		}
		if(t!=0){
			cout<<"t";
			t--;
			count--;
		}
    }
	return 0;
}
