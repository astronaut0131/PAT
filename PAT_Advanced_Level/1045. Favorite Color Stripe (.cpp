#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	int K,N;
	scanf("%d %d",&K,&N);
	int favorite[N];
	vector <bool> like;
	like.resize(N+1);
	for(int i=0;i<N;i++){
		scanf("%d",&favorite[i]);
		like[favorite[i]] = true;
	}
	int M;
	scanf("%d",&M);
	vector <int> stripe;
	for(int i=0;i<M;i++){
		int temp;
		scanf("%d",&temp);
		if(like[temp]) stripe.push_back(temp);
	}
	for(int i=0;i<stripe.size();i++){
		printf("%d ",stripe[i]);
	}
	return 0;
}
