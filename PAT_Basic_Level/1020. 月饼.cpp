#include <stdio.h>
#include <algorithm>
using namespace std;
struct mooncake{
	float storage;
	float total_price;
	float per_price;
}my_mooncake[1005];
bool comp(mooncake a,mooncake b){
	return a.per_price>b.per_price;
}
int main(){
    int N,D;
    float income=0;
    scanf("%d %d",&N,&D);
    for(int i=0;i<N;i++){
    	scanf("%f",&my_mooncake[i].storage);
	}
	for(int i=0;i<N;i++){
		scanf("%f",&my_mooncake[i].total_price);
		my_mooncake[i].per_price=my_mooncake[i].total_price/my_mooncake[i].storage;
	}
	sort(my_mooncake,my_mooncake+N,comp);
	for(int i=0;i<N;i++){
		if(D-my_mooncake[i].storage>0){
			D-=my_mooncake[i].storage;
			income+=my_mooncake[i].total_price;
		}
		else{
			income+=my_mooncake[i].per_price*D;
			break;
		}
	}
	printf("%.2f",income);
	return 0;
}
