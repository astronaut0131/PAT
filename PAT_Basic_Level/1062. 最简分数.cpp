#include <stdio.h>
#include <vector>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
  int N1,M1,N2,M2,K;
  int flag=0;
  int min,max;
  scanf("%d/%d %d/%d %d",&N1,&M1,&N2,&M2,&K);
  if(N1*M2>N2*M1){
  	swap(N1,N2);
  	swap(M1,M2);
  }
  for(int i=1;;i++){
  	if(i*M1>N1*K&&flag==0){
  		min=i;
  		flag=1;
	}
	if(i*M2>=N2*K){//注意这个=很关键，有一个点如果没这个等号就过不去 
		max=i-1;
		break;
	}
  }
  if(min>=max){
  	return 0;
  }
  flag=0;
  for(int i=min;i<=max;i++){
  	int x=gcd(i,K);
  	if(x==1){
  		if(flag==0){
  			flag=1;
		}
		else{
			printf(" ");
		}
		printf("%d/%d",i,K);
	}
  }
  return 0;
}
