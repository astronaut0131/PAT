#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 9999999;
vector <int> v;
int main(){
	int N,M,S,D;
	scanf("%d %d %d %d",&N,&M,&S,&D);
	int G[N][N];
	int weight[N][N];
	int pre[N];
	int dis[N];
	int w[N];
	bool visit[N];
	fill(G[0],G[0]+N*N,INF);
	fill(weight[0],weight[0]+N*N,INF);
	fill(dis,dis+N,INF);
	fill(visit,visit+N,false);
	fill(w,w+N,0);
	for(int i=0;i<N;i++){
		pre[i]=i;
	}
	for(int i=0;i<M;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		scanf("%d %d",&G[v1][v2],&weight[v1][v2]);
		G[v2][v1]=G[v1][v2];
		weight[v2][v1]=weight[v1][v2];
	}
	dis[S]=0;
	w[S]=0;
	while(1){
		int u=-1,minn=INF;
		for(int i=0;i<N;i++){
			if(visit[i]==false&&dis[i]<minn){
				minn=dis[i];
				u=i;
			}
		}
		if(u==-1){
			break;
		}
		visit[u]=true;
		for(int v=0;v<N;v++){
			if(visit[v]==false&&G[u][v]!=INF){
				if(G[u][v]+dis[u]<dis[v]){
					dis[v]=dis[u]+G[u][v];
					pre[v]=u;
					w[v]=w[u]+weight[u][v];
				}
				else if(G[u][v]+dis[u]==dis[v]){
					if(w[u]+weight[u][v]<w[v]){
						w[v]=w[u]+weight[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
	for(int i=D;i!=S;i=pre[i]){
		v.push_back(i);
	}
	printf("%d",S);
	for(int i=v.size()-1;i>=0;i--){
		printf(" %d",v[i]);
	}
	printf(" %d %d",dis[D],w[D]);
	return 0;
}
