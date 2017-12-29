#include <iostream>
#include <cctype>
using namespace std;
int main(){
	int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[11]={'1' ,'0' ,'X' ,'9', '8', '7', '6' ,'5' ,'4', '3', '2'};
	int N;
	int flag_all=0;
	cin>>N;
	if(N>100){
		return 0;
	}
	for(int i=0;i<N;i++){
        int flag=0;
		string ID;
		cin>>ID;
		for(int j=0;j<17;j++){
			if(!isdigit(ID[j])){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout<<ID<<endl;
			flag_all=1;
			continue;
		}
		else{
			int Z=0;
			for(int j=0;j<17;j++){
				Z+=(ID[j]-'0')*weight[j];
			}
			Z=Z%11;
			if(M[Z]!=ID[17]){
				flag_all=1;
				cout<<ID<<endl;
			}
		}
	}
	if(flag_all==0){
		cout<<"All passed";
	}
	return 0;
}
