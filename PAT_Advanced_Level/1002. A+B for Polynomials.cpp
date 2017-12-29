#include <stdio.h>
#include <map> 
using namespace std;
map <int,float> mapp;
int main(){
	int maxx;
	int K1,K2;
	scanf("%d",&K1);
    for(int i=0;i<K1;i++){
    	int a;
    	float b;
    	scanf("%d %f",&a,&b);
    	mapp[a]+=b;
    	if(a>maxx){
    		maxx=a;
		}
	}
	scanf("%d",&K2);
	for(int i=0;i<K2;i++){
		int a;
		float b;
		scanf("%d %f",&a,&b);
		mapp[a]+=b;
		if(a>maxx){
			maxx=a;
		}
	}
	int cnt=0;
	for(int i=maxx;i>=0;i--){
		if(mapp[i]!=0){
			cnt++;
		}
	}
	printf("%d",cnt);
	for(int i=maxx;i>=0;i--){
		if(mapp[i]!=0){
			printf(" %d %.1f",i,mapp[i]);
		}
	}
	return 0;
}
