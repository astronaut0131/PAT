#include <stdio.h>
using namespace std;
int main(){
	int a1,b1,c1,a2,b2,c2,a3,b3,c3;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	c3=(c2+c1)%29;
	int tempc = (c1+c2)/29;
	b3=(b2+b1+tempc)%17;
	int tempb = (b2+b1+tempc)/17;
	a3=tempb+a1+a2;
	printf("%d.%d.%d",a3,b3,c3);
	return 0;
}
