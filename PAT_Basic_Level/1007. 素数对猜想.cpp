#include <stdio.h>
#include <cmath>
using namespace std;
int Prime[100000];
bool IsPrime(int x){
	if(x%2==0){
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
int CalPrime(int n){
	int sum = 0;
	int count = 0;
	for(int i=2;i<=n;i++){
		if(IsPrime(i)){
			Prime[count]=i;
			count++;
		}
	}
	for(int i=0;i<count-1;i++){
		if(Prime[i+1]-Prime[i]==2){
			sum++;
		}
	}
	return sum;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",CalPrime(n));
	return 0;
}
