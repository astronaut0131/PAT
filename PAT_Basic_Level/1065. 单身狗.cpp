#include <stdio.h>
#include <algorithm>
using namespace std;
int person[100000];
int result[50000];
int peo_pres[10000];
int whe_pres[100000];
int main(){
	fill(whe_pres,whe_pres+100000,0);
	fill(person,person+100000,0);
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		person[a]=b;
		person[b]=a;
	}
	int M;
	scanf("%d",&M);
	int count=0;
	for(int i=0;i<M;i++){
		int x;
		scanf("%d",&x);
		whe_pres[x]=1;
		peo_pres[i]=x;
	}
	for(int i=0;i<M;i++){
		if(whe_pres[person[peo_pres[i]]]==0){
			result[count]=peo_pres[i];
			count++;
		}
	}
	sort(result,result+count);
	printf("%d\n",count);
	for(int i=0;i<count;i++){
		printf("%05d",result[i]);
		if(i!=count-1){
			printf(" ");
		}
	}
	return 0;
}
