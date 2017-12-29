#include <stdio.h>
using namespace std;
int main(){
	int c1,c2;
	int sec=0,min=0,hour=0;
	scanf("%d %d",&c1,&c2);
	if((c2-c1)*1.0/100-(c2-c1)/100>=0.5){
		sec=(c2-c1)/100+1;
	}
	else{
		sec=(c2-c1)/100;
	}
	if(sec/60>=1){
		min=sec/60;
		sec=sec%60;
	}
	if(min/60>=1){
		hour=min/60;
		min=min%60;
	}
	printf("%02d:%02d:%02d",hour,min,sec);
	return 0;
}
