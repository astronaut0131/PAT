#include <iostream>
using namespace std;
int main(){
	string s;
	int n,cnt=0;
	cin>>s>>n;
	cin.ignore();
	while(1){
		string x;
		getline(cin,x);
		if(x=="#"){
			break;
		}
		if(x==s){
			cout<<"Welcome in\n";
			break;
		}
		else{
			cout<<"Wrong password: "<<x<<endl;
			cnt++;
		}
		if(cnt==n){
			cout<<"Account locked\n";
			break;
		}
	}
	return 0;
}
