#include <stdio.h>
using namespace std;
int main(){
	int n;
	int temp;
	char ch;
	scanf("%d %c",&n,&ch);
	if(n*1.0/2-(n/2)>=0.5){
		temp=(n/2)+1;
	}
	else{
		temp=n/2;
	}
	for(int i=1;i<=temp;i++){
		for(int j=1;j<=n;j++){
			if(i==temp||i==1||j==1||j==n){
				printf("%c",ch);
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
