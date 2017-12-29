#include <stdio.h>
#include <cmath>
using namespace std;
bool IsPrime(int x){
	if(x==1){
		return false;
	}
	else if(x%2==0&&x!=2){
		return false;
	}
	else{
		for(int i=2;i<=sqrt(x);i++){
			if(x%i==0){
				return false;
			}
		}
		return true;
	}
}
int main(){
	int M,N;
	int count=0;
	scanf("%d %d",&M,&N);
	for(int i=1;;i++){
		if(IsPrime(i)){
			count++;
			if(count>=M&&count<=N){
			    printf("%d",i);
			    if((count-M+1)%10==0&&count!=M){
			    	printf("\n");
				}
				else if(count!=N){
					printf(" ");
				}
		    }
		    else if(count>N){
		    	break;
			}

		}
	}
	return 0;
}
