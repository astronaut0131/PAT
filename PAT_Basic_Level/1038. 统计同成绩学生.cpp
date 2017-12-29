#include <stdio.h>
#include <algorithm>
using namespace std;
int num[101];
int main(){
	fill(num,num+101,0);
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int x;
		scanf("%d",&x);
		printf("%d",num[x]);
		if(i!=K-1){
			printf(" ");
		}
	}
	return 0;
}
