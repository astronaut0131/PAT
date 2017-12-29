#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> weight;
const int MAXN = 505;
const int INF = 999999999;
int G[MAXN][MAXN];
bool visit[MAXN];
int dis[MAXN];
int pre[MAXN];
int num[MAXN];
int w[MAXN];
int main(){
	fill(G[0],G[0] + MAXN*MAXN,INF);
	fill(visit,visit+MAXN,false);
	fill(dis,dis+MAXN,INF);
	fill(num,num+MAXN,0);
	fill(w,w+MAXN,0);
	int N,M,S,D;
	scanf("%d %d %d %d",&N,&M,&S,&D);
	weight.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<M;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		scanf("%d",&G[v1][v2]);
		G[v2][v1] = G[v1][v2];
	}
	dis[S] = 0;
	pre[S] = -1;
	num[S] = 1;
	w[S] = weight[S];
	while(1){
		int u=-1,minn = INF;
		for(int i=0;i<N;i++){
			if(not visit[i] and dis[i] < minn){
				minn = dis[i];
				u = i;
			}
		}
		if(u == -1) break;
		visit[u] = true;
		for(int v=0;v<N;v++){
			if(not visit[v] and dis[v] >= dis[u] + G[u][v]){
				if(dis[v] > dis[u] + G[u][v]){
					dis[v] = dis[u] + G[u][v];
					pre[v] = u;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if(dis[v] == dis[u] + G[u][v]){
					num[v] += num[u];
					if(w[v] < w[u] +weight[v]){
						pre[v] = u;
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}
	printf("%d %d\n",num[D],w[D]);
	vector <int> res;
	for(int i=D;i!=-1;i = pre[i]){
		res.push_back(i);
	}
	for(int i=res.size()-1;i>=0;i--){
		printf("%d",res[i]);
		if(i!=0) printf(" ");
	}
	return 0;
}
