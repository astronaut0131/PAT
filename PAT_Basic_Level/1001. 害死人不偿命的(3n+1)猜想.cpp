#include <stdio.h>
using namespace std;
int main(){
    int n;
    int count = 0;
    scanf("%d",&n);
	while(1){
		if(n==1){
			break;
		}
		if(n%2==0){
			n/=2;
		}
		else{
			n=(3*n+1)/2;
		}
		count++;

	}
	printf("%d",count);
	return 0;
} 
