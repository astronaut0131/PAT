#include <iostream>
#include <string>
using namespace std;
int main(){
	string A;
	int B,R,Q[1000];
	cin>>A>>B;
	int cnt1=0,cnt2=0;
	while(1){
		int temp=A[cnt1]-'0';
		if(temp<B){
			if(cnt1==A.length()-1){
				Q[cnt2]=temp/B;
				cnt2++;
				R=temp%B;
				break;
			}
			temp=temp*10+A[cnt1+1]-'0';
			cnt1++;
		}
		Q[cnt2]=temp/B;
		cnt2++;
		A[cnt1]=(temp%B)+'0';
		if(cnt1==A.length()-1){
			R=temp%B;
			break;
		}
	}
	for(int i=0;i<cnt2;i++){
		cout<<Q[i];
	}
	cout<<" "<<R;
	return 0;
}
