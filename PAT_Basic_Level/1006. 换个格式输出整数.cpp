#include <stdio.h>
using namespace std;
int main(){
	int n;
	int result[3];
	int count=0;
	scanf("%d",&n);
	int temp;
	while(1){
		temp=n%10;
		result[count]=temp;
		count++;
		if(temp==n){
			break;
		}
		n=(n-temp)/10;
	}
	for(int i=count-1;i>=0;i--){
		if(i==2){
			for(int j=0;j<result[i];j++){
				printf("B");
			}
		}
		else if(i==1){
			for(int j=0;j<result[i];j++){
				printf("S");
			}
		}
		else{
			for(int j=1;j<=result[i];j++){
				printf("%d",j);
			}
		}
		
	}
	return 0;
}
