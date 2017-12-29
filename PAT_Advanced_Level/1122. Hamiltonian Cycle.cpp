#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int G[205][205];
int visit[205];
int main(){
	fill(G[0],G[0]+205*205,0);
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		G[v1][v2] = G[v2][v1] = 1;
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		fill(visit,visit+205,0);
		int num;
		int S;
		vector <int> v;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			int x;
			scanf("%d",&x);
			v.push_back(x);
			if(j==0){
				S = x;
			}
		}
		if(v[0] != v[v.size()-1]){
			printf("NO\n");
			continue;
		}
		int flag = 0;
		for(int j=0;j<v.size()-1;j++){
			visit[v[j]]++;
			if(G[v[j]][v[j+1]] != 1){
				flag = 1;
			}
		}
		for(int j=1;j<=N;j++){
			if(visit[j]!=1){
				flag = 1;
				break;
			}
		}
		if(flag){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}
