#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	long int N,P;
	scanf("%ld %ld",&N,&P);
	long int Arr[N];
	for(int i=0;i<N;i++){
		scanf("%ld",&Arr[i]);
	}
	sort(Arr,Arr+N);
	int max=0;
    for(int i=0;i<N;i++){
    	for(int j=i+max;j<N;j++){
    		if(Arr[j]<=Arr[i]*P){ //×¢ÒâÏà³ËÒç³ö 
    			if(j-i+1>max){
    				max=j-i+1;
				}
			}else{
				break;
			}
		}
	}
	printf("%d",max);
	return 0;
}
