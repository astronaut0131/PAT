#include <stdio.h>
using namespace std;
int main(){
	int A1,B1,C1,A2,B2,C2;
	int sum1,sum2,sum;
	int R1,R2,R3;
	scanf("%d.%d.%d %d.%d.%d",&A1,&B1,&C1,&A2,&B2,&C2);
	sum1=A1*17*29+B1*29+C1;
	sum2=A2*17*29+B2*29+C2;
	if(sum1>sum2){
		sum=sum1-sum2;
		R2=sum/29;
		R3=sum%29;
		R1=R2/17;
		R2=R2%17;
		printf("-%d.%d.%d",R1,R2,R3);
	}
	else{
		sum=sum2-sum1;
		R2=sum/29;
		R3=sum%29;
		R1=R2/17;
		R2=R2%17;
		printf("%d.%d.%d",R1,R2,R3);
	}
	return 0;
}
