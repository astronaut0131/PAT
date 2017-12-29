#include <stdio.h>
using namespace std;
int main(){
	long int a,b,c;
	int n;
	bool result[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%ld%ld%ld",&a,&b,&c);
		if((a+b)>c){
			result[i]=true;
		}
		else{
			result[i]=false;
		}
	}
	for(int i=0;i<n;i++){
		if(result[i]){
			printf("Case #%d: true\n",i+1);
		}
		else{
			printf("Case #%d: false\n",i+1);
		}
	}
	return 0;
}
