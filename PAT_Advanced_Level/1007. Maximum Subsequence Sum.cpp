#include <stdio.h>
using namespace std;
int main(){
	int K;
	scanf("%d",&K);
	int arr[K];
	int flag=0;
	for(int i=0;i<K;i++){
		scanf("%d",&arr[i]);
		if(arr[i]>=0){
			flag=1;
		}
	}
	int maxx=-999999;
	int v1,v2;
	for(int i=0;i<K;i++){
		int sum=0;
		for(int j=i;j<K;j++){
			sum+=arr[j];
			if(sum>maxx){
				maxx=sum;
				v1=arr[i];
				v2=arr[j];
			}
		}
	}
	if(flag==0){
		printf("0 %d %d",arr[0],arr[K-1]);
	}
	else{
		printf("%d %d %d",maxx,v1,v2);
	}
	return 0;
}
