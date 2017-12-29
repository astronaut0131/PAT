#include <stdio.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	double arr[N];
	for(int i=0;i<N;i++){
		scanf("%lf",&arr[i]);
	}
	double sum=0;
	for(int i=0;i<N;i++){
		sum+=arr[i]*(N-i)*(i+1);
	}
	printf("%.2lf",sum);
	return 0;
}
