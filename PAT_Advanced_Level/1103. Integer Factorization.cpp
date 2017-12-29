#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
int N,K,P;
vector <int> v;
void init(){
	for(int i=0;;i++){
		if(pow(i,P) > N) break;
		else v.push_back(pow(i,P));
	}
}
vector <int> res,resTemp;
int facSumMax = -1;
void dfs(int index,int tempSum,int facSum,int tempK){
	if(index <=0) return;
	if(tempSum > N||tempK > K) return;
	else if(tempSum == N and tempK == K){
		if(facSum > facSumMax){
			facSumMax = facSum;
			res = resTemp;
		}
		return;
	}
	else{
		resTemp.push_back(index);
		dfs(index,tempSum + v[index],facSum + index,tempK + 1);
		resTemp.pop_back();
		dfs(index-1,tempSum,facSum,tempK);
	}
}
int main(){
	scanf("%d %d %d",&N,&K,&P);
	init();
	dfs(v.size() - 1,0,0,0);
	if(facSumMax == -1){
		printf("Impossible");
	}
	else{
		printf("%d = ",N);
		for(int i=0;i<res.size();i++){
			if(i!=0) printf(" + ");
			printf("%d^%d",res[i],P);
		}
	}
	return 0;
}
