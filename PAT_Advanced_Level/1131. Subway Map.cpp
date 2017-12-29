#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
map <int,vector <int> > edge;
const int MAXN = 10000;
const int INF = 9999999;
int line[MAXN][MAXN];
int v1,v2;
bool visit[MAXN];
vector <int> temp;
vector <int> path;
int get_trans(vector <int> x){
	int last = -1;
	int cnt = 0;
	for(int i=1;i<x.size();i++){
		if(last != -1 and last != line[x[i-1]][x[i]]) cnt++;
		last = line[x[i-1]][x[i]];
	}
	return cnt;
}
void dfs(int x,int &min_dis,int &min_trans){
	int dis = temp.size();
	int trans = get_trans(temp);
	if(x == v2){
		if(dis < min_dis or (dis == min_dis and trans < min_trans)){
			min_dis = dis;
			min_trans = trans;
			path = temp;
		}
		else return;
	}
	else{
		for(int i=0;i<edge[x].size();i++){
			if(not visit[edge[x][i]]){
				visit[edge[x][i]] = true;
				temp.push_back(edge[x][i]);
				dfs(edge[x][i],min_dis,min_trans);
				temp.pop_back();
				visit[edge[x][i]] = false;
			}
		}	
	}
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int num;
		int last = -1;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			int x;
			scanf("%d",&x);
			if(last != -1){
				edge[last].push_back(x);
				edge[x].push_back(last);
				line[x][last] = line[last][x] = i;
			}
			last = x;
		}
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d %d",&v1,&v2);
		temp.clear();
		int min_dis = INF,min_transfer = INF;
		visit[v1] = true;
		temp.push_back(v1);
		dfs(v1,min_dis,min_transfer);
		visit[v1] = false;
		printf("%d\n",min_dis-1);
		int last_start = path[0];
		int last = -1;
		for(int i=1;i<path.size();i++){
			if(last != -1 and last != line[path[i-1]][path[i]]){
				printf("Take Line#%d from %04d to %04d.\n",last,last_start,path[i-1]);
				last_start = path[i-1];
			}
			last = line[path[i-1]][path[i]];
		}
		printf("Take Line#%d from %04d to %04d.\n",last,last_start,v2);
	}
	return 0;
}
