#include <stdio.h>
#include <map>
using namespace std;
map <int,float> map1;
map <int,float> map2;
map <int,float> map3;
int main(){
	int K1,K2;
	int max1=-1,max2=-1,max3=-1;
	int cnt=0;
	scanf("%d",&K1);
	for(int i=0;i<K1;i++){
		int exp;
		float coef;
		scanf("%d %f",&exp,&coef);
		map1[exp]+=coef;
		if(exp>max1){
			max1=exp;
		}
	}
	scanf("%d",&K2);
	for(int i=0;i<K2;i++){
		int exp;
		float coef;
		scanf("%d %f",&exp,&coef);
		map2[exp]+=coef;
		if(exp>max2){
			max2=exp;
		}
	}
	for(int i=max1;i>=0;i--){
		if(map1[i]!=0){
			for(int j=max2;j>=0;j--){
				if(map2[j]!=0){
					map3[i+j]+=map1[i]*map2[j];
					if(i+j>max3){
						max3=i+j;
					}
				}
			}
		}
	}
	for(int i=max3;i>=0;i--){
		if(map3[i]!=0){
			cnt++;
		}
	}
	printf("%d",cnt);
	for(int i=max3;i>=0;i--){
		if(map3[i]!=0){
			printf(" %d %.1f",i,map3[i]);
		}
	}
	return 0;
}
