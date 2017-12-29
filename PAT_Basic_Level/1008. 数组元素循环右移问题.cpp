#include <stdio.h>
using namespace std;
int main(){
	int N,M;
	int a[100],b[100];
	scanf("%d %d",&N,&M);
	if(M>N){
		M=M%N;
	}
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=N-M;i<=N-1;i++){
		b[i-N+M]=a[i];
	}
	for(int i=0;i<N-M;i++){
		b[M+i]=a[i];
	}
	for(int i=0;i<N;i++){
		printf("%d",b[i]);
		if(i!=N-1){
			printf(" ");
		}
	}
	return 0;
}
