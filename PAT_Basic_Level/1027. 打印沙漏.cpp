#include <stdio.h>
using namespace std;
int main(){
	int n;
	char ch;
	int sum=0;
	int max,rest;
	scanf("%d %c",&n,&ch);
	for(int i=1;;i+=2){
		sum+=2*i;
		if(sum-1>n){
			max=i-2;
			rest=n-(sum-1-2*i);
			break;
		}
	}
	for(int i=0;i<max;i++){
		if(i<=max/2){
			for(int j=0;j<i;j++){
				printf(" ");
			}
			for(int j=0;j<max-2*i;j++){
				printf("%c",ch);
			}
			printf("\n");
		}
		else{
			for(int j=0;j<max-1-i;j++){
				printf(" ");
			}
			for(int j=0;j<2*(i-max/2)+1;j++){
				printf("%c",ch);
			}
			printf("\n");
		}
	}
	printf("%d",rest);
	return 0;
}
