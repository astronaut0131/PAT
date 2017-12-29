#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int temp =s.length();
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]==' '){
			for(int j=i+1;j<temp;j++){
				cout<<s[j];
			}
			temp = i;
			cout<<" ";
		}
	}
	for(int i=0;i<temp;i++){
		cout<<s[i];
	}
	return 0;
}
