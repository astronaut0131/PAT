#include <stdio.h>
#include <algorithm>
using namespace std;
int G[1005][1005];
int N,M,K;
bool visit[1005];
void dfs(int x){
	visit[x]=true;
	for(int i=1;i<=N;i++){
		if(visit[i]==false&&G[x][i]==1){
			dfs(i);
		}
	}
}
int main(){
	scanf("%d %d %d",&N,&M,&K);
	fill(G[0],G[0]+1005*1005,0);
	for(int i=0;i<M;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
        G[v1][v2]=G[v2][v1]=1;
	}
	for(int i=0;i<K;i++){
		int x;
		scanf("%d",&x);
		fill(visit,visit+1005,false);
		visit[x]=true;
		int cnt=0;
		for(int j=1;j<=N;j++){
			if(visit[j]==false){
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
