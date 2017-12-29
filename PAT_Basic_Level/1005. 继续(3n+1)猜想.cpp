#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[105];
int n;
bool cmpDec(int a,int b){
	return a>b;
}
void Callatz(int x){
	while(1){
		if(x%2==0){
			x/=2;
		}
		else{
			x=(3*x+1)/2;
		}
		if(x==1){
			return ;
		}
        for(int i=0;i<n;i++){
            if(arr[i]==x){
            	arr[i]=-1;
			}
		}
	}
}
int main(){
    int result[105];
    int count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,cmpDec);
	for(int i=0;i<n;i++){
		if(arr[i]!=-1){
			Callatz(arr[i]);
		}
	}
	for(int i=0;i<n;i++){
	    if(arr[i]!=-1){
	    	result[count]=arr[i];
	    	count++;
		}
	}
	for(int i=0;i<count;i++){
		printf("%d",result[i]);
		if(i!=count-1){
			printf(" ");
		}
	}
	return 0;
}
