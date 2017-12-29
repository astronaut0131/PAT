#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int N;
	int p;
	scanf("%d %d",&N,&p);
	long long int arr[N];
	for(int i=0;i<N;i++){
		scanf("%lld",&arr[i]);
	}
	sort(arr,arr+N);
	int max=0;
	for(int i=0;i<N;i++){
		for(int j=i+max;j<N;j++){
			if(arr[j]<=arr[i]*p){
				if(j-i+1>max){
					max=j-i+1;
			    }
			}
			else{
				break;
			}
		}
	}
	printf("%d",max);
	return 0;
}
