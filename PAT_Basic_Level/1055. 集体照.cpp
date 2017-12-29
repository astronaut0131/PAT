#include <iostream>
#include <algorithm>
using namespace std;
struct student{
	string name;
	int height;
};
bool cmpInc(struct student A,struct student B){
	if(A.height!=B.height){
		return A.height>B.height;
	}
	else{
		return A.name<B.name;
	}
}
int main(){
	int N,K,m;
	cin>>N>>K;
	int remainder = N%K;
	int G[remainder][remainder];
	struct student s[N];
	for(int i=0;i<N;i++){
		cin>>s[i].name>>s[i].height;
	}
	sort(s,s+N,cmpInc);
	int t=0;
	int row = K;
	while(row){
		if(row==K){
			m=N-N/K*(K-1);
		}
		else{
			m=N/K;
		}
		string x[m];
		x[m/2]=s[t].name;
		int j=m/2-1;
		for(int i=t+1;i<t+m;i+=2){
			x[j--]=s[i].name;
		}
		j=m/2+1;
		for(int i=t+2;i<t+m;i+=2){
			x[j++]=s[i].name;
		}
		for(int i=0;i<m;i++){
			cout<<x[i];
			if(i!=m-1){
				cout<<" ";
			}
			else{
				cout<<endl;
			}
		}
		t+=m;
		row--;
	}
	return 0;
}
