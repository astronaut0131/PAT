#include <stdio.h>
using namespace std;
int main(){
	int M,N,A,B,X;
	scanf("%d %d %d %d %d",&M,&N,&A,&B,&X);
	int G[M][N];
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]>=A&&G[i][j]<=B){
				G[i][j]=X;
			}
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%03d",G[i][j]);
			if(j!=N-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
