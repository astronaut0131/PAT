#include <stdio.h>
using namespace std;
void toMars(int x){
	int a = x/13;
	if(0<=a&&a<=9){
		printf("%d",a);
	}
	else if(a<=12){
		printf("%c",a-10+'A');
	}
	int b = x%13;
	if(b>=0&&b<=9){
		printf("%d",b);
	}
	else if(b<=12){
		printf("%c",b-10+'A');
	}
}
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("#");
	toMars(a);
	toMars(b);
	toMars(c);
	return 0;
}
