#include <stdio.h>
using namespace std;
int main(){
	int arr[10];
	int N;
	int sum=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(j!=i){
				sum+=arr[i]*10+arr[j];
			}
		}
	}
	printf("%d",sum);
	return 0;
}
