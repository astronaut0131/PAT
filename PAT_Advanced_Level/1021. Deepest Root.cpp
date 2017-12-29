#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
set <int> s;
map <int,vector <int> > edge;
vector <int> temp;
vector <bool> visit;
int max_height = -1;
void dfs(int node,int height){
	if(height >= max_height){
		if(height > max_height){
			temp.clear();
			max_height = height;
		}
		temp.push_back(node);
	}
	visit[node] = true;
	for(int i=0;i<edge[node].size();i++){
		if(not visit[edge[node][i]]){
			dfs(edge[node][i],height+1);
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);
	visit.resize(N+1);
	fill(visit.begin(),visit.end(),false);
	for(int i=0;i<N-1;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		edge[v1].push_back(v2);
		edge[v2].push_back(v1);
	}
	int s1 = 0;
	int cnt =0;
	for(int i=1;i<=N;i++){
		if(not visit[i]){
			dfs(i,1);
			if(i == 1){
				for(int j=0;j<temp.size();j++){
					s.insert(temp[j]);
					if(j == 0) s1 = temp[j];
				}
			}
			cnt++;
		}
	}
	if(cnt > 1){
		printf("Error: %d components",cnt);
	}
	else{
		max_height = -1;
		fill(visit.begin(),visit.end(),false);
		temp.clear();
		dfs(s1,1);
		for(int i=0;i<temp.size();i++){
			s.insert(temp[i]);
		}
		for(set<int>::iterator it = s.begin();it!=s.end();it++){
			printf("%d\n",*it);
		}
	}
	return 0;
}
