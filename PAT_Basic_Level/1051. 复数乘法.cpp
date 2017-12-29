#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	double R1,P1,R2,P2;
	double A1,B1,A2,B2;
	scanf("%lf %lf %lf %lf",&R1,&P1,&R2,&P2);
	A1=R1*cos(P1);
	B1=R1*sin(P1);
	A2=R2*cos(P2);
	B2=R2*sin(P2);
	double A,B;
	A=A1*A2-B1*B2;
	B=A1*B2+A2*B1;
	if(A>-0.005&&A<0){
		printf("0.00");
	}
	else{
		printf("%.2lf",A);
	}
	if(B>=0){
		printf("+%.2lfi",B);
	}
	else if(B>-0.005&&B<0){
		printf("+0.00i");
	}
	else{
		printf("%.2lfi",B);
	}
	return 0;
}
