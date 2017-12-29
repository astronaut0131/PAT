#include <iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	string u[N],p[N];
	int cnt=0;
	for(int i=0;i<N;i++){
		string user,password;
		cin>>user>>password;
		int flag=0;
		for(int j=0;j<password.length();j++){
			if(password[j]=='1'){
				password[j]='@';
				flag=1;
			}
			else if(password[j]=='0'){
				password[j]='%';
				flag=1;
			}
			else if(password[j]=='l'){
				password[j]='L';
				flag=1;
			}
			else if(password[j]=='O'){
				password[j]='o';
				flag=1;
			}
		}
		if (flag==1){
			u[cnt]=user;
			p[cnt]=password;
			cnt++;
		}
	}
	if(cnt==0){
		if(N>1){
			cout<<"There are "<<N<<" accounts and no account is modified";
		}
		else if(N==1){
			cout<<"There is "<<N<<" account and no account is modified";
		}
	}
	else{
		cout<<cnt<<endl;
		for(int i=0;i<cnt;i++){
			cout<<u[i]<<" "<<p[i]<<endl;
		}
	}
	return 0;
}
