#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	char sa[11],sb[11];
	char DA,DB;
	int sum1=0,sum2=0;
	int a=0,b=0;
	scanf("%s %c %s %c",sa,&DA,sb,&DB);
	for(int i=0;i<strlen(sa);i++){
		if(sa[i]==DA){
			sum1++;
		}
	}
	for(int i=0;i<strlen(sb);i++){
		if(sb[i]==DB){
			sum2++;
		}
	}
	for(int i=0;i<sum1;i++){
		a+=(DA-'0')*pow(10,i);
	}
	for(int i=0;i<sum2;i++){
		b+=(DB-'0')*pow(10,i);
	}
	printf("%d",a+b);
	return 0;
}
