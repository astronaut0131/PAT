#include <stdio.h>
using namespace std;
int num[10];
int main(){
	int result[50];
	int sum=0;
	for(int i=0;i<=9;i++){
		scanf("%d",&num[i]);
		sum+=num[i];
	}
	int min=10;
	for(int i=1;i<=9;i++){
		if(num[i]!=0&&i<min){
			min=i;
		}
	}
	num[min]--;
	result[0]=min;
	for(int i=1;i<=sum-1;i++){
		min=10;
		for(int j=0;j<=9;j++){
			if(num[j]!=0&&j<min){
				min=j;
			}
		}
		result[i]=min;
		num[min]--;
	}
	for(int i=0;i<sum;i++){
		printf("%d",result[i]);
	}
	return 0;
}
