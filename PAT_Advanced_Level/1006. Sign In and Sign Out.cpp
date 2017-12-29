#include <iostream>
#include <algorithm>
using namespace std;
struct employee{
	string ID;
	int Sign_in[3];
	int Sign_out[3];
};
bool FindMin(struct employee A,struct employee B){
	if(A.Sign_in[0]!=B.Sign_in[0]){
		return A.Sign_in[0]<B.Sign_in[0];
	}
	else{
		if(A.Sign_in[1]!=B.Sign_in[1]){
			return A.Sign_in[1]<B.Sign_in[1];
		}
		else{
			return A.Sign_in[2]<B.Sign_in[2];
		}
	}
}
bool FindMax(struct employee A,struct employee B){
	if(A.Sign_out[0]!=B.Sign_out[0]){
		return A.Sign_out[0]>B.Sign_out[0];
	}
	else{
		if(A.Sign_out[1]!=B.Sign_out[1]){
			return A.Sign_out[1]>B.Sign_out[1];
		}
		else{
			return A.Sign_out[2]>B.Sign_out[2];
		}
	}
}
int main(){
	int N;
	cin>>N;
	struct employee x[N];
	char m;
	for(int i=0;i<N;i++){
		cin>>x[i].ID>>x[i].Sign_in[0]>>m>>x[i].Sign_in[1]>>m>>x[i].Sign_in[2]>>x[i].Sign_out[0]>>m>>x[i].Sign_out[1]>>m>>x[i].Sign_out[2];
	}
	sort(x,x+N,FindMin);
	cout<<x[0].ID<<" ";
	sort(x,x+N,FindMax);
	cout<<x[0].ID;
	return 0;
}
