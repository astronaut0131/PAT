#include <iostream>
#include <map>
using namespace std;
map<char,int> mapp;
int main(){
	string A,B;
	cin>>A;
	cin>>B;
	int count=0;
	int loss=0;
	for(int i=0;i<A.length();i++){
		mapp[A[i]]++;
		count++;
	}
	for(int i=0;i<B.length();i++){
		if(mapp[B[i]]==0){
			loss++;
		}
		else{
			mapp[B[i]]--;
			count--;
		}
	}
	if(loss>0){
		cout<<"No"<<" "<<loss;
	}
	else{
		cout<<"Yes"<<" "<<count;
	}
	return 0;
}
