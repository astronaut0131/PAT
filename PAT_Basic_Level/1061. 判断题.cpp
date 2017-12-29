#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int N,M;
	int score[100];
	int answer[100];
	int sum[100];
	fill(sum,sum+100,0);
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d",&score[i]);
	}
	for(int i=0;i<M;i++){
		scanf("%d",&answer[i]);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int x;
			scanf("%d",&x);
			if(x==answer[j]){
				sum[i]+=score[j];
			}
		}
	}
	for(int i=0;i<N;i++){
		printf("%d\n",sum[i]);
	}
	return 0;
}
