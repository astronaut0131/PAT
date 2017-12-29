#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int low = -1,high = -1;
	int longest = 0;
	for(int i=2;i<=13;i++){
		int temp = 1;
		for(int j=i;j<=13;j++){
			temp*=j;
			if(N%temp == 0 and j-i+1 >longest){
				longest = j-i+1;
				low = i;
				high = j;
			}
		}
	}
	if(high == -1 and low == -1){
		printf("1\n");
		int flag = 0;
		for(int i=2;i<=(int)sqrt(N) + 1;i++){
			if(N%i == 0){
				printf("%d",i);
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf("%d",N);
		}
	}
	else{
		printf("%d\n",longest);
		for(int i=low;i<=high;i++){
			printf("%d",i);
			if(i!=high) printf("*");
		}
	}
	return 0;
}
