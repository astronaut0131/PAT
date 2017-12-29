#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
int index[10000];
bool IsPrimer(int index){
	for(int i=2;i<=sqrt(index);i++){
		if(index%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	fill(index,index+10000,-1);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int temp;
		scanf("%d",&temp);
		index[temp]=i;
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int x;
		scanf("%d",&x);
		if(index[x]==1){
			printf("%04d: Mystery Award\n",x);
			index[x]=-2;
		}
		else if(index[x]>0&&IsPrimer(index[x])){
			printf("%04d: Minion\n",x);
			index[x]=-2;
		}
		else if(index[x]>0){
			printf("%04d: Chocolate\n",x);
			index[x]=-2;
		}
		else if(index[x]==-1){
			printf("%04d: Are you kidding?\n",x);
		}
		else{
			printf("%04d: Checked\n",x);
		}
	}
	return 0;
}
