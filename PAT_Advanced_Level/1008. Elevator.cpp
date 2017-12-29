#include <stdio.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int sum=0;
	int pre=0;
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		if(x>pre){
			sum+=(x-pre)*6;
		}
		else{
			sum+=(pre-x)*4;
		}
		sum+=5;
		pre=x;
	}
	printf("%d",sum);
	return 0;
}
