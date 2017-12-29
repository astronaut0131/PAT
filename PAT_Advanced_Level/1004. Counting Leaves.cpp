#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> v[105];
int leaf[105],level[105],maxlevel=-1;
void bfs(){
	queue <int> Q;
	Q.push(1);
	level[1]=0;
	while(!Q.empty()){
		int temp=Q.front();
		Q.pop();
		maxlevel=max(maxlevel,level[temp]);
		if(v[temp].size()==0){
			leaf[level[temp]]++;
		}
		for(int i=0;i<v[temp].size();i++){
			Q.push(v[temp][i]);
			level[v[temp][i]]=level[temp]+1;
		}
	}
}
/*
void dfs(int index,int depth){
	if(v[index].size()==0){
		book[depth]++;
		maxdepth = max(maxdepth,depth);
		return;
	}
    for(int i=0;i<v[index].size();i++)
        dfs(v[index][i],depth+1);
}
*/
int main(){
	fill(leaf,leaf+105,0);
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int node,num;
		scanf("%d %d",&node,&num);
		for(int j=0;j<num;j++){
			int x;
			scanf("%d",&x);
			v[node].push_back(x);
		}
	}
	bfs();
	for(int i=0;i<=maxlevel;i++){
		printf("%d",leaf[i]);
		if(i!=maxlevel){
			printf(" ");
		}
	}
	return 0;
}
