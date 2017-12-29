#include <stdio.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	long long int a,b,c;
	for(int i=0;i<N;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("Case #%d: ",i+1);
		long long int sum = a+b;
		if(a>0 and b>0 and sum<=0){
			printf("true\n");
		}
		else if(a<0 and b<0 and sum>=0){
			printf("false\n");
		}
		else{
			if(sum>c){
				printf("true\n");
			}
			else{
				printf("false\n");
			}
		}
		
	}
	return 0;
}
