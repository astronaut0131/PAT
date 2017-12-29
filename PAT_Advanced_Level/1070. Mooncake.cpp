#include <stdio.h>
#include <algorithm>
using namespace std;
struct mooncake{
    double weight;
    double price;
    double per;
};
bool cmpDec(struct mooncake A,struct mooncake B){
	return A.per>B.per;
}
int main(){
    int N,demand;
    scanf("%d %d",&N,&demand);
    struct mooncake m[N];
    for(int i=0;i<N;i++){
       scanf("%lf",&m[i].weight);
    }
    for(int i=0;i<N;i++){
    	scanf("%lf",&m[i].price);
    	m[i].per = m[i].price/m[i].weight;
    }
    sort(m,m+N,cmpDec);
    double interest=0;
    for(int i=0;i<N;i++){
    	if(demand>m[i].weight){
    		demand-=m[i].weight;
    		interest+=m[i].price;
    	}
    	else{
    		interest+=demand*m[i].per;
    		break;
    	}
    }
    printf("%.2lf",interest);
	return 0;
}
