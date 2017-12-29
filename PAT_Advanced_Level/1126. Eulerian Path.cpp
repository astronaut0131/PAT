#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map <int,vector <int> > edge;
map <int,int> degree;
int cnt = 0;
bool visit[505];
void dfs(int x){
	cnt++;
	visit[x] = true;
	for(int i=0;i<edge[x].size();i++){
		if(not visit[edge[x][i]]){
			dfs(edge[x][i]);
		}
	}
}
int main(){
	fill(visit,visit+505,false);
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		degree[v1]++;
		degree[v2]++;
		edge[v1].push_back(v2);
		edge[v2].push_back(v1);
	}
	bool connected = false;
	dfs(1);
	if(cnt == N) connected = true;
	int even = 0,odd = 0;
	for(int i=1;i<=N;i++){
		printf("%d",degree[i]);
		if(i!=N) printf(" ");
		else printf("\n");
		if(degree[i]%2 == 0) even++;
		else odd++;
	}
	if(even == N and connected) printf("Eulerian");
	else if(odd == 2 and connected) printf("Semi-Eulerian");
	else printf("Non-Eulerian");
	return 0;
}
