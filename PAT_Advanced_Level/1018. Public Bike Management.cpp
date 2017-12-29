#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAXN = 510;
const int INF = 999999999;
vector <int> weight;
map <int,vector <int> > pre;
int G[MAXN][MAXN];
bool visit[MAXN];
int dis[MAXN];
int minNeed = INF,minBack = INF;
vector <int> path,temppath;
void dfs(int v){
	if(v == 0){
		int back = 0,need = 0;
		temppath.push_back(0);
		for(int i=temppath.size() - 1;i>=0;i--){
			int id = temppath[i];
			if(weight[id] > 0){
				back += weight[id];
			}
			else{
				if(back > -1*weight[id]){
					back +=weight[id];
				}
				else{
					need += (-1*weight[id] - back);
					back = 0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if(need == minNeed){
			if(back < minBack){
				minBack = back;
				path.clear();
				path = temppath;
			}
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}
int main(){
	fill(G[0],G[0]+MAXN*MAXN,INF);
	int cmax,N,sp,M;
	scanf("%d %d %d %d",&cmax,&N,&sp,&M);
	weight.resize(N+1);
	for(int i=1;i<=N;i++){
		int temp;
		scanf("%d",&temp);
		weight[i] = temp - cmax/2;
	}
	for(int i=0;i<M;i++){
		int v1,v2,len;
		scanf("%d %d",&v1,&v2);
		scanf("%d",&G[v1][v2]);
		G[v2][v1] = G[v1][v2];
	}
	fill(dis,dis+MAXN,INF);
	fill(visit,visit+MAXN,false);
	dis[0] = 0;
	while(1){
		int u = -1,minn = INF;
		for(int i=0;i<=N;i++){
			if(not visit[i] and dis[i]< minn){
				minn = dis[i];
				u = i;
			}
		}
		if(u == -1) break;
		visit[u] = true;
		for(int v=0;v<=N;v++){
			if(not visit[v] and dis[v] >= dis[u] + G[u][v]){
				if(dis[v] == dis[u] + G[u][v]){
					pre[v].push_back(u);
				}
				else{
					dis[v] = dis[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(sp);
	printf("%d 0",minNeed);
	for(int i=path.size()-2;i>=0;i--){
		printf("->%d",path[i]);
	}
	printf(" %d",minBack);
	return 0;
}
