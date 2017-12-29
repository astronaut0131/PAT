#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 99999999;
const int MAXN = 505;
int G[MAXN][MAXN];
int Time[MAXN][MAXN];
int dis[MAXN];
int t[MAXN];
int num[MAXN];
bool visit[MAXN];
int path1[MAXN];
int path2[MAXN];
vector <int> p1;
vector <int> p2;
int main(){
	fill(G[0],G[0]+MAXN*MAXN,INF);
	fill(Time[0],Time[0]+MAXN*MAXN,INF);
	fill(visit,visit+MAXN,false);
	fill(dis,dis+MAXN,INF);
	fill(t,t+MAXN,INF);
	int N,M,S,D;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b,c,d,e;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		if(c == 1){
			G[a][b] = d;
			Time[a][b] = e;
		}
		else{
			G[a][b] = G[b][a] = d;
			Time[a][b] = Time[b][a] = e;
		}
	}
	scanf("%d %d",&S,&D);
	for(int i=0;i<N;i++){
		if(G[S][i] != INF){
			dis[i] = G[S][i];
			t[i] = Time[S][i];
			path1[i] = S;
		} 
	}
	visit[S] = true;
	while(1){
		int u=-1,min = INF;
		for(int i=0;i<N;i++){
			if(not visit[i] and dis[i] < min){
				min = dis[i];
				u = i;
			}
		}
		if(u==-1){
			break;
		}
		visit[u] = true;
		for(int v = 0;v<N;v++){
			if(not visit[v]){
				if(dis[v] > dis[u] + G[u][v]){
					dis[v] = dis[u] + G[u][v];
					t[v] = t[u] + Time[u][v];
					path1[v] = u;
				}
				else if(dis[v] == dis[u] + G[u][v] and t[v] > t[u]+Time[u][v]){
					t[v] = t[u] + Time[u][v];
					path1[v] = u;
				}
			}
		}
	}
	for(int i = D;i!=S;i = path1[i]) p1.push_back(i);
	p1.push_back(S);
	fill(t,t+MAXN,INF);
	fill(num,num+MAXN,0);
	fill(visit,visit+MAXN,false);
	for(int i=0;i<N;i++){
		if(Time[S][i] != INF){
			t[i] = Time[S][i];
			num[i] = 1;
			path2[i] = S;
		}
	}
	while(1){
		int u=-1,min = INF;
		for(int i=0;i<N;i++){
			if(not visit[i] and t[i] < min){
				min = t[i];
				u = i;
			}
		}
		if(u==-1){
			break;
		}
		visit[u] = true;
		for(int v=0;v<N;v++){
			if(not visit[v]){
				if(t[v] > t[u] + Time[u][v]){
					t[v] = t[u] + Time[u][v];
					num[v] = num[u] + 1;
					path2[v] = u;
				}
				else if(t[v] == t[u] + Time[u][v] and num[v] > num[u] + 1){
					num[v] = num[u] + 1;
					path2[v] = u;
				}
			}
		}
	}
	for(int i=D;i!=S;i = path2[i]) p2.push_back(i);
	p2.push_back(S);
	int same = 1;
	if(p2.size() != p1.size()){
		same = 0;
	}
	else{
		for(int i=0;i<p1.size();i++){
			if(p1[i] != p2[i]){
				same = 0;
				break;
			}
		}
	}
	if(same){
		printf("Distance = %d; Time = %d: ",dis[D],t[D]);
		for(int i=p1.size()-1;i>=0;i--){
			printf("%d",p1[i]);
			if(i!=0) printf(" -> ");
		}
	}
	else{
		printf("Distance = %d: ",dis[D]);
		for(int i=p1.size()-1;i>=0;i--){
			printf("%d",p1[i]);
			if(i!=0) printf(" -> ");
			else printf("\n");
		}
		printf("Time = %d: ",t[D]);
		for(int i=p2.size()-1;i>=0;i--){
			printf("%d",p2[i]);
			if(i!=0) printf(" -> ");
		}
	}
	return 0;
}
