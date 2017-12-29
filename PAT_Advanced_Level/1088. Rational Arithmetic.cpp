#include <stdio.h>
#include <cmath>
using namespace std;
long long int gcd(long long int a,long long int b){ 
	a = abs(a);
	b = abs(b);
	if(a<b){
		long long int temp = a;
		a = b;
		b = temp;
	}
	return b==0?a:gcd(b,a%b);
}   
void format_output(long long int a,long long int b){
	long long int temp = gcd(a,b);
	a /= temp;
	b /= temp;
	int flag = 1;
	if((a<0 and b<0) or (a>0 and b>0) or a==0) flag = 0;
	a = abs(a);
	b = abs(b);
	if(flag) printf("(-");
	if(a%b == 0){
		printf("%lld",a/b);
	}
	else if(a>b){
		printf("%lld %lld/%lld",a/b,a%b,b);
	}
	else{
		printf("%lld/%lld",a,b);
	}
	if(flag) printf(")");
}
void sum(long long int a1,long long int b1,long long int a2,long long int b2){
	format_output(a1,b1);
	printf(" + ");
	format_output(a2,b2);
	printf(" = ");
	long long int lcm = b1*b2/gcd(b1,b2);
	format_output(lcm/b1*a1 + lcm/b2*a2,lcm);
	printf("\n");
}
void diff(long long int a1,long long int b1,long long int a2,long long int b2){
	format_output(a1,b1);
	printf(" - ");
	format_output(a2,b2);
	printf(" = ");
	long long int lcm = b1*b2/gcd(b1,b2);
	format_output(lcm/b1*a1 - lcm/b2*a2,lcm);
	printf("\n");
}
void prod(long long int a1,long long int b1,long long int a2,long long int b2){
	format_output(a1,b1);
	printf(" * ");
	format_output(a2,b2);
	printf(" = ");
	format_output(a1*a2,b1*b2);
	printf("\n");
}	
void quot(long long int a1,long long int b1,long long int a2,long long int b2){
	format_output(a1,b1);
	printf(" / ");
	format_output(a2,b2);
	printf(" = ");
	if(a2 == 0){
		printf("Inf");
	}
	else{
		format_output(a1*b2,b1*a2);
	}
	printf("\n");
}
int main(){
	long long int a1,b1,a2,b2;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	long long int temp1 = gcd(a1,b1);
	
	long long int temp2 = gcd(a2,b2);
	
	a1 /= temp1;
	b1 /= temp1;
	a2 /= temp2;
	b2 /= temp2;
	sum(a1,b1,a2,b2);
	diff(a1,b1,a2,b2);
	prod(a1,b1,a2,b2);
	quot(a1,b1,a2,b2);
	return 0;
}
