#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N);
	float sum=0;
	for(int i=0;i<N;i++){
		if(i==0){
			sum+=arr[0];
		}
		else{
			sum=sum*1.0/2+arr[i]*1.0/2;
		}
	}
	printf("%d",(int)sum);
	return 0;
}
