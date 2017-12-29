#include <stdio.h>
using namespace std;
int main() {
	int result1[100],result2[100];
	int cnt=0;
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		if(b==0) break;
		result1[cnt]=a*b;
		result2[cnt]=b-1;
		cnt++;
	}
	if(cnt==0){
		printf("0 0");
	}
	for(int i=0;i<cnt;i++){
		printf("%d %d",result1[i],result2[i]);
		if(i!=cnt-1){
			printf(" ");
		}
	}
    return 0;
}
