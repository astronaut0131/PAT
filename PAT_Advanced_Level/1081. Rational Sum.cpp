#include <stdio.h>
#include <cmath>
using namespace std;
int gcd(long long int a,long long int b){
	return b==0?abs(a):gcd(b,a%b);
}
int main(){
	int N;
	scanf("%d",&N);
	long long int nume=0,deno=0;
	for(int i=0;i<N;i++){
		long long int temp1,temp2;
		scanf("%lld/%lld",&temp1,&temp2);
		if(i == 0){
			nume = temp1;
			deno = temp2;
		}
		else{
			int lcm = deno*temp2/(deno>temp2?gcd(deno,temp2):gcd(temp2,deno));
			nume = lcm/deno*nume + lcm/temp2*temp1;
			deno = lcm;
		}
		int temp = nume>deno?gcd(nume,deno):gcd(deno,nume);
		nume /= temp;
		deno /= temp;
	} 
	if(nume % deno == 0){
		printf("%d",nume/deno);
	}
	else if(nume > deno){
		printf("%d %d/%d",nume/deno,nume%deno,deno);
	}
	else{
		printf("%d/%d",nume,deno);
	}
	return 0;
}
