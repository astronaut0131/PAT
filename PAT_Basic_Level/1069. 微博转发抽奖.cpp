#include <map>
#include <iostream>
using namespace std;
map <string,int> mapp;
int main(){
	int M,N,S;
	int flag=0;
	scanf("%d %d %d",&M,&N,&S);
	for(int i=1;i<=M;i++){
		string x;
		cin>>x;
		if(mapp[x]==1){
			S=S+1;
		}
		if(i==S){
			cout<<x<<endl;
			mapp[x]=1;
			flag=1;
			S=S+N;
		}
	}
	if(flag==0){
		cout<<"Keep going..."<<endl;
	}
	return 0;
}
