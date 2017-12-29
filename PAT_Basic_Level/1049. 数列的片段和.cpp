#include <stdio.h>
using namespace std;
double Arr[100005];
int main(){
	double sum=0;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lf",&Arr[i]);
		sum+=Arr[i]*(N-i)*(i+1);
	}
	printf("%.2lf",sum);
	return 0;
}
