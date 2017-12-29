#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[105];
bool visit[105];
int cnt[105];
int maxx=0;
void dfs(int root,int level){
	cnt[level]++;
	if(level>maxx){
		maxx=level;
	}
	if(v[root].size()!=0){
		for(int i=0;i<v[root].size();i++){
			dfs(v[root][i],level+1);
		}
	}
}
int main(){
	fill(visit,visit+105,false);
	fill(cnt,cnt+105,0);
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int x,num;
		scanf("%d %d",&x,&num);
		for(int j=0;j<num;j++){
			int y;
			scanf("%d",&y);
			v[x].push_back(y);
		}
	}
	dfs(1,1);
	int maxxnum=1;
	int u=1;
	for(int i=1;i<=maxx;i++){
		if(cnt[i]>maxxnum){
			maxxnum=cnt[i];
			u=i;
		}
	}
	printf("%d %d",maxxnum,u);
	return 0;
}
