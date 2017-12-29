#include <stdio.h>
using namespace std;
int main(){
	int maybe_null=0,null=0;
	int N,D;
	float e;
	scanf("%d %f %d",&N,&e,&D);
	for(int i=0;i<N;i++){
		int days;
		int cnt=0;
		scanf("%d",&days);
		for(int j=0;j<days;j++){
			float x;
			scanf("%f",&x);
			if(x<e){
				cnt++;
			}
		}
	    if(2*cnt>days){
	    	if(days<=D){
	    		maybe_null++;
			}
			else{
				null++;
			}
		}
	}
	printf("%.1f%% %.1f%%",100*maybe_null*1.0/N,100*null*1.0/N);
	return 0;
}
