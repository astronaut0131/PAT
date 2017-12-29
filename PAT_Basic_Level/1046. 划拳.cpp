#include <stdio.h>
using namespace std;
int main(){
	int cnt_a=0,cnt_b=0;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(b==a+c&&d!=a+c){
			cnt_b++;
		}
		if(d==a+c&&b!=a+c){
			cnt_a++;
		}
	}
	printf("%d %d",cnt_a,cnt_b);
	return 0;
}
