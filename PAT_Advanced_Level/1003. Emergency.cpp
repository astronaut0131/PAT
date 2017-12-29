#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF=999999;
int main(){
	int N,M,C1,C2;
	scanf("%d %d %d %d",&N,&M,&C1,&C2);
	int weight[N];
	int G[N][N];
	int dis[N];
	int w[N];
	int visit[N];
	int num[N];
	fill(dis,dis+N,INF);
	fill(w,w+N,0);
	fill(visit,visit+N,0);
	fill(num,num+N,0);
	fill(G[0],G[0]+N*N,INF);
	for(int i=0;i<N;i++){
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<M;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		scanf("%d",&G[v1][v2]);
		G[v2][v1]=G[v1][v2];
	}
	dis[C1]=0;
	w[C1]=weight[C1];
	num[C1]=1;
	while(1){
		int u=-1;
		int minn=INF;
		for(int i=0;i<N;i++){
			if(dis[i]<minn&&visit[i]==0){
				minn=dis[i];
				u=i;
			}
		}
		if(u==-1){
			break;
		}
		visit[u]=1;
		for(int v=0;v<N;v++){
			if(G[u][v]!=INF&&visit[v]==0){
				if(G[u][v]+dis[u]<dis[v]){
		    		dis[v]=dis[u]+G[u][v];
		    		num[v]=num[u];
		    		w[v]=w[u]+weight[v];
			    }
			    else if(G[u][v]+dis[u]==dis[v]){
			    	num[v]+=num[u];
			    	if(w[u]+weight[v]>w[v]){
			    		w[v]=w[u]+weight[v];
					}
				}
			}
		}
	}
	printf("%d %d",num[C2],w[C2]);
	return 0;
}
