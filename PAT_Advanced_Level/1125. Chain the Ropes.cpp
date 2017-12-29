#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmpInc(int a,int b){
	return a<b;
}
int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N);
	double temp = arr[0];
	double sum=0;
	for(int i=1;i<N;i++){
		sum=arr[i]*0.5+temp*0.5;
		temp=sum;
	}
	printf("%d",(int)sum);
	return 0;
}
