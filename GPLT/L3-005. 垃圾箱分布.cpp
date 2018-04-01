#include <stdio.h>
#include <iostream>
#include <sstream> 
using namespace std;
const int INF = 999999999;
const int MAXN = 1100;
int G[MAXN][MAXN];
bool visit[MAXN];
int dis[MAXN];
int string2int(string x){
	int res;
	stringstream s;
	s<<x;
	s>>res;
	return res;
}
int main(){
	fill(G[0],G[0] + MAXN*MAXN,INF);
	int N,M,K,D;
	scanf("%d %d %d %d",&N,&M,&K,&D);
	for(int i=0;i<K;i++){
		getchar();
		int a,b;
		string v1,v2;
		cin>>v1>>v2;
		if(v1[0] == 'G') a = string2int(v1.substr(1,v1.length()-1)) + N;
		else a = string2int(v1);
		if(v2[0] == 'G') b = string2int(v2.substr(1,v2.length()-1)) + N;
		else b = string2int(v2);
		scanf("%d",&G[a][b]);
		G[b][a] = G[a][b];
	}
	int max_dis = -1;
	int sum_dis = -1;
	int index = -1;
	for(int i=N+1;i<=N+M;i++){
		fill(visit,visit+MAXN,false);
		fill(dis,dis+MAXN,INF);
		dis[i] = 0;
		while(1){
			int u = -1,min = INF;
			for(int j=1;j<=N+M;j++){
				if(not visit[j] and dis[j] < min){
					min = dis[j];
					u = j;
				}
			}
			if(u == -1) break;
			visit[u] = true;
			for(int v=1;v<=N+M;v++){
				if(not visit[v] and dis[v] > dis[u] + G[u][v]){
					dis[v] = dis[u] + G[u][v];
				}
			}
		}	
		int sum = 0,min_dis = INF,flag = 0;
			for(int j=1;j<=N;j++){
				if(dis[j] > D){
					flag = 1;
					break;
				}
				if(dis[j] < min_dis) min_dis = dis[j];
				sum += dis[j];
			}
			if(not flag and (min_dis > max_dis or (min_dis == max_dis and sum < sum_dis))){
				index = i;
				max_dis = min_dis;
				sum_dis = sum;
			}
	}
	if(index == -1) printf("No Solution");
	else printf("G%d\n%.1f %.1f",index-N,max_dis*1.0,sum_dis*1.0/N);
	return 0;
}
