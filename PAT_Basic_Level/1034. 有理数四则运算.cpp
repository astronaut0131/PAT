#include <stdio.h>
#include <cmath>
using namespace std;
int gcd(long long int a,long long int b){
	return b==0?a:gcd(b,a%b);
}
void put(long long int A,long long int B){
	if(A==0){
		printf("0");
		return;
	}
	if(A>=B){
		long long int temp=A/B;
		if(A%B==0){
			printf("%lld",A/B);
		}
		else{
			printf("%lld %lld/%lld",temp,A-temp*B,B);
		}
	}
	else{
		printf("%lld/%lld",A,B);
	}
}
void change(long long int A,long long int B){
	int M=gcd(A,B);
    if(M!=1){
    	A=A/M;
    	B=B/M;
	}
	if(A<0^B<0){
		printf("(-");
		put(abs(A),abs(B));
		printf(")");
	}
	else{
		put(A,B);
	}
}
void plus(long long int A,long long int B,long long int C,long long int D){
    change(A,B);
    printf(" + ");
    change(C,D);
    printf(" = ");
    change(A*D+C*B,B*D);
    puts("");
}
void minus(long long int A,long long int B,long long int C,long long int D){
    change(A,B);
    printf(" - ");
    change(C,D);
    printf(" = ");
    change(A*D-C*B,B*D);
    puts("");
}
void multi(long long int A,long long int B,long long int C,long long int D){
    change(A,B);
    printf(" * ");
    change(C,D);
    printf(" = ");
    change(A*C,B*D);
    puts("");
}
void divide(long long int A,long long int B,long long int C,long long int D){
    change(A,B);
    printf(" / ");
    change(C,D);
    printf(" = ");
    if(C==0){
    	printf("Inf");
	}
	else{
		change(A*D,B*C);
	}
	puts("");
}
int main(){
    long long int A1,B1,A2,B2,M1,M2;
    scanf("%lld/%lld %lld/%lld",&A1,&B1,&A2,&B2);
    plus(A1,B1,A2,B2);
    minus(A1,B1,A2,B2);
    multi(A1,B1,A2,B2);
    divide(A1,B1,A2,B2);
	return 0;
}
